#include "stdafx.h"
#include "SymbolResolver.h"

using namespace System::Runtime::InteropServices;

namespace MagoWrapper
{

	DebugScopedSymbol::DebugScopedSymbol(
		String^ name, 
		String^ typeName, 
		String^ textValue, 
		String^ fullName,
		ULONG size,
		bool hasChildren)
	{
		Name = name;
		TypeName = typeName;
		TextValue = textValue;
		FullName = fullName;
		Size = size;
		HasChildren = HasChildren;
	};

	DebugScopedSymbol::~DebugScopedSymbol()
	{
	}



	SymbolResolver::SymbolResolver(Debuggee^ debuggee)	
	{
		mDebuggee = debuggee;
		mTypeEnv = NULL;

		RefPtr<MagoEE::ITypeEnv> typeEnv;
        HRESULT hr = MagoEE::EED::MakeTypeEnv( typeEnv.Ref() );

		mTypeEnv = typeEnv.Detach();

		mModGuard = new Guard();
		mExprContextGuard = new Guard();

	}

	SymbolResolver::~SymbolResolver()

	{
		delete mExprContextGuard;
		delete mModGuard;
		delete mTypeEnv;
	}

	ULONG64 SymbolResolver::GetAddressFromCodeLine(String^ str, uint16_t line)
	{

		std::list<AddressBinding> bindings;

		//pin_ptr<const wchar_t> pStr = PtrToStringChars(str);

		IntPtr p = Marshal::StringToHGlobalAnsi(str);
		const char* pStr = static_cast<char*>(p.ToPointer());

		bool result = InternalGetAddressByLine(true, pStr, str->Length, line, line, bindings);

		Marshal::FreeHGlobal(p);

		if (result)
		{
			std::list<AddressBinding>::iterator i;
			for (i =  bindings.begin(); i != bindings.end(); ++i)
			{
				return (*i).Addr;
			}
		}
		
		return 0;
	}

	bool SymbolResolver::GetCodeLineFromAddress(ULONG64 address,[Runtime::InteropServices::Out] String^ %File,[Runtime::InteropServices::Out] ULONG %Line)
	{
		const wchar_t* buf = L"";// = new char[512];
		uint16_t fileNameLen = 0;
		uint16_t lineNum = 0;

		if (!InternalGetLineByAddress(address, &buf, &fileNameLen, &lineNum))
			return false;

		Line = lineNum;
		File = gcnew String((fileNameLen > 0)?buf:((wchar_t*)""));
		
		return true;
	}

	String^ SymbolResolver::GetFunctionNameFromAddress(ULONG64 address, DWORD threadId)
	{
		BSTR bstrFuncName; 

		bool modulefound = false;
		for ( ModuleMap::iterator it = mDebuggee->GetModuleMap()->begin();
			it != mDebuggee->GetModuleMap()->end();
			it++ )
		{
			RefPtr<MagoST::ISession>    session;
			RefPtr<Mago::Module> mod =  it->second;

			if (!mod->Contains(address))
				continue;

			FRAMEINFO_FLAGS flags = { 0 };
			flags = FIF_FUNCNAME_MODULE |
						FIF_FUNCNAME_LINES |
						FIF_FUNCNAME_OFFSET |
						FIF_FUNCNAME_ARGS_ALL |
						FIF_FUNCNAME_ARGS_TYPES |
						FIF_FUNCNAME_ARGS_NAMES |
						FIF_FUNCNAME_ARGS_VALUES;



			HRESULT hr = S_OK;
			hr = GetStackFrameName(
						address, 
						threadId,
						mod, 
						flags,
						0,
						&bstrFuncName);


			break;
		}

		String^ v=gcnew String(bstrFuncName);
		
		return v;
	}

	HRESULT SymbolResolver::FindModuleContainingAddress(ULONG64 address, Mago::Module*& module)
	{
		for ( ModuleMap::iterator it = mDebuggee->GetModuleMap()->begin();
			it != mDebuggee->GetModuleMap()->end();
			it++ )
		{
			RefPtr<Mago::Module> mod =  it->second;

			if (!mod->Contains( address ))
				continue;
			
			module = mod.Get();
			module->AddRef();
			return S_OK;
		}
		return E_NOT_FOUND;
	}

