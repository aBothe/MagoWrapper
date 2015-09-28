#include "stdafx.h"
#include "DebuggerCallback.h"

//using namespace boost;

namespace MagoWrapper
{
	DebuggerCallback::DebuggerCallback(IManagedIEventCallback^ managedCallback)
	{
		mRefCount = 0;
		mManagedCallback = managedCallback;
		//SetCanStepInFunctionReturnValue(true);
	}

	DebuggerCallback::~DebuggerCallback(void)
	{
		
	}

	void DebuggerCallback::AddRef()
	{
		InterlockedIncrement(&mRefCount);
	}

	void DebuggerCallback::Release()
	{
		long    newRef = InterlockedDecrement(&mRefCount);
		_ASSERT(newRef >= 0);
		if (newRef == 0)
		{
			delete this;
		}
	}

	void DebuggerCallback::OnProcessStart(DWORD uniquePid)
	{
		mManagedCallback->OnInternalProcessStart(uniquePid);
	}

	void DebuggerCallback::OnProcessExit(DWORD uniquePid, DWORD exitCode)
	{
		mManagedCallback->OnInternalProcessExit(uniquePid, exitCode);
	}

	void DebuggerCallback::OnThreadStart(DWORD uniquePid, Mago::ICoreThread* thread)
	{
		mManagedCallback->OnInternalThreadStart(uniquePid, thread);
	}

	void DebuggerCallback::OnThreadExit(DWORD uniquePid, DWORD threadId, DWORD exitCode)
	{
		mManagedCallback->OnInternalThreadExit(uniquePid, threadId, exitCode);
	}

	void DebuggerCallback::OnModuleLoad(DWORD uniquePid, Mago::ICoreModule* module)
	{
		mManagedCallback->OnInternalModuleLoad(uniquePid, module);
	}

	void DebuggerCallback::OnModuleUnload(DWORD uniquePid, Mago::Address64 baseAddr)
	{
		mManagedCallback->OnInternalModuleUnload(uniquePid, baseAddr);
	}

	void DebuggerCallback::OnOutputString(DWORD uniquePid, const wchar_t* outputString)
	{
		mManagedCallback->OnInternalOutputString(uniquePid, outputString);
	}

	void DebuggerCallback::OnLoadComplete(DWORD uniquePid, DWORD threadId)
	{
		mManagedCallback->OnInternalLoadComplete(uniquePid, threadId);
	}

	RunMode DebuggerCallback::OnException(DWORD uniquePid, DWORD threadId, bool firstChance, const EXCEPTION_RECORD64*exceptRec)
	{
		return mManagedCallback->OnInternalException(uniquePid, threadId, firstChance, exceptRec);
	}

	RunMode DebuggerCallback::OnBreakpoint(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, bool embedded)
	{
		return mManagedCallback->OnInternalBreakpoint(uniquePid, threadId, address, embedded);
	}

	void DebuggerCallback::OnStepComplete(DWORD uniquePid, uint32_t threadId)
	{
		mManagedCallback->OnInternalStepComplete(uniquePid, threadId);
	}

	void DebuggerCallback::OnAsyncBreakComplete(DWORD uniquePid, uint32_t threadId)
	{
		mManagedCallback->OnInternalStepComplete(uniquePid, threadId);
	}

	void DebuggerCallback::OnError(DWORD uniquePid, HRESULT hrErr, IEventCallback::EventCode event)
	{
		mManagedCallback->OnInternalError(uniquePid, hrErr, event);
	}

	ProbeRunMode DebuggerCallback::OnCallProbe(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, Mago::AddressRange64& thunkRange)
	{
		return mManagedCallback->OnInternalCallProbe(uniquePid, threadId, address, thunkRange);
	}
	//bool DebuggerCallback::CanStepInFunction( IProcess* process, Address address )
	//{
	//	bool result = EventCallbackBase::CanStepInFunction(process, address);
	//	if (result)
	//		mManagedCallback->InternalCanStepInFunction(process, address);
	//	return result;
	//}

}