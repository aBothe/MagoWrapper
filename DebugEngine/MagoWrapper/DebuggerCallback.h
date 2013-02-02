#pragma once

#include "IManagedIEventCallback.h"

//using Mago;

namespace MagoWrapper
{

	class DebuggerCallback : public EventCallbackBase
	{
	public:
		DebuggerCallback(IManagedIEventCallback^ managedCallback);
		~DebuggerCallback(void);

		virtual void OnProcessStart( IProcess* process );
		virtual void OnProcessExit( IProcess* process, DWORD exitCode );
		virtual void OnThreadStart( IProcess* process, Thread* thread );
		virtual void OnThreadExit( IProcess* process, DWORD threadId, DWORD exitCode );
		virtual void OnModuleLoad( IProcess* process, IModule* module );
		virtual void OnModuleUnload( IProcess* process, Address baseAddr );
		virtual void OnOutputString( IProcess* process, const wchar_t* outputString );
		virtual void OnLoadComplete( IProcess* process, DWORD threadId );
		virtual bool OnException( IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec );
		virtual bool OnBreakpoint( IProcess* process, uint32_t threadId, Address address, Enumerator< BPCookie >* iter );
		virtual void OnStepComplete( IProcess* process, uint32_t threadId );
		virtual void OnAsyncBreakComplete( IProcess* process, uint32_t threadId );
		virtual void OnError( IProcess* process, HRESULT hrErr, EventCode event );

		virtual bool CanStepInFunction( IProcess* process, Address address );
	private:
		gcroot<IManagedIEventCallback^> mManagedCallback;
	};

}