	List<DebugScopedSymbol^>^ SymbolResolver::GetLocalSymbols(DWORD threadId)
	{
		List<DebugScopedSymbol^>^ list = gcnew List<DebugScopedSymbol^>();
		
		Address address = mDebuggee->GetCurrentInstructionAddress();

		return GetLocalSymbols(threadId, address);
	}

	List<DebugScopedSymbol^>^ SymbolResolver::GetLocalSymbols(DWORD threadId, Address frameAddress)
	{
		List<DebugScopedSymbol^>^ list = gcnew List<DebugScopedSymbol^>();
		
		HRESULT hr;

		hr = EnumerateLocalSymbols( frameAddress, threadId, list );

		return list;
	}


	List<DebugScopedSymbol^>^ SymbolResolver::GetChildSymbols(String^ expression, DWORD threadId)
	{
		List<DebugScopedSymbol^>^ list = gcnew List<DebugScopedSymbol^>();

		Address address = mDebuggee->GetCurrentInstructionAddress();
		if (address == 0)
			return list;

        HRESULT hr = S_OK;
        RefPtr<MagoST::ISession>    session;
        MagoST::SymHandle           funcSH = { 0 };
        MagoST::SymHandle           childSH = { 0 };
        MagoST::SymbolScope         scope = { 0 };
        MagoST::SymHandle           blockSH = { 0 };
		RefPtr<Mago::Module>		module;

		RefPtr<Thread>				thread;
		RefPtr<Mago::ExprContext>	exprContext;
		CONTEXT						context = { 0 };
		RefPtr<Mago::IRegisterSet>	regSet;

		if (! mDebuggee->GetCoreProcess()->FindThread(threadId, thread.Ref()) )
			return list;

		// TODO: we should get this another way
		context.ContextFlags = CONTEXT_FULL 
			| CONTEXT_FLOATING_POINT | CONTEXT_EXTENDED_REGISTERS;
		if ( !GetThreadContext( thread->GetHandle(), &context ) )
			return list;

		hr = FindModuleContainingAddress(address, module.Ref());
		if ( FAILED( hr ) )
			return list;

		hr = module->GetSymbolSession( session );
		if ( FAILED( hr ) )
			return list;

		hr = FindFunction(address, module, funcSH, blockSH);
		if ( FAILED( hr ) )
			return list;

		regSet = new Mago::RegisterSet( context, thread.Get() );

		hr = session->SetChildSymbolScope( funcSH, scope );
		if ( FAILED( hr ) )
			return list;

		hr = MakeExprContext(address, threadId, module, regSet, funcSH, blockSH, exprContext.Ref());
		if ( FAILED(hr) )
			return list;

		RefPtr<MagoEE::IEEDParsedExpr>  parsedExpr;
		MagoEE::EvalOptions				options = { 0 };
		MagoEE::EvalResult				evalResult;
        RefPtr<MagoEE::IEEDEnumValues>  enumVals;

		pin_ptr<const wchar_t> parentFullName = PtrToStringChars(expression);  

		hr = MagoEE::EED::ParseText( 
			parentFullName, 
			exprContext->GetTypeEnv(), 
			exprContext->GetStringTable(), 
			parsedExpr.Ref() );
		if ( FAILED( hr ) )
			return list;

		hr = parsedExpr->Bind( options, exprContext );
		if ( FAILED( hr ) )
			return list;

		hr = parsedExpr->Evaluate( options, exprContext, evalResult );
		if ( FAILED( hr ) )
			return list;


        hr = MagoEE::EED::EnumValueChildren( 
            exprContext, 
            parentFullName, 
			evalResult.ObjVal, 
            exprContext->GetTypeEnv(),
            exprContext->GetStringTable(),
            enumVals.Ref() );

		if ( FAILED(hr) )
			return list;

		int memberCount = min(enumVals->GetCount(), 100); 
		for (int i = 0; i < memberCount; i++)
		{
			MagoEE::EvalOptions		options = { 0 };
			MagoEE::EvalResult		evalResult;
			std::wstring			name;
			std::wstring			fullName;
            CComBSTR				strValue;
            std::wstring			strType;
			uint32_t				size = 0;


			hr = enumVals->EvaluateNext(options, evalResult, name, fullName);
			if ( FAILED(hr) )
				continue;

			hr = MagoEE::EED::FormatValue( exprContext, evalResult.ObjVal, 0, strValue.m_str );
			if ( FAILED(hr) )
				continue;

            if ( evalResult.ObjVal._Type != NULL )
                evalResult.ObjVal._Type->ToString( strType );

			size = evalResult.ObjVal._Type->GetSize();

			String^ scopedSymbolName = gcnew String( name.c_str() );
			String^ scopedSymbolType = gcnew String( strType.c_str()  );
			String^ scopedSymbolValue = gcnew String( strValue );
			String^ scopedSymbolFullName = gcnew String( fullName.c_str() );

			DebugScopedSymbol^ scopedSymbol = gcnew DebugScopedSymbol( scopedSymbolName, scopedSymbolType, scopedSymbolValue, scopedSymbolFullName, size, evalResult.HasChildren );

			list->Add(scopedSymbol);
		}

		return list;
	}

