

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Sat Sep 19 12:59:36 2015
 */
/* Compiler settings for ..\Include\MagoRemoteCmd.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>

#include "MagoRemoteCmd_i.h"

#define TYPE_FORMAT_STRING_SIZE   205                               
#define PROC_FORMAT_STRING_SIZE   1169                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _MagoRemoteCmd_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MagoRemoteCmd_MIDL_TYPE_FORMAT_STRING;

typedef struct _MagoRemoteCmd_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MagoRemoteCmd_MIDL_PROC_FORMAT_STRING;

typedef struct _MagoRemoteCmd_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } MagoRemoteCmd_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MagoRemoteCmd_MIDL_TYPE_FORMAT_STRING MagoRemoteCmd__MIDL_TypeFormatString;
extern const MagoRemoteCmd_MIDL_PROC_FORMAT_STRING MagoRemoteCmd__MIDL_ProcFormatString;
extern const MagoRemoteCmd_MIDL_EXPR_FORMAT_STRING MagoRemoteCmd__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: MagoRemoteCmd, ver. 1.0,
   GUID={0x2497A4C6,0x7F4C,0x4383,{0x96,0x42,0x9B,0xCA,0xE2,0x83,0xD1,0xC3}} */



static const RPC_CLIENT_INTERFACE MagoRemoteCmd___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x2497A4C6,0x7F4C,0x4383,{0x96,0x42,0x9B,0xCA,0xE2,0x83,0xD1,0xC3}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE MagoRemoteCmd_v1_0_c_ifspec = (RPC_IF_HANDLE)& MagoRemoteCmd___RpcClientInterface;

extern const MIDL_STUB_DESC MagoRemoteCmd_StubDesc;

static RPC_BINDING_HANDLE MagoRemoteCmd__MIDL_AutoBindHandle;


HRESULT MagoRemoteCmd_Open( 
    /* [in] */ handle_t hBinding,
    /* [in] */ const GUID *sessionUuid,
    /* [in] */ boolean newSession,
    /* [out] */ HCTXCMD *phContext)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&hBinding);
    return ( HRESULT  )_RetVal.Simple;
    
}


void MagoRemoteCmd_Close( 
    /* [out][in] */ HCTXCMD *phContext)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[52],
                  ( unsigned char * )&phContext);
    
}


