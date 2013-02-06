#include "stdafx.h"
#include "DebuggerCallback.h"

using namespace boost;

namespace MagoWrapper
{
	DebuggerCallback::DebuggerCallback(IManagedIEventCallback^ managedCallback) : EventCallbackBase()
	{
		mManagedCallback = managedCallback;
		SetCanStepInFunctionReturnValue(true);
	}

	DebuggerCallback::~DebuggerCallback(void)
	{
		
	}

	void DebuggerCallback::OnProcessStart(IProcess* process)
	{
		EventCallbackBase::OnProcessStart(process);
		mManagedCallback->OnInternalProcessStart(process);
	}

	void DebuggerCallback::OnProcessExit( IProcess* process, DWORD exitCode )
	{
		EventCallbackBase::OnProcessExit(process, exitCode);
		mManagedCallback->OnInternalProcessExit(process, exitCode);
	}

	void DebuggerCallback::OnThreadStart( IProcess* process, Thread* thread )
	{
		EventCallbackBase::OnThreadStart(process, thread);
		mManagedCallback->OnInternalThreadStart(process, thread);
	}

	void DebuggerCallback::OnThreadExit( IProcess* process, DWORD threadId, DWORD exitCode )
	{
		EventCallbackBase::OnThreadExit(process, threadId, exitCode);
		mManagedCallback->OnInternalThreadExit(process, threadId, exitCode);
	}

	void DebuggerCallback::OnModuleLoad( IProcess* process, IModule* module )
	{
		EventCallbackBase::OnModuleLoad(process, module);
		mManagedCallback->OnInternalModuleLoad(process, module);
	}

	void DebuggerCallback::OnModuleUnload( IProcess* process, Address baseAddr )
	{
		EventCallbackBase::OnModuleUnload(process, baseAddr);
		mManagedCallback->OnInternalModuleUnload(process, baseAddr);
	}

	void DebuggerCallback::OnOutputString( IProcess* process, const wchar_t* outputString )
	{
		EventCallbackBase::OnOutputString(process, outputString);
		mManagedCallback->OnInternalOutputString(process, outputString);
	}

	void DebuggerCallback::OnLoadComplete( IProcess* process, DWORD threadId )
	{
		EventCallbackBase::OnLoadComplete(process, threadId);
		mManagedCallback->OnInternalLoadComplete(process, threadId);
	}

	bool DebuggerCallback::OnException( IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec )
	{
		bool result = EventCallbackBase::OnException(process, threadId, firstChance, exceptRec);
		result = mManagedCallback->OnInternalException(process, threadId, firstChance, exceptRec);
		return result;
	}

	bool DebuggerCallback::OnBreakpoint( IProcess* process, uint32_t threadId, Address address, Enumerator<BPCookie>* iter )
	{
		bool reault = EventCallbackBase::OnBreakpoint(process, threadId, address, iter);
		mManagedCallback->OnInternalBreakpoint(process, threadId, address, iter);
		return false;
	}

	void DebuggerCallback::OnStepComplete( IProcess* process, uint32_t threadId )
	{
		EventCallbackBase::OnStepComplete(process, threadId);
		mManagedCallback->OnInternalStepComplete(process, threadId);
	}

	void DebuggerCallback::OnAsyncBreakComplete( IProcess* process, uint32_t threadId )
	{
		EventCallbackBase::OnAsyncBreakComplete(process, threadId);
		mManagedCallback->OnInternalStepComplete(process, threadId);
	}

	void DebuggerCallback::OnError( IProcess* process, HRESULT hrErr, EventCode event )
	{
		EventCallbackBase::OnError(process, hrErr, event);
		mManagedCallback->OnInternalError(process, hrErr, event);
	}

	bool DebuggerCallback::CanStepInFunction( IProcess* process, Address address )
	{
		bool result = EventCallbackBase::CanStepInFunction(process, address);
		if (result)
			mManagedCallback->InternalCanStepInFunction(process, address);
		return result;
	}

}