	DebugScopedSymbol^ SymbolResolver::Evaluate(String^ expression, DWORD threadId)
	{
		Address address = mDebuggee->GetCurrentInstructionAddress();
		if (address == 0)
			return nullptr;

        HRESULT hr = S_OK;
        RefPtr<MagoST::ISession>    session;
        MagoST::SymHandle           funcSH = { 0 };
        MagoST::SymHandle           childSH = { 0 };
        MagoST::SymbolScope         scope = { 0 };
        MagoST::SymHandle           blockSH = { 0 };
		RefPtr<Mago::Module>		module;

		RefPtr<Thread>				thread;
		RefPtr<Mago::ExprContext>	exprContext;
		CONTEXT						context = { 0 };
		RefPtr<Mago::IRegisterSet>	regSet;

		if (! mDebuggee->GetCoreProcess()->FindThread(threadId, thread.Ref()) )
			return nullptr;

		context.ContextFlags = CONTEXT_FULL 
			| CONTEXT_FLOATING_POINT | CONTEXT_EXTENDED_REGISTERS;
		if ( !GetThreadContext( thread->GetHandle(), &context ) )
			return nullptr;

		hr = FindModuleContainingAddress(address, module.Ref());
		if ( FAILED( hr ) )
			return nullptr;

		hr = module->GetSymbolSession( session );
		if ( FAILED( hr ) )
			return nullptr;

		hr = FindFunction(address, module, funcSH, blockSH);
		if ( FAILED( hr ) )
			return nullptr;

		regSet = new Mago::RegisterSet( context, thread.Get() );

		hr = session->SetChildSymbolScope( funcSH, scope );
		if ( FAILED( hr ) )
			return nullptr;

		hr = MakeExprContext(address, threadId, module, regSet, funcSH, blockSH, exprContext.Ref());
		if ( FAILED(hr) )
			return nullptr;

		RefPtr<MagoEE::IEEDParsedExpr>  parsedExpr;
		MagoEE::EvalOptions				options = { 0 };
		MagoEE::EvalResult				evalResult;
        RefPtr<MagoEE::IEEDEnumValues>  enumVals;
		std::wstring					fullName;
        CComBSTR						strValue;
        std::wstring					strType;
		uint32_t						size = 0;

		options.AllowAssignment = true;

		pin_ptr<const wchar_t> strExpression = PtrToStringChars(expression);  

		hr = MagoEE::EED::ParseText( 
				strExpression, 
				exprContext->GetTypeEnv(), 
				exprContext->GetStringTable(), 
				parsedExpr.Ref() );
		if ( FAILED( hr ) )
			return nullptr;

		hr = parsedExpr->Bind( options, exprContext );
		if ( FAILED( hr ) )
			return nullptr;

		hr = parsedExpr->Evaluate( options, exprContext, evalResult );
		if ( FAILED( hr ) )
			return nullptr;

		MagoEE::EED::FormatValue( exprContext, evalResult.ObjVal, 0, strValue.m_str );
		if ( FAILED( hr ) )
			return nullptr;

        if ( evalResult.ObjVal._Type != NULL )
            evalResult.ObjVal._Type->ToString( strType );

		size = evalResult.ObjVal._Type->GetSize();

		String^ scopedSymbolName = gcnew String( strExpression );
		String^ scopedSymbolType = gcnew String( strType.c_str() );
		String^ scopedSymbolValue = gcnew String( strValue );
		String^ scopedSymbolFullName = gcnew String( strExpression );

		return gcnew DebugScopedSymbol( scopedSymbolName, scopedSymbolType, scopedSymbolValue, scopedSymbolFullName, size, evalResult.HasChildren );
	}