HRESULT MagoRemoteCmd_Launch( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ MagoRemote_LaunchInfo *launchInfo,
    /* [out] */ MagoRemote_ProcInfo *procInfo)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[88],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_Attach( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [out] */ MagoRemote_ProcInfo *procInfo)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[142],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_Terminate( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[196],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_Detach( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[244],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_ResumeProcess( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[292],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_ReadMemory( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ unsigned int length,
    /* [out] */ unsigned int *lengthRead,
    /* [out] */ unsigned int *lengthUnreadable,
    /* [out][size_is] */ byte *buffer)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[340],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_WriteMemory( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ unsigned int length,
    /* [out] */ unsigned int *lengthWritten,
    /* [in][size_is] */ byte *buffer)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[418],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_SetBreakpoint( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[490],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_RemoveBreakpoint( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[544],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_StepOut( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address targetAddr,
    /* [in] */ boolean handleException)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[598],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_StepInstruction( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean stepIn,
    /* [in] */ boolean handleException)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[658],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_StepRange( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean stepIn,
    /* [in] */ MagoRemote_AddressRange range,
    /* [in] */ boolean handleException)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[718],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_Continue( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean handleException)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[784],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_Execute( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ boolean handleException)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[838],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_AsyncBreak( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[892],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_GetThreadContext( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int tid,
    /* [in] */ unsigned int mainFeatureMask,
    /* [in] */ unsigned __int64 extFeatureMask,
    /* [in] */ unsigned int size,
    /* [out] */ unsigned int *sizeRead,
    /* [out][length_is][size_is] */ byte *regBuffer)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[940],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_SetThreadContext( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int tid,
    /* [in] */ unsigned int size,
    /* [in][size_is] */ byte *regBuffer)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[1024],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


HRESULT MagoRemoteCmd_GetPData( 
    /* [in] */ HCTXCMD hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ MagoRemote_Address imageBase,
    /* [in] */ unsigned int size,
    /* [out] */ unsigned int *sizeRead,
    /* [out][length_is][size_is] */ byte *pdataBuffer)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteCmd_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteCmd__MIDL_ProcFormatString.Format[1090],
                  ( unsigned char * )&hContext);
    return ( HRESULT  )_RetVal.Simple;
    
}


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MagoRemoteCmd_MIDL_PROC_FORMAT_STRING MagoRemoteCmd__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure MagoRemoteCmd_Open */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x49 ),	/* 73 */
/* 16 */	NdrFcShort( 0x40 ),	/* 64 */
/* 18 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 20 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 28 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 30 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 32 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter sessionUuid */

/* 34 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 36 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 38 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter newSession */

/* 40 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 42 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 44 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter phContext */

/* 46 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 48 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 50 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_Close */


	/* Return value */

/* 52 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 54 */	NdrFcLong( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x1 ),	/* 1 */
/* 60 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 62 */	0x30,		/* FC_BIND_CONTEXT */
			0xe8,		/* Ctxt flags:  via ptr, in, out, strict, */
/* 64 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 66 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 68 */	NdrFcShort( 0x38 ),	/* 56 */
/* 70 */	NdrFcShort( 0x38 ),	/* 56 */
/* 72 */	0x40,		/* Oi2 Flags:  has ext, */
			0x1,		/* 1 */
/* 74 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 82 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 84 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 86 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Procedure MagoRemoteCmd_Launch */

/* 88 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 90 */	NdrFcLong( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x2 ),	/* 2 */
/* 96 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 98 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 100 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 102 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 104 */	NdrFcShort( 0x24 ),	/* 36 */
/* 106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 108 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 110 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x1 ),	/* 1 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 118 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 120 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 122 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter launchInfo */

/* 124 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 126 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 128 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter procInfo */

/* 130 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 132 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 134 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_Attach */

/* 142 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 148 */	NdrFcShort( 0x3 ),	/* 3 */
/* 150 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 152 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 154 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 156 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 158 */	NdrFcShort( 0x2c ),	/* 44 */
/* 160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 162 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 164 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 172 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 174 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 176 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 178 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter procInfo */

/* 184 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_Terminate */

/* 196 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x4 ),	/* 4 */
/* 204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 206 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 208 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 210 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 212 */	NdrFcShort( 0x2c ),	/* 44 */
/* 214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 216 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 218 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 226 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 228 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 230 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_Detach */

/* 244 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x5 ),	/* 5 */
/* 252 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 254 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 256 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 258 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 260 */	NdrFcShort( 0x2c ),	/* 44 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 266 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 274 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 276 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 278 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 280 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 282 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 286 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_ResumeProcess */

/* 292 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 294 */	NdrFcLong( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x6 ),	/* 6 */
/* 300 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 302 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 304 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 306 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 308 */	NdrFcShort( 0x2c ),	/* 44 */
/* 310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 314 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 322 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 324 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 326 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 330 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 336 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_ReadMemory */

/* 340 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x7 ),	/* 7 */
/* 348 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 350 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 352 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 354 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 356 */	NdrFcShort( 0x44 ),	/* 68 */
/* 358 */	NdrFcShort( 0x40 ),	/* 64 */
/* 360 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x8,		/* 8 */
/* 362 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 364 */	NdrFcShort( 0x1 ),	/* 1 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 370 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 372 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 374 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 376 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 378 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter address */

/* 382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 384 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 386 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter length */

/* 388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 390 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lengthRead */

/* 394 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 396 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lengthUnreadable */

/* 400 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 402 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter buffer */

/* 406 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 408 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 410 */	NdrFcShort( 0x92 ),	/* Type Offset=146 */

	/* Return value */

/* 412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 414 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_WriteMemory */

/* 418 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 426 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 428 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 430 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 432 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 434 */	NdrFcShort( 0x44 ),	/* 68 */
/* 436 */	NdrFcShort( 0x24 ),	/* 36 */
/* 438 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 440 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x1 ),	/* 1 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 448 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 450 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 452 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 456 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter address */

/* 460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 462 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 464 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter length */

/* 466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 468 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lengthWritten */

/* 472 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 474 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter buffer */

/* 478 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 480 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 482 */	NdrFcShort( 0x92 ),	/* Type Offset=146 */

	/* Return value */

/* 484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 486 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_SetBreakpoint */

/* 490 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x9 ),	/* 9 */
/* 498 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 500 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 502 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 504 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 506 */	NdrFcShort( 0x3c ),	/* 60 */
/* 508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 510 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 512 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 520 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 522 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 524 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 528 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter address */

/* 532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 536 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 540 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_RemoveBreakpoint */

/* 544 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0xa ),	/* 10 */
/* 552 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 554 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 556 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 558 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 560 */	NdrFcShort( 0x3c ),	/* 60 */
/* 562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 564 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 566 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 574 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 576 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 578 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 582 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter address */

/* 586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 588 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 590 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 594 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_StepOut */

/* 598 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0xb ),	/* 11 */
/* 606 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 608 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 610 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 612 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 614 */	NdrFcShort( 0x41 ),	/* 65 */
/* 616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 618 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 620 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 628 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 630 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 632 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 634 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 636 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter targetAddr */

/* 640 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 642 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 644 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter handleException */

/* 646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 648 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 650 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 654 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_StepInstruction */

/* 658 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0xc ),	/* 12 */
/* 666 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 668 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 670 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 672 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 674 */	NdrFcShort( 0x36 ),	/* 54 */
/* 676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 678 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 680 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 688 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 690 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 692 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 694 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 696 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stepIn */

/* 700 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 702 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 704 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter handleException */

/* 706 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 708 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 710 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 714 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_StepRange */

/* 718 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 724 */	NdrFcShort( 0xd ),	/* 13 */
/* 726 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 728 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 730 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 732 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 734 */	NdrFcShort( 0x56 ),	/* 86 */
/* 736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 738 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 740 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 748 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 750 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 752 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stepIn */

/* 760 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 764 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter range */

/* 766 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 770 */	NdrFcShort( 0x9e ),	/* Type Offset=158 */

	/* Parameter handleException */

/* 772 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 774 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 776 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 780 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_Continue */

/* 784 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0xe ),	/* 14 */
/* 792 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 794 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 796 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 798 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 800 */	NdrFcShort( 0x31 ),	/* 49 */
/* 802 */	NdrFcShort( 0x8 ),	/* 8 */
/* 804 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 806 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 814 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 816 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 818 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 820 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 822 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter handleException */

/* 826 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 828 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 830 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 834 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_Execute */

/* 838 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0xf ),	/* 15 */
/* 846 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 848 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 850 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 852 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 854 */	NdrFcShort( 0x31 ),	/* 49 */
/* 856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 858 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 860 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 868 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 870 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 872 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 874 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter handleException */

/* 880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 882 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 884 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 888 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_AsyncBreak */

/* 892 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x10 ),	/* 16 */
/* 900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 902 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 904 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 906 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 908 */	NdrFcShort( 0x2c ),	/* 44 */
/* 910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 912 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 914 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 922 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 924 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 926 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 928 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 930 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_GetThreadContext */

/* 940 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x11 ),	/* 17 */
/* 948 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 950 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 952 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 954 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 956 */	NdrFcShort( 0x54 ),	/* 84 */
/* 958 */	NdrFcShort( 0x24 ),	/* 36 */
/* 960 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x9,		/* 9 */
/* 962 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 964 */	NdrFcShort( 0x1 ),	/* 1 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 970 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 972 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 974 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 976 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 978 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter tid */

/* 982 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 984 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mainFeatureMask */

/* 988 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 990 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter extFeatureMask */

/* 994 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 996 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 998 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 1000 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1002 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter sizeRead */

/* 1006 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1008 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter regBuffer */

/* 1012 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1014 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1016 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 1018 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1020 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_SetThreadContext */

/* 1024 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1032 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1034 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 1036 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1038 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1040 */	NdrFcShort( 0x3c ),	/* 60 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1046 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 1054 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1056 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1058 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 1060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter tid */

/* 1066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1068 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter size */

/* 1072 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter regBuffer */

/* 1078 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1080 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1082 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Return value */

/* 1084 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1086 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteCmd_GetPData */

/* 1090 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1092 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1098 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1100 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 1102 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1104 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1106 */	NdrFcShort( 0x54 ),	/* 84 */
/* 1108 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1110 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x8,		/* 8 */
/* 1112 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1114 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 1120 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1122 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1124 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 1126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter address */

/* 1132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1136 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter imageBase */

/* 1138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1140 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1142 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 1144 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1146 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter sizeRead */

/* 1150 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1152 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdataBuffer */

/* 1156 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1158 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1160 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 1162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1164 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MagoRemoteCmd_MIDL_TYPE_FORMAT_STRING MagoRemoteCmd__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x8 ),	/* Offset= 8 (12) */
/*  6 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 12 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x10 ),	/* 16 */
/* 16 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 18 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (6) */
			0x5b,		/* FC_END */
/* 24 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 26 */	NdrFcShort( 0x2 ),	/* Offset= 2 (28) */
/* 28 */	0x30,		/* FC_BIND_CONTEXT */
			0xa8,		/* Ctxt flags:  via ptr, out, strict, */
/* 30 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 32 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 34 */	NdrFcShort( 0x2 ),	/* Offset= 2 (36) */
/* 36 */	0x30,		/* FC_BIND_CONTEXT */
			0xe9,		/* Ctxt flags:  via ptr, in, out, strict, can't be null */
/* 38 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 40 */	0x30,		/* FC_BIND_CONTEXT */
			0x49,		/* Ctxt flags:  in, strict, can't be null */
/* 42 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 44 */	
			0x11, 0x0,	/* FC_RP */
/* 46 */	NdrFcShort( 0xe ),	/* Offset= 14 (60) */
/* 48 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 50 */	NdrFcShort( 0x2 ),	/* 2 */
/* 52 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x0,		/*  */
/* 54 */	NdrFcShort( 0xe ),	/* 14 */
/* 56 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 58 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 60 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 62 */	NdrFcShort( 0x14 ),	/* 20 */
/* 64 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 66 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 74 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 76 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 78 */	NdrFcShort( 0x4 ),	/* 4 */
/* 80 */	NdrFcShort( 0x4 ),	/* 4 */
/* 82 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 84 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 86 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	NdrFcShort( 0x8 ),	/* 8 */
/* 92 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 94 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 96 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 98 */	NdrFcShort( 0x10 ),	/* 16 */
/* 100 */	NdrFcShort( 0x10 ),	/* 16 */
/* 102 */	0x12, 0x0,	/* FC_UP */
/* 104 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (48) */
/* 106 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 108 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 110 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 112 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 114 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 116 */	NdrFcShort( 0x2 ),	/* Offset= 2 (118) */
/* 118 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 120 */	NdrFcShort( 0x18 ),	/* 24 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xa ),	/* Offset= 10 (134) */
/* 126 */	0x36,		/* FC_POINTER */
			0x40,		/* FC_STRUCTPAD4 */
/* 128 */	0xb,		/* FC_HYPER */
			0x8,		/* FC_LONG */
/* 130 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 132 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 134 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 136 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 138 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 140 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 142 */	
			0x11, 0x0,	/* FC_RP */
/* 144 */	NdrFcShort( 0x2 ),	/* Offset= 2 (146) */
/* 146 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0x1 ),	/* 1 */
/* 150 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 152 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 154 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 156 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 158 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 160 */	NdrFcShort( 0x10 ),	/* 16 */
/* 162 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 164 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 166 */	
			0x11, 0x0,	/* FC_RP */
/* 168 */	NdrFcShort( 0x2 ),	/* Offset= 2 (170) */
/* 170 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 172 */	NdrFcShort( 0x1 ),	/* 1 */
/* 174 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 176 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 178 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 180 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 182 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 184 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 186 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 188 */	
			0x11, 0x0,	/* FC_RP */
/* 190 */	NdrFcShort( 0x2 ),	/* Offset= 2 (192) */
/* 192 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 194 */	NdrFcShort( 0x1 ),	/* 1 */
/* 196 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 198 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 200 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 202 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const unsigned short MagoRemoteCmd_FormatStringOffsetTable[] =
    {
    0,
    52,
    88,
    142,
    196,
    244,
    292,
    340,
    418,
    490,
    544,
    598,
    658,
    718,
    784,
    838,
    892,
    940,
    1024,
    1090
    };


static const MIDL_STUB_DESC MagoRemoteCmd_StubDesc = 
    {
    (void *)& MagoRemoteCmd___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &MagoRemoteCmd__MIDL_AutoBindHandle,
    0,
    0,
    0,
    0,
    MagoRemoteCmd__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x8000253, /* MIDL Version 8.0.595 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

