#pragma once

#include "Types.h"
#include "CallStackFrame.h"
#include "DebuggeeThread.h"
#include "IManagedIEventCallback.h"
#include "ExceptionRecord.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using Mago::DebuggerProxy;

namespace MagoWrapper
{
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

		void SetBreakPoint(ULONG64 address, ULONG64 cookie);
		void RemoveBreakPoint(ULONG64 address, ULONG64 cookie);

		delegate void OnProcessStartHandler();
		delegate void OnProcessExitHandler(DWORD exitCode);
		delegate void OnThreadStartHandler(Thread* thread);
		delegate void OnThreadExitHandler(DWORD threadId, DWORD exitCode);
		delegate void OnModuleLoadHandler(IModule* module);
		delegate void OnModuleUnloadHandler(Address baseAddr);
		delegate void OnOutputStringHandler(String^ outputString );
		delegate void OnLoadCompleteHandler(DWORD threadId);
		delegate bool OnExceptionHandler(DWORD threadId, bool firstChance, ExceptionRecord^ exceptRec);
		delegate bool OnBreakpointHandler(uint32_t threadId, Address address);
		delegate void OnStepCompleteHandler(uint32_t threadId);
		delegate void OnAsyncBreakCompleteHandler(uint32_t threadId);
		delegate void OnErrorHandler(HRESULT hrErr, DWORD eventCode);

		delegate bool CanStepInFunctionHandler(Address address );

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

		event CanStepInFunctionHandler^ CanStepInFunction;

	internal:
		IProcess* mProcess;
		IEventCallback* mEventCallback;

		void SetCoreProcess(IProcess* process);
		void SetDebuggerProxy(DebuggerProxy* debuggerProxy);
		DebuggerProxy* GetDebuggerProxy();
		void SetStoppedThreadId(DWORD stoppedThreadId);
		bool GetStoppedThread(Thread*& thread);
		ModuleMap* GetModuleMap();

		IProcess* GetCoreProcess();

		virtual void OnInternalProcessStart( IProcess* process ) = IManagedIEventCallback::OnInternalProcessStart;
		virtual void OnInternalProcessExit( IProcess* process, DWORD exitCode ) = IManagedIEventCallback::OnInternalProcessExit;
		virtual void OnInternalThreadStart( IProcess* process, Thread* thread ) = IManagedIEventCallback::OnInternalThreadStart;
		virtual void OnInternalThreadExit( IProcess* process, DWORD threadId, DWORD exitCode ) = IManagedIEventCallback::OnInternalThreadExit;
		virtual void OnInternalModuleLoad( IProcess* process, IModule* module ) = IManagedIEventCallback::OnInternalModuleLoad;
		virtual void OnInternalModuleUnload( IProcess* process, Address baseAddr ) = IManagedIEventCallback::OnInternalModuleUnload;
		virtual void OnInternalOutputString( IProcess* process, const wchar_t* outputString ) = IManagedIEventCallback::OnInternalOutputString;
		virtual void OnInternalLoadComplete( IProcess* process, DWORD threadId ) = IManagedIEventCallback::OnInternalLoadComplete;

		virtual bool OnInternalException( IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec ) = IManagedIEventCallback::OnInternalException;
		virtual bool OnInternalBreakpoint( IProcess* process, uint32_t threadId, Address address, Enumerator<BPCookie>* iter ) = IManagedIEventCallback::OnInternalBreakpoint;
		virtual void OnInternalStepComplete( IProcess* process, uint32_t threadId ) = IManagedIEventCallback::OnInternalStepComplete;
		virtual void OnInternalAsyncBreakComplete( IProcess* process, uint32_t threadId ) = IManagedIEventCallback::OnInternalAsyncBreakComplete;
		virtual void OnInternalError( IProcess* process, HRESULT hrErr, uint32_t event ) = IManagedIEventCallback::OnInternalError;

		virtual bool InternalCanStepInFunction( IProcess* process, Address address ) = IManagedIEventCallback::InternalCanStepInFunction;


	private:
		ULONG mPid;
		DWORD mStoppedThreadId;

		DebuggerProxy* mDebugger;
		ModuleMap* mModules;		
		DWORD mModuleIdCounter;

	};

}