	HRESULT SymbolResolver::EnumerateLocalSymbols(ULONG64 address, DWORD threadId, List<DebugScopedSymbol^>^ list)
	{

        HRESULT hr = S_OK;
        RefPtr<MagoST::ISession>    session;
        MagoST::SymHandle           funcSH = { 0 };
        MagoST::SymHandle           blockSH = { 0 };
		RefPtr<Mago::Module>		module;

		if (address == 0)
			return E_NOT_FOUND;

		hr = FindModuleContainingAddress(address, module.Ref());
		if ( FAILED(hr) )
			return hr;

		hr = module->GetSymbolSession( session );
		if ( FAILED( hr ) )
			return hr;

		hr = FindFunction(address, module, funcSH, blockSH);
		if ( FAILED( hr ) )
			return hr;

        MagoST::SymbolScope         scope = { 0 };
        MagoST::SymHandle           childSH = { 0 };
		RefPtr<Thread>				thread;
		RefPtr<Mago::ExprContext>	exprContext;
		CONTEXT						context = { 0 };
		RefPtr<Mago::IRegisterSet>	regSet;

		if (! mDebuggee->GetCoreProcess()->FindThread(threadId, thread.Ref()) )
			return E_FAIL;

		context.ContextFlags = CONTEXT_FULL 
			| CONTEXT_FLOATING_POINT | CONTEXT_EXTENDED_REGISTERS;
		if ( !GetThreadContext( thread->GetHandle(), &context ) )
			return E_FAIL;
		
		regSet = new Mago::RegisterSet( context, thread.Get() );

		hr = session->SetChildSymbolScope( funcSH, scope );
		if ( FAILED( hr ) )
			return hr;

		hr = MakeExprContext(address, threadId, module, regSet, funcSH, blockSH, exprContext.Ref());
		if ( FAILED(hr) )
			return hr;

		while ( session->NextSymbol( scope, childSH ) )
		{
			MagoST::SymInfoData     infoData = { 0 };
			MagoST::ISymbolInfo*    symInfo = NULL;
			PasString*              pstrName = NULL;
			CComBSTR                strName;


			hr = session->GetSymbolInfo( childSH, infoData, symInfo );
			if ( FAILED( hr ) )
				continue;

			if ( !symInfo->GetName( pstrName ) )
				continue;

			hr = Utf8To16( pstrName->GetName(), pstrName->GetLength(), strName.m_str );
			if ( FAILED( hr ) )
				continue;

			RefPtr<MagoEE::IEEDParsedExpr>  parsedExpr;
			MagoEE::EvalOptions		options = { 0 };
			MagoEE::EvalResult		evalResult;
			std::wstring			fullName;
            CComBSTR				strValue;
            std::wstring			strType;
			uint32_t				size = 0;

			hr = MagoEE::EED::ParseText( 
				strName.m_str, 
				exprContext->GetTypeEnv(), 
				exprContext->GetStringTable(), 
				parsedExpr.Ref() );
			if ( FAILED( hr ) )
				continue;

			hr = parsedExpr->Bind( options, exprContext );
			if ( FAILED( hr ) )
				continue;

			hr = parsedExpr->Evaluate( options, exprContext, evalResult );
			if ( FAILED( hr ) )
				continue;

			MagoEE::EED::FormatValue( exprContext, evalResult.ObjVal, 0, strValue.m_str );
			if ( FAILED( hr ) )
				continue;

            if ( evalResult.ObjVal._Type != NULL )
                evalResult.ObjVal._Type->ToString( strType );

			size = evalResult.ObjVal._Type->GetSize();

			String^ scopedSymbolName = gcnew String( strName.m_str );
			String^ scopedSymbolType = gcnew String( strType.c_str() );
			String^ scopedSymbolValue = gcnew String( strValue );
			String^ scopedSymbolFullName = gcnew String( strName.m_str );

			DebugScopedSymbol^ scopedSymbol = gcnew DebugScopedSymbol( scopedSymbolName, scopedSymbolType, scopedSymbolValue, scopedSymbolFullName, size, evalResult.HasChildren );

			list->Add(scopedSymbol);
		}

		return S_OK;		
	}

