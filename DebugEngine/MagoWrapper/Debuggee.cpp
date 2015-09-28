#include "stdafx.h"
#include "Debuggee.h"
#include "DebuggerCallback.h"

#include "..\..\CVSym\CVSym\Error.h"

#include "..\..\CVSym\CVSTI\CVSTI.h"

//#include "..\UnitTests\utestExec\Utility.h"
#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\Thread.h"
#include "..\MagoNatDE\LocalProcess.h"
#include "..\MagoNatDE\ArchData.h"
#include "..\MagoNatDE\EnumFrameInfo.h"
#include "..\MagoNatDE\Program.h"
#include "..\MagoNatDE\CodeContext.h"

using namespace System::Collections::Generic;

namespace MagoWrapper{

	Debuggee::Debuggee(void)
	{
		mModuleIdCounter = 0;

		mDebugger = NULL;

		mEventCallback = new DebuggerCallback(this);
	}

	Debuggee::~Debuggee()
	{
		CComModule _Module;
		if (mDruntime)
			delete mDruntime;
		
		mProg->Dispose();
		mProg->Release();
		mDebugger->Release();
	}

	void Debuggee::Terminate()
	{
		HRESULT hr = mDebugger->Terminate(mProcess);
	}

	void Debuggee::Resume()
	{
		HRESULT hr = mDebugger->ResumeLaunchedProcess(mProcess);
	}

	void Debuggee::Suspend()
	{
		HRESULT hr = mDebugger->AsyncBreak(mProcess);
	}

	void Debuggee::Continue()
	{
		HRESULT hr = mDebugger->Continue(mProcess, true);
	}

	void Debuggee::StepIn()
	{
		HRESULT hr = mDebugger->StepInstruction(mProcess, true, true);
	}

	void Debuggee::StepOut()
	{
		RefPtr<Mago::Thread> thread;
		HRESULT hr = mProg->FindThread(StoppedThreadId, thread);
		if (FAILED(hr))
			return;

		hr = thread->Step(mProcess, STEP_OUT, 0, true);
	}

	void Debuggee::StepOver()
	{
		Mago::Address64 address = GetCurrentInstructionAddress();
		if (address == 0)
			return;
		RefPtr<Mago::Module> mod;
		HRESULT hr = mProg->FindModuleContainingAddress(address, mod);
		if (FAILED(hr))
			return;

		RefPtr<MagoST::ISession>    session;
		MagoST::LineNumber      line;

		if ( !mod->GetSymbolSession( session ) )
			return;

		uint16_t    sec = 0;
		uint32_t    offset = 0;
		sec = session->GetSecOffsetFromVA( address, offset );
		if ( sec == 0 )
			return;

		if ( !session->FindLine( sec, offset, line ) )
			return;

		UINT64  addrBegin = 0;
		DWORD   len = 0;

		addrBegin = session->GetVAFromSecOffset( sec, line.Offset );
		len = line.Length;

		Mago::AddressRange64            addrRange = { 0 };
		addrRange.Begin = (Address) addrBegin;
		addrRange.End = (Address) (addrBegin + len - 1);

		hr = mDebugger->StepRange(mProcess, false, addrRange, true);
	}

	void Debuggee::SetBreakPoint(ULONG64 address)
	{		
		HRESULT hr = mDebugger->SetBreakpoint(mProcess, address);
	}

	void Debuggee::RemoveBreakPoint(ULONG64 address)
	{
		HRESULT hr = mDebugger->RemoveBreakpoint(mProcess, address);
	}

	void Debuggee::OnInternalProcessStart(DWORD uniquePid)
	{
		OnProcessStart();
	}

	void Debuggee::OnInternalProcessExit(DWORD uniquePid, DWORD exitCode)
	{
		OnProcessExit(exitCode);
	}

	void Debuggee::OnInternalThreadStart(DWORD uniquePid, Mago::ICoreThread* thread)
	{
		CComModule _Module;
		//create mago thread
		RefPtr<Mago::Thread> magothread;
		HRESULT hr = S_OK;
		
		hr = mProg->CreateThread(thread, magothread);
		if (FAILED(hr))
			return;

		hr = mProg->AddThread(magothread.Get());
		if (FAILED(hr))
			return;

		//call managed event
		OnThreadStart(thread->GetTid());
	}

