

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Sat Sep 19 12:59:35 2015
 */
/* Compiler settings for ..\Include\MagoRemoteEvent.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __MagoRemoteEvent_h_h__
#define __MagoRemoteEvent_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "MagoRemoteCommon.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __MagoRemoteEvent_INTERFACE_DEFINED__
#define __MagoRemoteEvent_INTERFACE_DEFINED__

/* interface MagoRemoteEvent */
/* [explicit_handle][strict_context_handle][version][uuid] */ 

typedef 
enum MagoRemote_RunMode
    {
        MagoRemote_RunMode_Run	= 0,
        MagoRemote_RunMode_Break	= ( MagoRemote_RunMode_Run + 1 ) ,
        MagoRemote_RunMode_Wait	= ( MagoRemote_RunMode_Break + 1 ) 
    } 	MagoRemote_RunMode;

typedef 
enum MagoRemote_ProbeRunMode
    {
        MagoRemote_PRunMode_Run	= 0,
        MagoRemote_PRunMode_Break	= ( MagoRemote_PRunMode_Run + 1 ) ,
        MagoRemote_PRunMode_Wait	= ( MagoRemote_PRunMode_Break + 1 ) ,
        MagoRemote_PRunMode_WalkThunk	= ( MagoRemote_PRunMode_Wait + 1 ) 
    } 	MagoRemote_ProbeRunMode;

typedef struct MagoRemote_ThreadInfo
    {
    MagoRemote_Address StartAddr;
    MagoRemote_Address TebBase;
    unsigned int Tid;
    } 	MagoRemote_ThreadInfo;

typedef struct MagoRemote_ModuleInfo
    {
    /* [string] */ const wchar_t *Path;
    MagoRemote_Address ImageBase;
    MagoRemote_Address PreferredImageBase;
    unsigned int DebugInfoFileOffset;
    unsigned int DebugInfoSize;
    unsigned int Size;
    unsigned short MachineType;
    } 	MagoRemote_ModuleInfo;

#define	MagoRemote_ExceptionMaxParams	( 15 )

typedef struct MagoRemote_ExceptionRecord
    {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    DWORD64 ExceptionAddress;
    DWORD NumberParameters;
    DWORD64 ExceptionInformation[ 15 ];
    } 	MagoRemote_ExceptionRecord;

typedef /* [context_handle] */ void *HCTXEVENT;

HRESULT MagoRemoteEvent_Open( 
    /* [in] */ handle_t hBinding,
    /* [in] */ const GUID *sessionUuid,
    /* [out] */ HCTXEVENT *phContext);

void MagoRemoteEvent_Close( 
    /* [out][in] */ HCTXEVENT *phContext);

void MagoRemoteEvent_OnProcessStart( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid);

void MagoRemoteEvent_OnProcessExit( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD exitCode);

void MagoRemoteEvent_OnThreadStart( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_ThreadInfo *threadInfo);

void MagoRemoteEvent_OnThreadExit( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD threadId,
    /* [in] */ DWORD exitCode);

void MagoRemoteEvent_OnModuleLoad( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_ModuleInfo *modInfo);

void MagoRemoteEvent_OnModuleUnload( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address baseAddress);

void MagoRemoteEvent_OnOutputString( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [string][in] */ const wchar_t *outputString);

void MagoRemoteEvent_OnLoadComplete( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD threadId);

MagoRemote_RunMode MagoRemoteEvent_OnException( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD threadId,
    /* [in] */ boolean firstChance,
    /* [in] */ unsigned int recordCount,
    /* [in][size_is] */ MagoRemote_ExceptionRecord *exceptRecords);

MagoRemote_RunMode MagoRemoteEvent_OnBreakpoint( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ boolean embedded);

void MagoRemoteEvent_OnStepComplete( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId);

void MagoRemoteEvent_OnAsyncBreak( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId);

MagoRemote_ProbeRunMode MagoRemoteEvent_OnCallProbe( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId,
    /* [in] */ MagoRemote_Address address,
    /* [out] */ MagoRemote_AddressRange *thunkRange);



extern RPC_IF_HANDLE MagoRemoteEvent_v1_0_c_ifspec;
extern RPC_IF_HANDLE MagoRemoteEvent_v1_0_s_ifspec;
#endif /* __MagoRemoteEvent_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

void __RPC_USER HCTXEVENT_rundown( HCTXEVENT );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