    bool SymbolResolver::InternalGetAddressByLine( 
        bool exactMatch, 
        const char* fileName, 
        size_t fileNameLen, 
        uint16_t reqLineStart, 
        uint16_t reqLineEnd,
        std::list<AddressBinding>& bindings )
    {
        GuardedArea guard( *mModGuard );

        HRESULT hr = S_OK;
        bool    foundMatch = false;

        for ( ModuleMap::iterator it = mDebuggee->GetModuleMap()->begin();
            it != mDebuggee->GetModuleMap()->end();
            it++ )
        {
            RefPtr<MagoST::ISession>    session;
			Mago::Module*  mod =  reinterpret_cast<Mago::Module*>(it->second.Get());
            uint32_t compCount = 0;

            if ( !mod->GetSymbolSession( session ) )
                continue;

            hr = session->GetCompilandCount( compCount );
            if ( FAILED( hr ) )
                continue;

            for ( uint16_t compIx = 1; compIx <= compCount; compIx++ )
            {
                MagoST::CompilandInfo   compInfo = { 0 };

                hr = session->GetCompilandInfo( compIx, compInfo );
                if ( FAILED( hr ) )
                    continue;

                for ( uint16_t fileIx = 0; fileIx < compInfo.FileCount; fileIx++ )
                {
                    MagoST::FileInfo    fileInfo = { 0 };
                    bool                matches = false;

                    hr = session->GetFileInfo( compIx, fileIx, fileInfo );
                    if ( FAILED( hr ) )
                        continue;

                    if ( exactMatch )
                        matches = ExactFileNameMatch( fileName, fileNameLen, fileInfo.Name, fileInfo.NameLength );
                    else
                        matches = PartialFileNameMatch( fileName, fileNameLen, fileInfo.Name, fileInfo.NameLength );

                    if ( !matches )
                        continue;

                    foundMatch = true;

                    MagoST::LineNumber  line = { 0 };
                    if ( !session->FindLineByNum( compIx, fileIx, (uint16_t) reqLineStart, line ) )
                        continue;

                    // do the line ranges overlap?
                    if ( ((line.Number <= reqLineEnd) && (line.NumberEnd >= reqLineStart)) )
                    {
                        line.NumberEnd = line.Number;

                        bindings.push_back( AddressBinding() );
                        bindings.back().Addr = session->GetVAFromSecOffset( line.Section, line.Offset );
                        bindings.back().Mod = mod;
                    }
                }
            }
        }

        return foundMatch;
    }

    bool SymbolResolver::InternalGetLineByAddress( 
		ULONG64 address,
		const wchar_t ** fileName, 
        WORD* fileNameLen, 
		uint16_t* lineNum)
    {
        GuardedArea guard( *mModGuard );

        HRESULT hr = S_OK;

        for ( ModuleMap::iterator it = mDebuggee->GetModuleMap()->begin();
            it != mDebuggee->GetModuleMap()->end();
            it++ )
        {
            RefPtr<MagoST::ISession>    session;
			Mago::Module*  mod =  reinterpret_cast<Mago::Module*>(it->second.Get());
            uint32_t compCount = 0;

			if ( !mod->Contains(address))
				continue;

            if ( !mod->GetSymbolSession( session ) )
                break;

			uint16_t    sec = 0;
			uint32_t    offset = 0;
			sec = session->GetSecOffsetFromVA( address, offset );
			if ( sec == 0 )
				return false;

			MagoST::LineNumber line = { 0 };
			if ( !session->FindLine( sec, offset, line ) )
				return false;

			MagoST::FileInfo    fileInfo = { 0 };
			hr = session->GetFileInfo( line.CompilandIndex, line.FileIndex, fileInfo );
			if ( FAILED( hr ) )
				return false;

			BSTR bstrFileName = L"";
			hr = Utf8To16( fileInfo.Name, fileInfo.NameLength, bstrFileName );
			if ( FAILED( hr ) )
				return false;

			*lineNum = line.Number;
			*fileName = bstrFileName;
			*fileNameLen = fileInfo.NameLength;

			return true;
        }

        return false;
    }

