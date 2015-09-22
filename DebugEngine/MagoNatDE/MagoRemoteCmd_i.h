

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Sep 22 13:39:32 2015
 */
/* Compiler settings for ..\Include\MagoRemoteCmd.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
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


#ifndef __MagoRemoteCmd_i_h__
#define __MagoRemoteCmd_i_h__

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


#ifndef __MagoRemoteCmd_INTERFACE_DEFINED__
#define __MagoRemoteCmd_INTERFACE_DEFINED__

/* interface MagoRemoteCmd */
/* [explicit_handle][strict_context_handle][version][uuid] */ 

typedef 
enum MagoRemote_ProcCreate
    {
        MagoRemote_ProcCreate_Launch	= 0,
        MagoRemote_ProcCreate_Attach	= ( MagoRemote_ProcCreate_Launch + 1 ) 
    } 	MagoRemote_ProcCreate;

typedef struct MagoRemote_ProcInfo
    {
    /* [string] */ wchar_t *ExePath;
    unsigned __int64 MachineFeatures;
    unsigned int Pid;
    unsigned short MachineType;
    } 	MagoRemote_ProcInfo;

typedef 
enum MagoRemote_ProcFlags
    {
        MagoRemote_PFlags_None	= 0,
        MagoRemote_PFlags_NewConsole	= 1,
        MagoRemote_PFlags_Suspend	= 2
    } 	MagoRemote_ProcFlags;

typedef struct MagoRemote_LaunchInfo
    {
    /* [string] */ const wchar_t *Exe;
    /* [string] */ const wchar_t *CommandLine;
    /* [string] */ const wchar_t *Dir;
    unsigned short Flags;
    unsigned short EnvBstrSize;
    /* [size_is] */ const wchar_t *EnvBstr;
    } 	MagoRemote_LaunchInfo;

typedef /* [context_handle] */ void *HCTXCMD;

HRESULT MagoRemoteCmd_Open( 
    /* [in] */ handle_t hBinding,
    /* [in] */ const GUID *sessionUuid,
    /* [in] */ boolean newSession,
    /* [out] */ HCTXCMD *phContext);

void MagoRemoteCmd_Close( 
    /* [out][in] */ HCTXCMD *phContext);

HRESULT MagoRemoteCmd_Launch( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ MagoRemote_LaunchInfo *launchInfo,
    /* [out] */ MagoRemote_ProcInfo *procInfo);

HRESULT MagoRemoteCmd_Attach( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [out] */ MagoRemote_ProcInfo *procInfo);

HRESULT MagoRemoteCmd_Terminate( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid);

HRESULT MagoRemoteCmd_Detach( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid);

HRESULT MagoRemoteCmd_ResumeProcess( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid);

HRESULT MagoRemoteCmd_ReadMemory( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ unsigned int length,
    /* [out] */ unsigned int *lengthRead,
    /* [out] */ unsigned int *lengthUnreadable,
    /* [out][size_is] */ byte *buffer);

HRESULT MagoRemoteCmd_WriteMemory( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ unsigned int length,
    /* [out] */ unsigned int *lengthWritten,
    /* [in][size_is] */ byte *buffer);

HRESULT MagoRemoteCmd_SetBreakpoint( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address);

HRESULT MagoRemoteCmd_RemoveBreakpoint( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address);

HRESULT MagoRemoteCmd_StepOut( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address targetAddr,
    /* [in] */ boolean handleException);

HRESULT MagoRemoteCmd_StepInstruction( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean stepIn,
    /* [in] */ boolean handleException);

HRESULT MagoRemoteCmd_StepRange( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean stepIn,
    /* [in] */ MagoRemote_AddressRange range,
    /* [in] */ boolean handleException);

HRESULT MagoRemoteCmd_Continue( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean handleException);

HRESULT MagoRemoteCmd_Execute( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean handleException);

HRESULT MagoRemoteCmd_AsyncBreak( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid);

HRESULT MagoRemoteCmd_GetThreadContext( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int tid,
    /* [in] */ unsigned int mainFeatureMask,
    /* [in] */ unsigned __int64 extFeatureMask,
    /* [in] */ unsigned int size,
    /* [out] */ unsigned int *sizeRead,
    /* [out][length_is][size_is] */ byte *regBuffer);

HRESULT MagoRemoteCmd_SetThreadContext( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int tid,
    /* [in] */ unsigned int size,
    /* [in][size_is] */ byte *regBuffer);

HRESULT MagoRemoteCmd_GetPData( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ MagoRemote_Address imageBase,
    /* [in] */ unsigned int size,
    /* [out] */ unsigned int *sizeRead,
    /* [out][length_is][size_is] */ byte *pdataBuffer);



extern RPC_IF_HANDLE MagoRemoteCmd_v1_0_c_ifspec;
extern RPC_IF_HANDLE MagoRemoteCmd_v1_0_s_ifspec;
#endif /* __MagoRemoteCmd_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

void __RPC_USER HCTXCMD_rundown( HCTXCMD );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


