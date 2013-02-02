#include "stdafx.h"
#include "Debuggee.h"
#include "DebuggerCallback.h"

using namespace System::Collections::Generic;

namespace MagoWrapper{

	Debuggee::Debuggee(void)
	{
		mModuleIdCounter = 0;

		mDebugger = NULL;
		mModules = new ModuleMap();
		mEventCallback = new DebuggerCallback(this);

	}

	Debuggee::~Debuggee()
	{
		delete mModules;
		delete mDebugger;
		delete mEventCallback;
	}

	void Debuggee::Terminate()
	{
		HRESULT hr = mDebugger->Terminate(mProcess);
	}

	void Debuggee::Resume()
	{
		mDebugger->ResumeProcess(mProcess);
	}

	void Debuggee::Suspend()
	{
		mDebugger->AsyncBreak(mProcess);
	}

	void Debuggee::Continue()
	{
		mDebugger->Continue(mProcess, true);
	}

	void Debuggee::StepIn()
	{
		mDebugger->StepInstruction(mProcess, true, true, true);
	}

	void Debuggee::StepOut()
	{

		List<CallStackFrame^>^ callStack = GetCallStack(StoppedThreadId);
		int count = callStack->Count;
		if (count < 2)
			return;

		Address address = callStack[1]->InstructionPointer;

		mDebugger->StepOut(mProcess, address, true);
	}

	void Debuggee::StepOver()
	{

		for ( ModuleMap::iterator it = mModules->begin();
			it != mModules->end();
			it++ )
		{
			RefPtr<Mago::Module> mod =  it->second;

			Address address = GetCurrentInstructionAddress();
			if (address == 0)
				return;

			if (!mod->Contains(address))
				continue;

			HRESULT hr = S_OK;
			RefPtr<MagoST::ISession>    session;
			AddressRange            addrRanges[1] = { 0 };
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

			addrRanges[0].Begin = (Address) addrBegin;
			addrRanges[0].End = (Address) (addrBegin + len - 1);

			hr = mDebugger->StepRange( mProcess, false, true, addrRanges, 1, true );

			break;
		}
	}

	void Debuggee::SetBreakPoint(ULONG64 address, ULONG64 cookie)
	{		
		mDebugger->SetBreakpoint(mProcess, address, cookie);
	}

	void Debuggee::RemoveBreakPoint(ULONG64 address, ULONG64 cookie)
	{
		mDebugger->RemoveBreakpoint(mProcess, address, cookie);
	}

	void Debuggee::OnInternalProcessStart(IProcess* process)
	{
		SetCoreProcess(process);
		
		OnProcessStart();
	}

	void Debuggee::OnInternalProcessExit(IProcess* process, DWORD exitCode)
	{
		OnProcessExit(exitCode);
	}

	void Debuggee::OnInternalThreadStart(IProcess* process, Thread* thread)
	{
		OnThreadStart(thread);
	}

	void Debuggee::OnInternalThreadExit(IProcess* process, DWORD threadId, DWORD exitCode)
	{
		OnThreadExit(threadId, exitCode);
	}

	void Debuggee::OnInternalModuleLoad(IProcess* process, IModule* module)
	{
		OnModuleLoad(module);
		
		RefPtr<Mago::Module> mod;

        HRESULT hr = S_OK;

		hr = MakeCComObject( mod );
        if ( FAILED( hr ) )
            return;

		mModuleIdCounter++;
		mod->SetId(mModuleIdCounter);
		mod->SetCoreModule(module);

		mModules->insert( ModuleMap::value_type( module->GetImageBase(),  mod ) );

        hr = mod->LoadSymbols( false );
 	}

	void Debuggee::OnInternalModuleUnload(IProcess* process, Address baseAddr)
	{		
		OnModuleUnload(baseAddr);
        ModuleMap::iterator it = mModules->find( baseAddr );

        if ( it != mModules->end() )
        {
            mModules->erase( it );
        }
	}

	void Debuggee::OnInternalOutputString(IProcess* process, const wchar_t* outputString)
	{
		OnOutputString(gcnew String(outputString));
	}

	void Debuggee::OnInternalLoadComplete(IProcess* process, DWORD threadId)
	{
		OnLoadComplete(threadId);
	}

	bool Debuggee::OnInternalException(IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec)
	{
		SetStoppedThreadId(threadId);

		ExceptionRecord^ rec = gcnew ExceptionRecord(exceptRec->ExceptionCode, exceptRec->ExceptionFlags, exceptRec->ExceptionAddress);
		
		return OnException(threadId, firstChance, rec);
	}

	bool Debuggee::OnInternalBreakpoint(IProcess* process, uint32_t threadId, Address address, Enumerator<BPCookie>* iter)
	{
		SetStoppedThreadId(threadId);

		return OnBreakpoint(threadId, address);
	}

	void Debuggee::OnInternalStepComplete(IProcess* process, uint32_t threadId)
	{
		SetStoppedThreadId(threadId);

		OnStepComplete(threadId);
	}

	void Debuggee::OnInternalAsyncBreakComplete(IProcess* process, uint32_t threadId)
	{
		SetStoppedThreadId(threadId);

		OnAsyncBreakComplete(threadId);
	}

	void Debuggee::OnInternalError(IProcess* process, HRESULT hrErr, uint32_t event)
	{
		OnError(hrErr, event);
	}

	bool Debuggee::InternalCanStepInFunction(IProcess* process, Address address)
	{
		return CanStepInFunction(address);
	}

	uint32_t Debuggee::GetProcessId()
	{
		return mProcess->GetId();
	}

	List<CallStackFrame^>^ Debuggee::GetCallStack(uint32_t threadId)
	{
		List<CallStackFrame^>^ frames = gcnew List<CallStackFrame^>();

		Enumerator<Thread*>*    threads = NULL;

		mProcess->EnumThreads( threads );

		while ( threads->MoveNext() )
		{
			Thread* t = threads->GetCurrent();
			std::list<FrameX86>  stack;

			if (t->GetId() == threadId) 
			{
				ReadCallstackX86(mProcess->GetHandle(), t->GetHandle(), stack );

				for ( std::list<FrameX86>::iterator it = stack.begin();
					it != stack.end();
					it++ )
				{
					CallStackFrame^ frame = gcnew CallStackFrame();
					frame->InstructionPointer = it->Eip;
					frame->BasePointer = it->Ebp;
					frames->Add(frame);
				}
			}
		}

		threads->Release();

		return frames;
	}

	List<DebuggeeThread^>^ Debuggee::GetThreads()
	{
		List<DebuggeeThread^>^ result = gcnew List<DebuggeeThread^>();

		Enumerator<Thread*>*    threads = NULL;

		mProcess->EnumThreads( threads );

		while ( threads->MoveNext() )
		{
			Thread* t = threads->GetCurrent();
			DebuggeeThread^ dthread = gcnew DebuggeeThread(t->GetId());
			result->Add(dthread);
		}

		threads->Release();

		return result;
	}

	void Debuggee::SetCoreProcess(IProcess* process)
	{
		mProcess = process;
	}

	void Debuggee::SetDebuggerProxy(DebuggerProxy* debuggerProxy)
	{
		mDebugger = debuggerProxy;
	}

	DebuggerProxy* Debuggee::GetDebuggerProxy()
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

	bool Debuggee::GetStoppedThread(Thread*& thread)
	{
		return mProcess->FindThread(mStoppedThreadId, thread);
	}

	ModuleMap* Debuggee::GetModuleMap()
	{
		return mModules;
	}
	
	IProcess* Debuggee::GetCoreProcess()
	{
		return mProcess;
	}


}