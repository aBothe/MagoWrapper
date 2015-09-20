#pragma once

#include "IManagedIEventCallback.h"

//#include "..\Exec\IProcess.h"
#include "..\Exec\Types.h"

#include "..\MagoNatDE\EventCallbackBase.h"

namespace MagoWrapper
{

	class DebuggerCallback : public Mago::EventCallbackBase
	{
		long mRefCount;
	public:
		DebuggerCallback(IManagedIEventCallback^ managedCallback);
		~DebuggerCallback(void);

		//virtual void OnProcessStart(IProcess* process);
		//virtual void OnProcessExit(IProcess* process, DWORD exitCode);
		//virtual void OnThreadStart(IProcess* process, Thread* thread);
		//virtual void OnThreadExit(IProcess* process, DWORD threadId, DWORD exitCode);
		//virtual void OnModuleLoad(IProcess* process, IModule* module);
		//virtual void OnModuleUnload(IProcess* process, Address baseAddr);
		//virtual void OnOutputString(IProcess* process, const wchar_t* outputString);
		//virtual void OnLoadComplete(IProcess* process, DWORD threadId);
		//virtual RunMode OnException(IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec);
		//virtual bool OnBreakpoint(IProcess* process, uint32_t threadId, Address address, Enumerator<Mago::BPCookie>* iter);
		//virtual void OnStepComplete(IProcess* process, uint32_t threadId);
		//virtual void OnAsyncBreakComplete(IProcess* process, uint32_t threadId);
		//virtual void OnError(IProcess* process, HRESULT hrErr, IEventCallback::EventCode event);

		//virtual bool CanStepInFunction(IProcess* process, Address address);



		virtual void AddRef();
		virtual void Release();

		virtual void OnProcessStart(DWORD uniquePid);
		virtual void OnProcessExit(DWORD uniquePid, DWORD exitCode);
		virtual void OnThreadStart(DWORD uniquePid, Mago::ICoreThread* thread);
		virtual void OnThreadExit(DWORD uniquePid, DWORD threadId, DWORD exitCode);
		virtual void OnModuleLoad(DWORD uniquePid, Mago::ICoreModule* module);
		virtual void OnModuleUnload(DWORD uniquePid, Mago::Address64 baseAddr);
		virtual void OnOutputString(DWORD uniquePid, const wchar_t* outputString);
		virtual void OnLoadComplete(DWORD uniquePid, DWORD threadId);

		virtual RunMode OnException(DWORD uniquePid, DWORD threadId, bool firstChance, const EXCEPTION_RECORD64*exceptRec);
		virtual RunMode OnBreakpoint(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, bool embedded);
		virtual void OnStepComplete(DWORD uniquePid, uint32_t threadId);
		virtual void OnAsyncBreakComplete(DWORD uniquePid, uint32_t threadId);
		virtual void OnError(DWORD uniquePid, HRESULT hrErr, IEventCallback::EventCode event);
		virtual ProbeRunMode OnCallProbe(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, Mago::AddressRange64& thunkRange);

	private:
		gcroot<IManagedIEventCallback^> mManagedCallback;
	};

}