	void Debuggee::OnInternalThreadExit(DWORD uniquePid, DWORD threadId, DWORD exitCode)
	{
		OnThreadExit(threadId, exitCode);

		RefPtr<Mago::Thread> thread;
		HRESULT hr = mProg->FindThread(threadId, thread);
		if (FAILED(hr))
			return;

		mProg->DeleteThread(thread);
	}

	void Debuggee::OnInternalModuleLoad(DWORD uniquePid, Mago::ICoreModule* module)
	{
		OnModuleLoad(module);
		
		CComModule _Module;
		RefPtr<Mago::Module> mod;
        HRESULT hr = S_OK;

		mModuleIdCounter++;
		hr = mProg->CreateModuleInternal(module, mod, mModuleIdCounter);
		if (FAILED(hr))
			return;

		hr = mProg->AddModule(mod.Get());
		if (FAILED(hr))
			return;

		hr = mod->LoadSymbols(false);
 	}

	void Debuggee::OnInternalModuleUnload(DWORD uniquePid, Mago::Address64 baseAddr)
	{		
		OnModuleUnload(baseAddr);

		RefPtr<Mago::Module> mod;
		bool found = mProg->FindModule(baseAddr, mod);
		if (!found)
			return;

		mProg->DeleteModule(mod);
	}

	void Debuggee::OnInternalOutputString(DWORD uniquePid, const wchar_t* outputString)
	{
		OnOutputString(gcnew String(outputString));
	}

	void Debuggee::OnInternalLoadComplete(DWORD uniquePid, DWORD threadId)
	{
		OnLoadComplete(threadId);
	}

	RunMode Debuggee::OnInternalException(DWORD uniquePid, DWORD threadId, bool firstChance, const EXCEPTION_RECORD64* exceptRec)
	{
		SetStoppedThreadId(threadId);

		ExceptionRecord^ rec = gcnew ExceptionRecord();
		rec->Init(mDruntime, exceptRec);
		
		return (RunMode)OnException(threadId, firstChance, rec);
	}

	RunMode Debuggee::OnInternalBreakpoint(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, bool embedded)
	{
		SetStoppedThreadId(threadId);

		return (RunMode)OnBreakpoint(threadId, address);
	}

	void Debuggee::OnInternalStepComplete(DWORD uniquePid, uint32_t threadId)
	{
		SetStoppedThreadId(threadId);

		OnStepComplete(threadId);
	}

	void Debuggee::OnInternalAsyncBreakComplete(DWORD uniquePid, uint32_t threadId)
	{
		SetStoppedThreadId(threadId);

		OnAsyncBreakComplete(threadId);
	}

	void Debuggee::OnInternalError(DWORD uniquePid, HRESULT hrErr, IEventCallback::EventCode event)
	{
		OnError(hrErr, event);
	}

	ProbeRunMode Debuggee::OnInternalCallProbe(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, Mago::AddressRange64& thunkRange)
	{
		return OnInternalCallProbe(uniquePid, threadId, address, thunkRange);
	}

	uint32_t Debuggee::GetProcessId()
	{
		return mProcess->GetPid();
	}