    HRESULT SymbolResolver::GetStackFrameName( 
		uintptr_t address,
		DWORD threadId,
		Mago::Module* module,
        FRAMEINFO_FLAGS flags, 
        UINT radix, 
        BSTR* funcName )
    {
        _ASSERT( funcName != NULL );
        HRESULT hr = S_OK;
        CString fullName;

        if ( (flags & FIF_FUNCNAME_MODULE) != 0 )
        {
            if ( module != NULL )
            {
                CComBSTR modNameBstr;
                module->GetName( modNameBstr );
                fullName.Append( modNameBstr );
                fullName.AppendChar( L'!' );
            }
        }

        hr = AppendFunctionNameWithSymbols( address, threadId, module, flags, radix, fullName );
        if ( FAILED( hr ) )
        {
            hr = AppendFunctionNameWithAddress( address, module, flags, radix, fullName );
            if ( FAILED( hr ) )
                return hr;
        }

        *funcName = fullName.AllocSysString();

        return hr;
    }

    HRESULT SymbolResolver::AppendFunctionNameWithAddress( 
		uintptr_t address,
		Mago::Module* module,
        FRAMEINFO_FLAGS flags, 
        UINT radix, 
        CString& fullName )
    {
        C_ASSERT( sizeof address == 4 );
        fullName.AppendFormat( L"%08x", address );

        return S_OK;
    }

    HRESULT SymbolResolver::AppendFunctionNameWithSymbols( 
		uintptr_t address,
		DWORD threadId,
		Mago::Module* module,
        FRAMEINFO_FLAGS flags, 
        UINT radix, 
        CString& fullName )
    {
        HRESULT hr = S_OK;
        RefPtr<MagoST::ISession>    session;
        MagoST::SymInfoData         infoData = { 0 };
        MagoST::ISymbolInfo*        symInfo = NULL;

        if ( module == NULL )
            return E_NOT_FOUND;

        if ( !module->GetSymbolSession( session ) )
            return E_NOT_FOUND;

		MagoST::SymHandle func = { 0 };
		MagoST::SymHandle  block = { 0 };

        hr = FindFunction(address, module, func, block);
        if ( FAILED( hr ) )
            return hr;

        hr = session->GetSymbolInfo( func, infoData, symInfo );
        if ( FAILED( hr ) )
            return hr;

        hr = AppendFunctionNameWithSymbols( address, threadId, module, flags, radix, session, symInfo, func, fullName );

        return hr;
    }

    HRESULT SymbolResolver::AppendFunctionNameWithSymbols( 
		uintptr_t address,
		DWORD threadId,
		Mago::Module* module,
        FRAMEINFO_FLAGS flags, 
        UINT radix, 
        MagoST::ISession* session,
        MagoST::ISymbolInfo* symInfo, 
		MagoST::SymHandle& func,
        CString& fullName )
    {
        _ASSERT( session != NULL );
        _ASSERT( symInfo != NULL );
        HRESULT hr = S_OK;
        CComBSTR funcNameBstr;

        PasString*  pstrName = NULL;
        if ( !symInfo->GetName( pstrName ) )
            return E_NOT_FOUND;

        hr = Utf8To16( pstrName->GetName(), pstrName->GetLength(), funcNameBstr.m_str );
        if ( FAILED( hr ) )
            return hr;

        fullName.Append( funcNameBstr );
        fullName.AppendChar( L'(' );

        if ( (flags & FIF_FUNCNAME_ARGS_ALL) != 0 )
        {
            AppendArgs( flags, radix, address, threadId, module, session, symInfo, func, fullName);
        }

        fullName.AppendChar( L')' );

        bool hasLineInfo = false;
        Address baseAddr = 0;

        if ( (flags & FIF_FUNCNAME_LINES) != 0 )
        {
            StackLineInfo line;
            if ( SUCCEEDED( GetStackLineInfo( address, module, line ) ) )
            {
                hasLineInfo = true;
                baseAddr = line.Address;
                // lines are 1-based to user, but 0-based from symbol store
                DWORD lineNumber = line.LineBegin.dwLine + 1;
                const wchar_t* lineStr = GetString( IDS_LINE );

                fullName.AppendFormat( L" %s %u", lineStr, lineNumber );
            }
        }

        if ( !hasLineInfo )
        {
            uint16_t sec = 0;
            uint32_t offset = 0;

            symInfo->GetAddressSegment( sec );
            symInfo->GetAddressOffset( offset );
            baseAddr = (Address) session->GetVAFromSecOffset( sec, offset );
        }

        if ( ((flags & FIF_FUNCNAME_OFFSET) != 0) && (address != baseAddr) )
        {
            const wchar_t* bytesStr = GetString( IDS_BYTES );
            fullName.AppendFormat( L" + 0x%x %s", address - baseAddr, bytesStr );
        }

        return S_OK;
    }

