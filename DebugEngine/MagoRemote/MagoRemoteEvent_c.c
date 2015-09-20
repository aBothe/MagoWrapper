

/* this ALWAYS GENERATED file contains the RPC client stubs */


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

#include "MagoRemoteEvent_h.h"

#define TYPE_FORMAT_STRING_SIZE   145                               
#define PROC_FORMAT_STRING_SIZE   767                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _MagoRemoteEvent_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MagoRemoteEvent_MIDL_TYPE_FORMAT_STRING;

typedef struct _MagoRemoteEvent_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MagoRemoteEvent_MIDL_PROC_FORMAT_STRING;

typedef struct _MagoRemoteEvent_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } MagoRemoteEvent_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MagoRemoteEvent_MIDL_TYPE_FORMAT_STRING MagoRemoteEvent__MIDL_TypeFormatString;
extern const MagoRemoteEvent_MIDL_PROC_FORMAT_STRING MagoRemoteEvent__MIDL_ProcFormatString;
extern const MagoRemoteEvent_MIDL_EXPR_FORMAT_STRING MagoRemoteEvent__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: MagoRemoteEvent, ver. 1.0,
   GUID={0xF5FECC74,0x6345,0x464A,{0xB4,0x79,0x74,0xF2,0x28,0x57,0x27,0x1C}} */



static const RPC_CLIENT_INTERFACE MagoRemoteEvent___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0xF5FECC74,0x6345,0x464A,{0xB4,0x79,0x74,0xF2,0x28,0x57,0x27,0x1C}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE MagoRemoteEvent_v1_0_c_ifspec = (RPC_IF_HANDLE)& MagoRemoteEvent___RpcClientInterface;

extern const MIDL_STUB_DESC MagoRemoteEvent_StubDesc;

static RPC_BINDING_HANDLE MagoRemoteEvent__MIDL_AutoBindHandle;


HRESULT MagoRemoteEvent_Open( 
    /* [in] */ handle_t hBinding,
    /* [in] */ const GUID *sessionUuid,
    /* [out] */ HCTXEVENT *phContext)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&hBinding);
    return ( HRESULT  )_RetVal.Simple;
    
}


void MagoRemoteEvent_Close( 
    /* [out][in] */ HCTXEVENT *phContext)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[46],
                  ( unsigned char * )&phContext);
    
}


void MagoRemoteEvent_OnProcessStart( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[82],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnProcessExit( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD exitCode)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[124],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnThreadStart( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_ThreadInfo *threadInfo)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[172],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnThreadExit( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD threadId,
    /* [in] */ DWORD exitCode)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[220],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnModuleLoad( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_ModuleInfo *modInfo)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[274],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnModuleUnload( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ MagoRemote_Address baseAddress)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[322],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnOutputString( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [string][in] */ const wchar_t *outputString)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[370],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnLoadComplete( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD threadId)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[418],
                  ( unsigned char * )&hContext);
    
}


MagoRemote_RunMode MagoRemoteEvent_OnException( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ DWORD threadId,
    /* [in] */ boolean firstChance,
    /* [in] */ unsigned int recordCount,
    /* [in][size_is] */ MagoRemote_ExceptionRecord *exceptRecords)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[466],
                  ( unsigned char * )&hContext);
    return ( MagoRemote_RunMode  )_RetVal.Simple;
    
}


MagoRemote_RunMode MagoRemoteEvent_OnBreakpoint( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId,
    /* [in] */ MagoRemote_Address address,
    /* [in] */ boolean embedded)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[538],
                  ( unsigned char * )&hContext);
    return ( MagoRemote_RunMode  )_RetVal.Simple;
    
}


void MagoRemoteEvent_OnStepComplete( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[604],
                  ( unsigned char * )&hContext);
    
}


void MagoRemoteEvent_OnAsyncBreak( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[652],
                  ( unsigned char * )&hContext);
    
}


MagoRemote_ProbeRunMode MagoRemoteEvent_OnCallProbe( 
    /* [in] */ HCTXEVENT hContext,
    /* [in] */ unsigned int pid,
    /* [in] */ unsigned int threadId,
    /* [in] */ MagoRemote_Address address,
    /* [out] */ MagoRemote_AddressRange *thunkRange)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MagoRemoteEvent_StubDesc,
                  (PFORMAT_STRING) &MagoRemoteEvent__MIDL_ProcFormatString.Format[700],
                  ( unsigned char * )&hContext);
    return ( MagoRemote_ProbeRunMode  )_RetVal.Simple;
    
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


