#pragma once

namespace MagoWrapper{

	//managed ref class of the IEventCallback
	interface class IManagedIEventCallback
	{
	public:

		virtual void OnInternalProcessStart( IProcess* process ) = 0;
		virtual void OnInternalProcessExit( IProcess* process, DWORD exitCode ) = 0;
		virtual void OnInternalThreadStart( IProcess* process, Thread* thread ) = 0;
		virtual void OnInternalThreadExit( IProcess* process, DWORD threadId, DWORD exitCode ) = 0;
		virtual void OnInternalModuleLoad( IProcess* process, IModule* module ) = 0;
		virtual void OnInternalModuleUnload( IProcess* process, Address baseAddr ) = 0;
		virtual void OnInternalOutputString( IProcess* process, const wchar_t* outputString ) = 0;
		virtual void OnInternalLoadComplete( IProcess* process, DWORD threadId ) = 0;

		// Returns true to continue onto run mode, false to stay in break mode.
		virtual bool OnInternalException( IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec ) = 0;
		virtual bool OnInternalBreakpoint( IProcess* process, uint32_t threadId, Address address, Enumerator<BPCookie>* iter ) = 0;
		virtual void OnInternalStepComplete( IProcess* process, uint32_t threadId ) = 0;
		virtual void OnInternalAsyncBreakComplete( IProcess* process, uint32_t threadId ) = 0;
		virtual void OnInternalError( IProcess* process, HRESULT hrErr, uint32_t event ) = 0;

		// This function is convenient here, but might not be so good in cases 
		// where Exec and its user are on different machines.
		// In that case, we would need an asynchronous event like the rest above
		// and a function exposed by Exec to respond and complete the request.

		virtual bool InternalCanStepInFunction( IProcess* process, Address address ) = 0;


	};
}