    HRESULT SymbolResolver::GetStackLineInfo(
		uintptr_t address,
		Mago::Module* module,
		StackLineInfo& info )
    {
        HRESULT hr = S_OK;
        RefPtr<MagoST::ISession>    session;

        if ( module == NULL )
            return E_NOT_FOUND;

        if ( !module->GetSymbolSession( session ) )
            return E_NOT_FOUND;

        uint16_t    sec = 0;
        uint32_t    offset = 0;
        sec = session->GetSecOffsetFromVA( address, offset );
        if ( sec == 0 )
            return E_FAIL;

        MagoST::LineNumber line = { 0 };
        if ( !session->FindLine( sec, offset, line ) )
            return E_FAIL;

        info.LineBegin.dwLine = line.Number;
        //info.LineEnd.dwLine = line.NumberEnd;
        info.LineEnd.dwLine = line.Number;
        info.LineBegin.dwColumn = 0;
        info.LineEnd.dwColumn = 0;

        info.LineBegin.dwLine--;
        info.LineEnd.dwLine--;

        // if there's no column info, then these are 0
        if ( info.LineBegin.dwColumn > 0 )
            info.LineBegin.dwColumn--;
        if ( info.LineEnd.dwColumn > 0 )
            info.LineEnd.dwColumn--;

        info.Address = (Address) session->GetVAFromSecOffset( line.Section, line.Offset );

        MagoST::FileInfo    fileInfo = { 0 };
        hr = session->GetFileInfo( line.CompilandIndex, line.FileIndex, fileInfo );
        if ( FAILED( hr ) )
            return hr;

        hr = Utf8To16( fileInfo.Name, fileInfo.NameLength, info.Filename.m_str );
        if ( FAILED( hr ) )
            return hr;

        info.LangName = L"D";
        info.LangGuid = GetDLanguageId();

        return hr;
    }

	HRESULT SymbolResolver::FindFunction(
		uintptr_t address, 
		Mago::Module* module, 
		MagoST::SymHandle& func,  
		MagoST::SymHandle& block)
    {
        HRESULT hr = S_OK;
        RefPtr<MagoST::ISession>    session;
        MagoST::SymHandle           symHandle = { 0 };

        // already found
        if ( memcmp( &func, &symHandle, sizeof (func) ) != 0 )
            return S_OK;

        if ( module == NULL )
            return E_NOT_FOUND;

        if ( !module->GetSymbolSession( session ) )
            return E_NOT_FOUND;

        uint16_t    sec = 0;
        uint32_t    offset = 0;
        sec = session->GetSecOffsetFromVA( address, offset );
        if ( sec == 0 )
            return E_NOT_FOUND;

        hr = session->FindOuterSymbolByAddr( MagoST::SymHeap_GlobalSymbols, sec, offset, symHandle );
        if ( FAILED( hr ) )
        {
            hr = session->FindOuterSymbolByAddr( MagoST::SymHeap_StaticSymbols, sec, offset, symHandle );
            if ( FAILED( hr ) )
            {
                hr = session->FindOuterSymbolByAddr( MagoST::SymHeap_PublicSymbols, sec, offset, symHandle );
                if ( FAILED( hr ) )
                    return hr;
            }
        }

        func = symHandle;

        hr = session->FindInnermostSymbol( func, sec, offset, block );

        return S_OK;
    }
	
