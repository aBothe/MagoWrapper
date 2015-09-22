/*
   Copyright (c) 2010 Aldo J. Nunez

   Licensed under the Apache License, Version 2.0.
   See the LICENSE text file for details.
*/

#pragma once


namespace Mago
{
    class ExprContext;
    class IRegisterSet;


    class FrameProperty : 
        public CComObjectRootEx<CComMultiThreadModel>,
        public IDebugProperty2
    {
        RefPtr<ExprContext>     mExprContext;
        RefPtr<IRegisterSet>    mRegSet;

    public:
        FrameProperty();
        ~FrameProperty();

    DECLARE_NOT_AGGREGATABLE(FrameProperty)

    BEGIN_COM_MAP(FrameProperty)
        COM_INTERFACE_ENTRY(IDebugProperty2)
    END_COM_MAP()

        //////////////////////////////////////////////////////////// 
        // IDebugProperty2 

        STDMETHOD( GetPropertyInfo )( 
            DEBUGPROP_INFO_FLAGS dwFields,
            DWORD dwRadix,
            DWORD dwTimeout,
            IDebugReference2** rgpArgs,
            DWORD dwArgCount,
            DEBUG_PROPERTY_INFO* pPropertyInfo );
        
        STDMETHOD( SetValueAsString )( 
            LPCOLESTR pszValue,
            DWORD dwRadix,
            DWORD dwTimeout );
        
        STDMETHOD( SetValueAsReference )( 
            IDebugReference2** rgpArgs,
            DWORD dwArgCount,
            IDebugReference2* pValue,
            DWORD dwTimeout );
        
        STDMETHOD( EnumChildren )( 
            DEBUGPROP_INFO_FLAGS dwFields,
            DWORD dwRadix,
            REFGUID guidFilter,
            DBG_ATTRIB_FLAGS dwAttribFilter,
            LPCOLESTR pszNameFilter,
            DWORD dwTimeout,
            IEnumDebugPropertyInfo2** ppEnum );
        
        STDMETHOD( GetParent )( 
            IDebugProperty2** ppParent );
        
        STDMETHOD( GetDerivedMostProperty )( 
            IDebugProperty2** ppDerivedMost );
        
        STDMETHOD( GetMemoryBytes )( 
            IDebugMemoryBytes2** ppMemoryBytes );
        
        STDMETHOD( GetMemoryContext )( 
            IDebugMemoryContext2** ppMemory );
        
        STDMETHOD( GetSize )( 
            DWORD* pdwSize );
        
        STDMETHOD( GetReference )( 
            IDebugReference2** ppReference );
        
        STDMETHOD( GetExtendedInfo )( 
            REFGUID guidExtendedInfo,
            VARIANT* pExtendedInfo );

    public:
        HRESULT Init( IRegisterSet* regSet, ExprContext* exprContext );
    };
}
