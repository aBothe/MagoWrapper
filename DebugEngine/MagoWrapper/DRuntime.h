/*
   Copyright (c) 2013 Aldo J. Nunez

   Licensed under the Apache License, Version 2.0.
   See the LICENSE text file for details.
*/

#pragma once

#include <MagoEED.h>
#include "..\MagoNatDE\Utility.h"

struct BB64;
struct TypeInfo_Struct64;
struct DArray64;


using MagoCore::DebuggerProxy;

namespace MagoWrapper
{
    struct Throwable64;


    class DRuntime
    {
        DebuggerProxy*         mDebugger;
        RefPtr<IProcess>    mCoreProc;
        int                     mPtrSize;

    public:
		DRuntime(DebuggerProxy* debugger, IProcess* coreProcess, int ptrSize);

        virtual HRESULT GetValue(
            MagoEE::Address aArrayAddr, 
            const MagoEE::DataObject& key, 
            MagoEE::Address& valueAddr );

        HRESULT GetClassName( Address addr, BSTR* pbstrClassName );

        HRESULT GetExceptionInfo( Address addr, BSTR* pbstrInfo );

    private:
        HRESULT GetStructHash( 
            const MagoEE::DataObject& key, 
            const BB64& bb, 
            // To hash a struct, we need to read the key memory into a buffer.
            // Return it, because the caller needs it, too.
            HeapPtr& keyBuf,
            uint64_t& hash );

        HRESULT GetArrayHash( 
            const MagoEE::DataObject& key, 
            // To hash an array, we need to read the key memory into a buffer.
            // Return it, because the caller needs it, too.
            HeapPtr& keyBuf,
            uint64_t& hash );

        bool EqualArray(
            MagoEE::Type* elemType,
            uint32_t length,
            const void* keyBuf, 
            const void* nodeArrayBuf );

        bool EqualSArray(
            const MagoEE::DataObject& key, 
            const void* keyBuf, 
            const void* nodeArrayBuf );

        bool EqualDArray(
            const MagoEE::DataObject& key, 
            const void* keyBuf, 
            HeapPtr& inout_nodeArrayBuf, 
            const MagoEE::DataValue& nodeKey );

        bool EqualStruct(
            const MagoEE::DataObject& key, 
            const void* keyBuf, 
            const void* nodeArrayBuf );

        HRESULT GetHash( MagoEE::Type* type, const MagoEE::DataValue& value, uint64_t& hash );
        uint64_t DHashOf( const void* buffer, uint32_t length );
        uint32_t AlignTSize( uint32_t size );

        HRESULT ReadMemory( MagoEE::Address addr, uint32_t sizeToRead, void* buffer );

        HRESULT ReadBB( Address addr, BB64& bb );
        HRESULT ReadTypeInfoStruct( Address addr, TypeInfo_Struct64& ti );
        HRESULT ReadAddress( Address baseAddr, uint64_t index, uint64_t& ptrValue );
        HRESULT ReadDArray( Address addr, DArray64& darray );
        HRESULT ReadThrowable( Address addr, Throwable64& throwable );

        DRuntime& operator=( const DRuntime& other );
        DRuntime( const DRuntime& other );
    };
}