	List<CallStackFrame^>^ Debuggee::GetCallStack(uint32_t threadId)
	{
		CComModule _Module;
		List<CallStackFrame^>^ frames = gcnew List<CallStackFrame^>();

		RefPtr<Mago::Thread> thread;
		HRESULT hr = mProg->FindThread(threadId, thread);
		if (FAILED(hr))
			return frames;

		FRAMEINFO_FLAGS flags =
			FIF_DEBUGINFO
			| FIF_FUNCNAME
			| FIF_RETURNTYPE
			| FIF_ARGS
			| FIF_LANGUAGE
			| FIF_MODULE
			| FIF_FUNCNAME_MODULE
			| FIF_FUNCNAME_ARGS_ALL
			| FIF_FUNCNAME_LINES
			| FIF_FUNCNAME_OFFSET
			| FIF_FUNCNAME_ARGS_TYPES
			| FIF_FUNCNAME_ARGS_NAMES
			| FIF_FUNCNAME_ARGS_VALUES
			| FIF_FRAME;


		DWORD tid = NULL;
		hr = thread->GetThreadId(&tid);
		if (FAILED(hr))
			return frames;

		CComPtr<IEnumDebugFrameInfo2> edfi = NULL;
		hr = thread->EnumFrameInfo(flags, 10, &edfi);
		if (FAILED(hr))
			return frames;

		ULONG cnt = 0;
		hr = edfi->GetCount(&cnt);
		if (FAILED(hr))
			return frames;
		
		ULONG fetched = 0;
		Mago::FrameInfoArray  array(cnt);
		while (fetched < cnt)
		{
			ULONG ft = 0;
			hr = edfi->Next(cnt - fetched, &array[fetched], &ft);
			if (FAILED(hr))
				return frames;
			fetched += ft;
		}

		for (ULONG i = 0; i < fetched; i++)
		{
			FRAMEINFO* fi = &array[i];
			CComPtr<IDebugCodeContext2> dcCtx = NULL;
			
			hr = fi->m_pFrame->GetCodeContext(&dcCtx);
			if (FAILED(hr))
				continue;

			CComQIPtr<Mago::IMagoMemoryContext> mmCtx = dcCtx; //how else to get address?
			Mago::Address64 addr = 0;
			hr = mmCtx->GetAddress(addr);

			CallStackFrame^ frame = gcnew CallStackFrame();
			frame->AddressMin = fi->m_addrMin;
			frame->AddressMax = fi->m_addrMax;
			frame->FunctionName = gcnew String(fi->m_bstrFuncName);
			frame->Args = gcnew String(fi->m_bstrArgs);
			frame->ReturnType = gcnew String(fi->m_bstrReturnType);
			frame->Language = gcnew String(fi->m_bstrLanguage);
			frame->InstructionPointer = addr;
			frames->Add(frame);
		}

		return frames;
	}

	List<DebuggeeThread^>^ Debuggee::GetThreads()
	{
		List<DebuggeeThread^>^ result = gcnew List<DebuggeeThread^>();

		CComPtr<IEnumDebugThreads2> edthread = NULL;
		HRESULT hr = mProg->EnumThreads(&edthread);
		if (FAILED(hr))
			return result;

		ULONG cnt = 0;
		hr = edthread->GetCount(&cnt);
		if (FAILED(hr))
			return result;

		ULONG fetched = 0;
		InterfaceArray<IDebugThread2> idbThreadArray(cnt);
		while (fetched < cnt) 
		{
			ULONG ft = 0;
			hr = edthread->Next(cnt - fetched, &(idbThreadArray[fetched]), &ft);
			if (FAILED(hr))
				return result;
			fetched += ft;
		}


		for (ULONG i = 0; i < fetched;  i++)
		{
			DWORD threadId = 0;
			hr = idbThreadArray[i]->GetThreadId(&threadId);
			if (FAILED(hr))
				continue;

			DebuggeeThread^ dthread = gcnew DebuggeeThread(threadId);
			result->Add(dthread);
		}

		return result;
	}

	void Debuggee::SetProgram(Mago::Program* prog)
	{
		mProg = prog;
		mProg->AddRef();
		mProcess = prog->GetCoreProcess();
		if (mDruntime)
			delete mDruntime;

		//need to get proper pointer size
		mDruntime = new Mago::DRuntime(mDebugger, mProcess);
	}

	Mago::Program* Debuggee::GetProgram()
	{
		return mProg;
	}

	Mago::ICoreProcess* Debuggee::GetProcess()
	{
		return mProcess;
	}

	void Debuggee::SetDebuggerProxy(Mago::DebuggerProxy* debuggerProxy)
	{
		mDebugger = debuggerProxy;
	}

	Mago::DebuggerProxy* Debuggee::GetDebuggerProxy()
	{
		return mDebugger;
	}

	void Debuggee::SetStoppedThreadId(DWORD stoppedThreadId)
	{
		mStoppedThreadId = stoppedThreadId;
	}

	DWORD Debuggee::StoppedThreadId::get()
	{
		return mStoppedThreadId;
	}

	ULONG64 Debuggee::GetCurrentInstructionAddress()
	{
        List<CallStackFrame^>^ stack = GetCallStack(mStoppedThreadId);
        if (stack->Count == 0)
            return 0;

		return stack[0]->InstructionPointer;
	}


	bool Debuggee::GetThread(DWORD threadId, RefPtr<Mago::Thread>& thread)
	{
		HRESULT hr = mProg->FindThread(threadId, thread);
		return !FAILED(hr);
	}
}