    HRESULT SymbolResolver::AppendArgs(
        FRAMEINFO_FLAGS flags, 
        UINT radix, 
		uintptr_t address, 
		DWORD threadId,
		Mago::Module* module, 
        MagoST::ISession* session,
        MagoST::ISymbolInfo* symInfo,
		MagoST::SymHandle& func,
        CString& outputStr )
    {
        _ASSERT( session != NULL );
        _ASSERT( symInfo != NULL );
        HRESULT             hr = S_OK;
        MagoST::SymbolScope funcScope = { 0 };
        MagoST::SymHandle   childSH = { 0 };
        MagoST::SymHandle   blockSH = { 0 };
        int                 paramCount = 0;
        std::wstring        typeStr;

		RefPtr<Thread> thread;
		if (! mDebuggee->GetCoreProcess()->FindThread(threadId, thread.Ref()) )
			return E_FAIL;

		CONTEXT         context = { 0 };
		RefPtr<Mago::IRegisterSet> regSet;

		context.ContextFlags = CONTEXT_FULL 
			| CONTEXT_FLOATING_POINT | CONTEXT_EXTENDED_REGISTERS;
		if ( !GetThreadContext( thread->GetHandle(), &context ) )
			return E_FAIL;
		
		regSet = new Mago::RegisterSet( context, thread.Get() );
		RefPtr<Mago::ExprContext> exprContext;

		hr = MakeExprContext(address, threadId, module, regSet, func, blockSH, exprContext.Ref());
		if ( FAILED(hr) )
			return hr;

        hr = session->SetChildSymbolScope( func, funcScope );
        if ( FAILED( hr ) )
            return hr;

        while ( session->NextSymbol( funcScope, childSH ) )
        {
            MagoST::SymInfoData     childData = { 0 };
            MagoST::ISymbolInfo*    childSym = NULL;
            MagoST::SymTag          tag = MagoST::SymTagNull;
            RefPtr<MagoEE::Type>    type;
            RefPtr<MagoEE::Declaration> decl;

            session->GetSymbolInfo( childSH, childData, childSym );
            if ( childSym == NULL )
                continue;

            tag = childSym->GetSymTag();
            if ( tag == MagoST::SymTagEndOfArgs )
                break;

            exprContext->MakeDeclarationFromSymbol( childSH, decl.Ref() );
            if ( decl == NULL )
                continue;

            if ( paramCount > 0 )
                outputStr.AppendChar( L',' );

            if ( (flags & FIF_FUNCNAME_ARGS_TYPES) != 0 )
            {
                if ( decl->GetType( type.Ref() ) )
                {
                    typeStr.clear();
                    type->ToString( typeStr );
                    outputStr.AppendFormat( L" %.*s", typeStr.size(), typeStr.c_str() );
                }
            }

            if ( (flags & FIF_FUNCNAME_ARGS_NAMES) != 0 )
            {
                outputStr.AppendFormat( L" %s", decl->GetName() );
            }

            if ( (flags & FIF_FUNCNAME_ARGS_VALUES) != 0 )
            {
                MagoEE::DataObject resultObj = { 0 };
                CComBSTR valueBstr;

                hr = exprContext->Evaluate( decl, resultObj );
                if ( hr == S_OK )
                {
                    hr = MagoEE::EED::FormatValue( exprContext, resultObj, radix, valueBstr.m_str );
                    if ( hr == S_OK )
                    {
                        outputStr.AppendFormat( L" = %.*s", valueBstr.Length(), valueBstr.m_str );
                    }
                }
            }

            paramCount++;
        }

        if ( paramCount > 0 )
            outputStr.AppendChar( L' ' );

        return S_OK;
    }

	HRESULT SymbolResolver::MakeExprContext(
		ULONG64 address, 
		DWORD threadId,
		Mago::Module* module,
		Mago::IRegisterSet* regSet,
		MagoST::SymHandle& func,  
		MagoST::SymHandle& block, 
		Mago::ExprContext*& exprCtx)
    {
        HRESULT hr = S_OK;

        hr = FindFunction(address, module, func, block);

        if ( exprCtx == NULL )
        {
            GuardedArea guard( *mExprContextGuard );

            if ( exprCtx == NULL )
            {
				RefPtr<Thread> thread;				
				if (!mDebuggee->GetCoreProcess()->FindThread(threadId, thread.Ref() ))
					return E_FAIL;

                RefPtr<Mago::ExprContext>         exprContext;
                hr = MakeCComObject( exprContext );
                if ( FAILED( hr ) )
                    return hr;

				hr = exprContext->Init( mDebuggee->GetDebuggerProxy(), mDebuggee->GetCoreProcess(), module, thread, func, block, address, regSet );
                if ( FAILED( hr ) )
                    return hr;

				exprCtx = exprContext.Detach();
            }
        }

        return S_OK;
    }

}