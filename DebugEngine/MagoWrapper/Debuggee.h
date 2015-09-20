#pragma once

#include "..\Exec\Types.h"
#include "..\Exec\IProcess.h"
#include "..\Exec\IModule.h"

#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\DebuggerProxy.h"
#include "..\MagoNatDE\ICoreProcess.h"
//#include "..\MagoNatDE\EventCallback.h"

#include "Types.h"
#include "CallStackFrame.h"
#include "DebuggeeThread.h"
#include "IManagedIEventCallback.h"
#include "ExceptionRecord.h"
//#include "DRuntime.h"

#include "DebuggerCallback.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

using MagoCore::DebuggerProxy;

namespace MagoWrapper
{

	public enum class DRunMode
	{
		DRunMode_Run,
		DRunMode_Break,
		DRunMode_Wait,
	};

	public ref class Debuggee : IManagedIEventCallback
	{
	public:
		Debuggee(void);
		~Debuggee();

		property DWORD StoppedThreadId
		{
			DWORD get();
		}

		uint32_t GetProcessId();
		List<CallStackFrame^>^ GetCallStack(uint32_t threadId);
		List<DebuggeeThread^>^ GetThreads();
		ULONG64 GetCurrentInstructionAddress();

		void Terminate();
		void Resume();
		void Suspend();
		void Continue();
		void StepIn();
		void StepOut();
		void StepOver();

		void SetBreakPoint(ULONG64 address);
		void RemoveBreakPoint(ULONG64 address);

		delegate void OnProcessStartHandler();
		delegate void OnProcessExitHandler(DWORD exitCode);
		delegate void OnThreadStartHandler(DWORD threadId);
		delegate void OnThreadExitHandler(DWORD threadId, DWORD exitCode);
		delegate void OnModuleLoadHandler(Mago::ICoreModule* module);
		delegate void OnModuleUnloadHandler(Address baseAddr);
		delegate void OnOutputStringHandler(String^ outputString);
		delegate void OnLoadCompleteHandler(DWORD threadId);
		delegate DRunMode OnExceptionHandler(DWORD threadId, bool firstChance, ExceptionRecord^ exceptRec);
		delegate DRunMode OnBreakpointHandler(uint32_t threadId, Address address);
		delegate void OnStepCompleteHandler(uint32_t threadId);
		delegate void OnAsyncBreakCompleteHandler(uint32_t threadId);
		delegate void OnErrorHandler(HRESULT hrErr, DWORD eventCode);
		delegate ProbeRunMode OnCallProbeHandler(DWORD uniquePid, uint32_t threadId, Address address, AddressRange thunkRange);

		event OnProcessStartHandler^ OnProcessStart;
		event OnProcessExitHandler^ OnProcessExit;
		event OnThreadStartHandler^ OnThreadStart;
		event OnThreadExitHandler^ OnThreadExit;
		event OnModuleLoadHandler^ OnModuleLoad;
		event OnModuleUnloadHandler^ OnModuleUnload;
		event OnOutputStringHandler^ OnOutputString;
		event OnLoadCompleteHandler^ OnLoadComplete;
		event OnExceptionHandler^ OnException;
		event OnBreakpointHandler^ OnBreakpoint;
		event OnStepCompleteHandler^ OnStepComplete;
		event OnAsyncBreakCompleteHandler^ OnAsyncBreakComplete;
		event OnErrorHandler^ OnError;
		event OnCallProbeHandler^ OnCallProbe;

	internal:
		//CComModule* mComModule;
		//IProcess* mProcess;
		Mago::ICoreProcess* mProcess;
		Mago::Program* mProg;
		Mago::DRuntime* mDruntime;
		//EventCallbackBase* mEventCallback;
		DebuggerCallback* mEventCallback;

		//void SetProcess(IProcess* process);
		void SetProcess(Mago::ICoreProcess* process);
		//IProcess* GetProcess();
		Mago::ICoreProcess* GetProcess();
		void SetProgram(Mago::Program* prog);
		Mago::Program* GetProgram();
		void SetDebuggerProxy(Mago::DebuggerProxy* debuggerProxy);
		Mago::DebuggerProxy* GetDebuggerProxy();

		void SetStoppedThreadId(DWORD stoppedThreadId);
		//bool GetStoppedThread(Thread*& thread);
		//ModuleMap* GetModuleMap();

		bool GetThread(DWORD threadId, RefPtr<Mago::Thread>& thread);

		//virtual void OnInternalProcessStart(IProcess* process) = IManagedIEventCallback::OnInternalProcessStart;
		//virtual void OnInternalProcessExit(IProcess* process, DWORD exitCode) = IManagedIEventCallback::OnInternalProcessExit;
		//virtual void OnInternalThreadStart(IProcess* process, Thread* thread) = IManagedIEventCallback::OnInternalThreadStart;
		//virtual void OnInternalThreadExit(IProcess* process, DWORD threadId, DWORD exitCode) = IManagedIEventCallback::OnInternalThreadExit;
		//virtual void OnInternalModuleLoad(IProcess* process, IModule* module) = IManagedIEventCallback::OnInternalModuleLoad;
		//virtual void OnInternalModuleUnload(IProcess* process, Address baseAddr) = IManagedIEventCallback::OnInternalModuleUnload;
		//virtual void OnInternalOutputString(IProcess* process, const wchar_t* outputString) = IManagedIEventCallback::OnInternalOutputString;
		//virtual void OnInternalLoadComplete(IProcess* process, DWORD threadId) = IManagedIEventCallback::OnInternalLoadComplete;

		//virtual RunMode OnInternalException(IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec) = IManagedIEventCallback::OnInternalException;
		//virtual bool OnInternalBreakpoint(IProcess* process, uint32_t threadId, Address address, Enumerator<Mago::BPCookie>* iter) = IManagedIEventCallback::OnInternalBreakpoint;
		//virtual void OnInternalStepComplete(IProcess* process, uint32_t threadId) = IManagedIEventCallback::OnInternalStepComplete;
		//virtual void OnInternalAsyncBreakComplete(IProcess* process, uint32_t threadId) = IManagedIEventCallback::OnInternalAsyncBreakComplete;
		//virtual void OnInternalError(IProcess* process, HRESULT hrErr, uint32_t event) = IManagedIEventCallback::OnInternalError;

		//virtual ProbeRunMode OnInternalCallProbe(IProcess* process, uint32_t threadId, Address address, AddressRange& thunkRange) = IManagedIEventCallback::OnInternalCallProbe;

		virtual void OnInternalProcessStart(DWORD uniquePid) = IManagedIEventCallback::OnInternalProcessStart;
		virtual void OnInternalProcessExit(DWORD uniquePid, DWORD exitCode) = IManagedIEventCallback::OnInternalProcessExit;
		virtual void OnInternalThreadStart(DWORD uniquePid, Mago::ICoreThread* thread) = IManagedIEventCallback::OnInternalThreadStart;
		virtual void OnInternalThreadExit(DWORD uniquePid, DWORD threadId, DWORD exitCode) = IManagedIEventCallback::OnInternalThreadExit;
		virtual void OnInternalModuleLoad(DWORD uniquePid, Mago::ICoreModule* module) = IManagedIEventCallback::OnInternalModuleLoad;
		virtual void OnInternalModuleUnload(DWORD uniquePid, Mago::Address64 baseAddr) = IManagedIEventCallback::OnInternalModuleUnload;
		virtual void OnInternalOutputString(DWORD uniquePid, const wchar_t* outputString) = IManagedIEventCallback::OnInternalOutputString;
		virtual void OnInternalLoadComplete(DWORD uniquePid, DWORD threadId) = IManagedIEventCallback::OnInternalLoadComplete;

		// Returns true to continue onto run mode, false to stay in break mode.
		virtual RunMode OnInternalException(DWORD uniquePid, DWORD threadId, bool firstChance, const EXCEPTION_RECORD64* exceptRec) = IManagedIEventCallback::OnInternalException;
		virtual RunMode OnInternalBreakpoint(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, bool embedded) = IManagedIEventCallback::OnInternalBreakpoint;
		virtual void OnInternalStepComplete(DWORD uniquePid, uint32_t threadId) = IManagedIEventCallback::OnInternalStepComplete;
		virtual void OnInternalAsyncBreakComplete(DWORD uniquePid, uint32_t threadId) = IManagedIEventCallback::OnInternalAsyncBreakComplete;
		virtual void OnInternalError(DWORD uniquePid, HRESULT hrErr, IEventCallback::EventCode event) = IManagedIEventCallback::OnInternalError;

		virtual ProbeRunMode OnInternalCallProbe(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, Mago::AddressRange64& thunkRange) = IManagedIEventCallback::OnInternalCallProbe;
	private:
		ULONG mPid;
		DWORD mStoppedThreadId;

		Mago::DebuggerProxy* mDebugger;
		//ModuleMap* mModules;		
		DWORD mModuleIdCounter;
		//ThreadMap* mThreads;
		Guard* mThreadGuard;



	};

}