static const MagoRemoteEvent_MIDL_PROC_FORMAT_STRING MagoRemoteEvent__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure MagoRemoteEvent_Open */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x44 ),	/* 68 */
/* 16 */	NdrFcShort( 0x40 ),	/* 64 */
/* 18 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
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

/* 34 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 36 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 38 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter phContext */

/* 40 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 42 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 44 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_Close */


	/* Return value */

/* 46 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 48 */	NdrFcLong( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x1 ),	/* 1 */
/* 54 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 56 */	0x30,		/* FC_BIND_CONTEXT */
			0xe8,		/* Ctxt flags:  via ptr, in, out, strict, */
/* 58 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 60 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 62 */	NdrFcShort( 0x38 ),	/* 56 */
/* 64 */	NdrFcShort( 0x38 ),	/* 56 */
/* 66 */	0x40,		/* Oi2 Flags:  has ext, */
			0x1,		/* 1 */
/* 68 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 76 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 78 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 80 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Procedure MagoRemoteEvent_OnProcessStart */

/* 82 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 84 */	NdrFcLong( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x2 ),	/* 2 */
/* 90 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 92 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 94 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 96 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 98 */	NdrFcShort( 0x2c ),	/* 44 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 104 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 112 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 114 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 116 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 118 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 120 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnProcessExit */

/* 124 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x3 ),	/* 3 */
/* 132 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 134 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 136 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 138 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 140 */	NdrFcShort( 0x34 ),	/* 52 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 146 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 154 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 156 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 158 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 160 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exitCode */

/* 166 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnThreadStart */

/* 172 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x4 ),	/* 4 */
/* 180 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 182 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 184 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 186 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 188 */	NdrFcShort( 0x2c ),	/* 44 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x3,		/* 3 */
/* 194 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 202 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 204 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 206 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadInfo */

/* 214 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 218 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Procedure MagoRemoteEvent_OnThreadExit */

/* 220 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x5 ),	/* 5 */
/* 228 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 230 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 232 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 234 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 236 */	NdrFcShort( 0x3c ),	/* 60 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	0x40,		/* Oi2 Flags:  has ext, */
			0x4,		/* 4 */
/* 242 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 250 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 252 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 254 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 258 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 264 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exitCode */

/* 268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnModuleLoad */

/* 274 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0x6 ),	/* 6 */
/* 282 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 284 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 286 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 288 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 290 */	NdrFcShort( 0x2c ),	/* 44 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x3,		/* 3 */
/* 296 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 304 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 306 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 308 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter modInfo */

/* 316 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 320 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Procedure MagoRemoteEvent_OnModuleUnload */

/* 322 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x7 ),	/* 7 */
/* 330 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 332 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 334 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 336 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 338 */	NdrFcShort( 0x3c ),	/* 60 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 342 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 344 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 352 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 354 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 356 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 360 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter baseAddress */

/* 364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 366 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 368 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnOutputString */

/* 370 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 378 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 380 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 382 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 384 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 386 */	NdrFcShort( 0x2c ),	/* 44 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x3,		/* 3 */
/* 392 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 400 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 402 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 404 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter outputString */

/* 412 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 414 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 416 */	NdrFcShort( 0x5a ),	/* Type Offset=90 */

	/* Procedure MagoRemoteEvent_OnLoadComplete */

/* 418 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x9 ),	/* 9 */
/* 426 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 428 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 430 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 432 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 434 */	NdrFcShort( 0x34 ),	/* 52 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 440 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
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

	/* Parameter threadId */

/* 460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 462 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnException */

/* 466 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0xa ),	/* 10 */
/* 474 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 476 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 478 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 480 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 482 */	NdrFcShort( 0x41 ),	/* 65 */
/* 484 */	NdrFcShort( 0x6 ),	/* 6 */
/* 486 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 488 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x1 ),	/* 1 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 496 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 498 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 500 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 502 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 504 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 510 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter firstChance */

/* 514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 516 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 518 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter recordCount */

/* 520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 522 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exceptRecords */

/* 526 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 528 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 530 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 534 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 536 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnBreakpoint */

