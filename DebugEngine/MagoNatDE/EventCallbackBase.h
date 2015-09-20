/*
   Copyright (c) 2010 Aldo J. Nunez

   Licensed under the Apache License, Version 2.0.
   See the LICENSE text file for details.
*/

#pragma once


namespace Mago
{
    class Engine;
    class Program;
    class Thread;
    class EventBase;
    class ICoreThread;
    class ICoreModule;


	class EventCallbackBase
    {
    public:
		virtual void AddRef() = 0;
		virtual void Release() = 0;

        virtual void OnProcessStart( DWORD uniquePid ) = 0;
        virtual void OnProcessExit( DWORD uniquePid, DWORD exitCode ) = 0;
        virtual void OnThreadStart( DWORD uniquePid, ICoreThread* thread ) = 0;
        virtual void OnThreadExit( DWORD uniquePid, DWORD threadId, DWORD exitCode ) = 0;
        virtual void OnModuleLoad( DWORD uniquePid, ICoreModule* module ) = 0;
        virtual void OnModuleUnload( DWORD uniquePid, Address64 baseAddr ) = 0;
        virtual void OnOutputString( DWORD uniquePid, const wchar_t* outputString ) = 0;
        virtual void OnLoadComplete( DWORD uniquePid, DWORD threadId ) = 0;

        virtual RunMode OnException( 
			DWORD uniquePid, DWORD threadId, bool firstChance, const EXCEPTION_RECORD64*exceptRec) = 0;
        virtual RunMode OnBreakpoint( 
            DWORD uniquePid, uint32_t threadId, Address64 address, bool embedded ) = 0;
        virtual void OnStepComplete( DWORD uniquePid, uint32_t threadId ) = 0;
        virtual void OnAsyncBreakComplete( DWORD uniquePid, uint32_t threadId ) = 0;
        virtual void OnError( DWORD uniquePid, HRESULT hrErr, IEventCallback::EventCode event ) = 0;
        virtual ProbeRunMode OnCallProbe( 
            DWORD uniquePid, uint32_t threadId, Address64 address, AddressRange64& thunkRange ) = 0;
    };
}
