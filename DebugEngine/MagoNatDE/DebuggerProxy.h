/*
   Copyright (c) 2010 Aldo J. Nunez

   Licensed under the Apache License, Version 2.0.
   See the LICENSE text file for details.
*/

#pragma once

#include "IDebuggerProxy.h"
#include "..\Exec\DebuggerProxy.h"

#include <string>

namespace Mago
{
    class ArchData;
    class IRegisterSet;
	class EventCallbackBase;
    class ICoreProcess;
    class ICoreThread;


    class DebuggerProxy : public IDebuggerProxy, public IEventCallback
    {
        MagoCore::DebuggerProxy mExecThread;
        RefPtr<ArchData>        mArch;
        RefPtr<EventCallbackBase>   mCallback;

    public:
        DebuggerProxy();
        ~DebuggerProxy();

		HRESULT Init(EventCallbackBase* callback);
        HRESULT Start();
        void    Shutdown();

        // IDebuggerProxy

        HRESULT Launch( LaunchInfo* launchInfo, ICoreProcess*& process );
        HRESULT Attach( uint32_t id, ICoreProcess*& process );

        HRESULT Terminate( ICoreProcess* process );
        HRESULT Detach( ICoreProcess* process );

        HRESULT ResumeLaunchedProcess( ICoreProcess* process );

        HRESULT ReadMemory( 
            ICoreProcess* process, 
            Address64 address,
            uint32_t length, 
            uint32_t& lengthRead, 
            uint32_t& lengthUnreadable, 
            uint8_t* buffer );

        HRESULT WriteMemory( 
            ICoreProcess* process, 
            Address64 address,
            uint32_t length, 
            uint32_t& lengthWritten, 
            uint8_t* buffer );

        HRESULT SetBreakpoint( ICoreProcess* process, Address64 address );
        HRESULT RemoveBreakpoint( ICoreProcess* process, Address64 address );

        HRESULT StepOut( ICoreProcess* process, Address64 targetAddr, bool handleException );
        HRESULT StepInstruction( ICoreProcess* process, bool stepIn, bool handleException );
        HRESULT StepRange( 
            ICoreProcess* process, 
            bool stepIn, 
            AddressRange64 range, 
            bool handleException );

        HRESULT Continue( ICoreProcess* process, bool handleException );
        HRESULT Execute( ICoreProcess* process, bool handleException );

        HRESULT AsyncBreak( ICoreProcess* process );

        HRESULT GetThreadContext( ICoreProcess* process, ICoreThread* thread, IRegisterSet*& regSet );
        HRESULT SetThreadContext( ICoreProcess* process, ICoreThread* thread, IRegisterSet* regSet );

        HRESULT GetPData( 
            ICoreProcess* process, 
            Address64 address, 
            Address64 imageBase, 
            uint32_t size, 
            uint32_t& sizeRead, 
            uint8_t* pdata );

        // IEventCallback

        virtual void AddRef();
        virtual void Release();

        virtual void OnProcessStart( IProcess* process );
        virtual void OnProcessExit( IProcess* process, DWORD exitCode );
        virtual void OnThreadStart( IProcess* process, ::Thread* thread );
        virtual void OnThreadExit( IProcess* process, DWORD threadId, DWORD exitCode );
        virtual void OnModuleLoad( IProcess* process, IModule* module );
        virtual void OnModuleUnload( IProcess* process, Address baseAddr );
        virtual void OnOutputString( IProcess* process, const wchar_t* outputString );
        virtual void OnLoadComplete( IProcess* process, DWORD threadId );

        virtual RunMode OnException( 
            IProcess* process, DWORD threadId, bool firstChance, const EXCEPTION_RECORD* exceptRec );

        virtual RunMode OnBreakpoint( 
            IProcess* process, uint32_t threadId, Address address, bool embedded );

        virtual void OnStepComplete( IProcess* process, uint32_t threadId );
        virtual void OnAsyncBreakComplete( IProcess* process, uint32_t threadId );
        virtual void OnError( IProcess* process, HRESULT hrErr, EventCode event );

        virtual ProbeRunMode OnCallProbe( 
            IProcess* process, uint32_t threadId, Address address, AddressRange& thunkRange );

        void SetSymbolSearchPath( const std::wstring& searchPath );
        const std::wstring& GetSymbolSearchPath() const;

    private:
        HRESULT CacheSystemInfo();
    };
}
