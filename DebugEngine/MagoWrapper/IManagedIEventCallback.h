#pragma once

#include "..\Exec\Types.h"
#include "..\Exec\IProcess.h"
//#include "..\Exec\IModule.h"
#include "..\Exec\EventCallback.h"

//#include "..\MagoNatDE\Program.h"
#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\ICoreProcess.h"

namespace MagoWrapper{

	//managed ref class of the IEventCallback
	interface class IManagedIEventCallback
	{
	public:
		virtual void OnInternalProcessStart(DWORD uniquePid);
		virtual void OnInternalProcessExit(DWORD uniquePid, DWORD exitCode);
		virtual void OnInternalThreadStart(DWORD uniquePid, Mago::ICoreThread* thread);
		virtual void OnInternalThreadExit(DWORD uniquePid, DWORD threadId, DWORD exitCode);
		virtual void OnInternalModuleLoad(DWORD uniquePid, Mago::ICoreModule* module);
		virtual void OnInternalModuleUnload(DWORD uniquePid, Mago::Address64 baseAddr);
		virtual void OnInternalOutputString(DWORD uniquePid, const wchar_t* outputString);
		virtual void OnInternalLoadComplete(DWORD uniquePid, DWORD threadId);

		// Returns true to continue onto run mode, false to stay in break mode.
		virtual RunMode OnInternalException(DWORD uniquePid, DWORD threadId, bool firstChance, const EXCEPTION_RECORD64*exceptRec);
		virtual RunMode OnInternalBreakpoint(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, bool embedded);
		virtual void OnInternalStepComplete(DWORD uniquePid, uint32_t threadId);
		virtual void OnInternalAsyncBreakComplete(DWORD uniquePid, uint32_t threadId);
		virtual void OnInternalError(DWORD uniquePid, HRESULT hrErr, IEventCallback::EventCode event);
		virtual ProbeRunMode OnInternalCallProbe(DWORD uniquePid, uint32_t threadId, Mago::Address64 address, Mago::AddressRange64& thunkRange);

	};
}