/* 538 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0xb ),	/* 11 */
/* 546 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 548 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 550 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 552 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 554 */	NdrFcShort( 0x49 ),	/* 73 */
/* 556 */	NdrFcShort( 0x6 ),	/* 6 */
/* 558 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 560 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 568 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 570 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 572 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 582 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter address */

/* 586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 588 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 590 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter embedded */

/* 592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 594 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 596 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 600 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 602 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnStepComplete */

/* 604 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0xc ),	/* 12 */
/* 612 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 614 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 616 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 618 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 620 */	NdrFcShort( 0x34 ),	/* 52 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 626 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 634 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 636 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 638 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 640 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 642 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 648 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnAsyncBreak */

/* 652 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 654 */	NdrFcLong( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0xd ),	/* 13 */
/* 660 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 662 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 664 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 666 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 668 */	NdrFcShort( 0x34 ),	/* 52 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 674 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 682 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 684 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 686 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 688 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 690 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 694 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 696 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MagoRemoteEvent_OnCallProbe */

/* 700 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0xe ),	/* 14 */
/* 708 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 710 */	0x30,		/* FC_BIND_CONTEXT */
			0x48,		/* Ctxt flags:  in, strict, */
/* 712 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 714 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 716 */	NdrFcShort( 0x44 ),	/* 68 */
/* 718 */	NdrFcShort( 0x3a ),	/* 58 */
/* 720 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 722 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 730 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 732 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 734 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pid */

/* 736 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter address */

/* 748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 750 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 752 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter thunkRange */

/* 754 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 756 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 758 */	NdrFcShort( 0x88 ),	/* Type Offset=136 */

	/* Return value */

/* 760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 762 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 764 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

			0x0
        }
    };

static const MagoRemoteEvent_MIDL_TYPE_FORMAT_STRING MagoRemoteEvent__MIDL_TypeFormatString =
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
/* 46 */	NdrFcShort( 0x2 ),	/* Offset= 2 (48) */
/* 48 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 50 */	NdrFcShort( 0x18 ),	/* 24 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x0 ),	/* Offset= 0 (54) */
/* 56 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 58 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 60 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 62 */	
			0x11, 0x0,	/* FC_RP */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 68 */	NdrFcShort( 0x28 ),	/* 40 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0xc ),	/* Offset= 12 (84) */
/* 74 */	0x36,		/* FC_POINTER */
			0x40,		/* FC_STRUCTPAD4 */
/* 76 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 78 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 80 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 82 */	0x3e,		/* FC_STRUCTPAD2 */
			0x5b,		/* FC_END */
/* 84 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 86 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 88 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 90 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 92 */	
			0x11, 0x0,	/* FC_RP */
/* 94 */	NdrFcShort( 0x16 ),	/* Offset= 22 (116) */
/* 96 */	
			0x1d,		/* FC_SMFARRAY */
			0x7,		/* 7 */
/* 98 */	NdrFcShort( 0x78 ),	/* 120 */
/* 100 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 102 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 104 */	NdrFcShort( 0x90 ),	/* 144 */
/* 106 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 108 */	0xb,		/* FC_HYPER */
			0x8,		/* FC_LONG */
/* 110 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 112 */	0x0,		/* 0 */
			NdrFcShort( 0xffef ),	/* Offset= -17 (96) */
			0x5b,		/* FC_END */
/* 116 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 118 */	NdrFcShort( 0x90 ),	/* 144 */
/* 120 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 122 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 124 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 126 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 128 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (102) */
/* 130 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 132 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 134 */	NdrFcShort( 0x2 ),	/* Offset= 2 (136) */
/* 136 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 138 */	NdrFcShort( 0x10 ),	/* 16 */
/* 140 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 142 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const unsigned short MagoRemoteEvent_FormatStringOffsetTable[] =
    {
    0,
    46,
    82,
    124,
    172,
    220,
    274,
    322,
    370,
    418,
    466,
    538,
    604,
    652,
    700
    };


static const MIDL_STUB_DESC MagoRemoteEvent_StubDesc = 
    {
    (void *)& MagoRemoteEvent___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &MagoRemoteEvent__MIDL_AutoBindHandle,
    0,
    0,
    0,
    0,
    MagoRemoteEvent__MIDL_TypeFormatString.Format,
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

