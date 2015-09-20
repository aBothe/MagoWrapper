#include "stdafx.h"
#include "SymbolResolver.h"


#include "..\..\CVSym\CVSym\cvconst.h"

#include "..\..\CVSym\CVSym\CVSymPublic.h"

#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\RegisterSet.h"
#include "..\MagoNatDE\Config.h"
#include "..\MagoNatDE\EnumFrameInfo.h"
#include "..\MagoNatDE\Program.h"

using namespace System::Runtime::InteropServices;

const HRESULT E_NOT_FOUND = HRESULT_FROM_WIN32(ERROR_NOT_FOUND);

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



	SymbolResolver::SymbolResolver(Debuggee^ debuggee, int ptrSize)
	{
		mPtrSize = ptrSize;
		mDebuggee = debuggee;
		mTypeEnv = NULL;

		RefPtr<MagoEE::ITypeEnv> typeEnv;
		HRESULT hr = MagoEE::EED::MakeTypeEnv(mPtrSize, typeEnv.Ref());

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

		bool result = InternalGetAddressesByLine(true, pStr, str->Length, line, line, bindings);

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

	List<DebugScopedSymbol^>^ SymbolResolver::GetLocalSymbols(DWORD threadId)
	{
		Address address = mDebuggee->GetCurrentInstructionAddress();
		List<DebugScopedSymbol^>^ list = GetLocalSymbols(threadId, address);

		return list;
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
		CComModule _Module;
		List<DebugScopedSymbol^>^ list = gcnew List<DebugScopedSymbol^>();

		IDebugProperty2* dp = NULL;
		HRESULT hr = EvaluateExpression(expression, threadId, &dp);
		if (FAILED(hr))
			return list;

		DEBUGPROP_INFO_FLAGS diflags =
			DEBUGPROP_INFO_NAME
			| DEBUGPROP_INFO_FULLNAME
			| DEBUGPROP_INFO_VALUE
			| DEBUGPROP_INFO_TYPE
			| DEBUGPROP_INFO_PROP
			| DEBUGPROP_INFO_ATTRIB;

		DEBUG_PROPERTY_INFO dpi;
		hr = dp->GetPropertyInfo(diflags, 10, 1000, NULL, 0, &dpi);
		if (FAILED(hr))
			return list;

		bool hasChildren = (dpi.dwAttrib & DBG_ATTRIB_OBJ_IS_EXPANDABLE == DBG_ATTRIB_OBJ_IS_EXPANDABLE);
		if (!hasChildren)
			return list;
		
		CComModule _Module2;
		IEnumDebugPropertyInfo2* edpi = NULL;	
		hr = dp->EnumChildren(diflags, 10, guidFilterAllLocals, DBG_ATTRIB_ALL, NULL, 1000, &edpi);
		if (FAILED(hr))
			return list;

		ULONG cnt = 0;
		hr = edpi->GetCount(&cnt);
		if (FAILED(hr))
			return list;

		DEBUG_PROPERTY_INFO* dpiArray = new DEBUG_PROPERTY_INFO[cnt];
		ULONG fetched = 0;
		while (fetched < cnt) {
			ULONG ft;
			hr = edpi->Next(cnt - fetched, &dpiArray[fetched], &ft);
			if (FAILED(hr))
			{
				delete [] dpiArray;
				return list;
			}
			fetched += ft;
		}

		for (ULONG i = 0; i < fetched; i++)
		{
			DEBUG_PROPERTY_INFO* dpi = &dpiArray[i];
			DWORD size = 0;
			dpi->pProperty->GetSize(&size);
			bool hasChildren = (dpi->dwAttrib & DBG_ATTRIB_OBJ_IS_EXPANDABLE == DBG_ATTRIB_OBJ_IS_EXPANDABLE);

			String^ scopedSymbolName = gcnew String(dpi->bstrName);
			String^ scopedSymbolType = gcnew String(dpi->bstrType);
			String^ scopedSymbolValue = nullptr;
			if (!IsBadStringPtr(dpi->bstrValue, 255)) // == 0xCDCDCDCD
				scopedSymbolValue = gcnew String(dpi->bstrValue);
			else
				scopedSymbolValue = gcnew String(String::Empty);
			String^ scopedSymbolFullName = gcnew String(dpi->bstrFullName);

			DebugScopedSymbol^ scopedSymbol = gcnew DebugScopedSymbol(scopedSymbolName, scopedSymbolType, scopedSymbolValue, scopedSymbolFullName, size, hasChildren);
			list->Add(scopedSymbol);
		}

		delete [] dpiArray;
		return list;
	}

	HRESULT SymbolResolver::EvaluateExpression(String^ expression, DWORD threadId, IDebugProperty2** dp)
	{
		CComModule _Module;
		RefPtr<Mago::Thread> thread;
		if (!mDebuggee->GetThread(threadId, thread))
			return E_FAIL;

		Mago::Thread::Callstack callstack;
		HRESULT hr = thread->BuildCallstack(callstack);
		if (FAILED(hr) || callstack.size() == 0)
			return hr;

		IDebugExpressionContext2* dectx = NULL;
		hr = callstack[0]->GetExpressionContext(&dectx);
		if (FAILED(hr))
			return hr;

		pin_ptr<const wchar_t> strExpression = PtrToStringChars(expression);  
		
		PARSEFLAGS pFlags = 
			PARSE_EXPRESSION 
			| PARSE_FUNCTION_AS_ADDRESS
			| PARSE_DESIGN_TIME_EXPR_EVAL;

		IDebugExpression2* de = NULL;
		BSTR sErr;
		UINT pichErr;
		hr = dectx->ParseText(strExpression, pFlags, 10, &de, &sErr, &pichErr);
		if (FAILED(hr))
			return hr;
		
		EVALFLAGS evFlags =
			EVAL_RETURNVALUE
			| EVAL_NOSIDEEFFECTS
			| EVAL_ALLOWBPS
			| EVAL_ALLOWERRORREPORT
			| EVAL_FUNCTION_AS_ADDRESS 
			| EVAL_NOFUNCEVAL
			| EVAL_NOEVENTS
			| EVAL_DESIGN_TIME_EXPR_EVAL
			| EVAL_ALLOW_IMPLICIT_VARS;
		IDebugProperty2* _dp = NULL;
		hr = de->EvaluateSync(evFlags, 1000, NULL, &_dp);
		if (FAILED(hr))
			return hr;

		*dp = _dp;
		return S_OK;
	}

	DebugScopedSymbol^ SymbolResolver::Evaluate(String^ expression, DWORD threadId)
	{
		IDebugProperty2* dp = NULL;
		HRESULT hr = EvaluateExpression(expression, threadId, &dp);
		if (FAILED(hr))
			return nullptr;

		DEBUGPROP_INFO_FLAGS diflags =
			DEBUGPROP_INFO_NAME
			| DEBUGPROP_INFO_FULLNAME
			| DEBUGPROP_INFO_VALUE
			| DEBUGPROP_INFO_TYPE
			| DEBUGPROP_INFO_PROP
			| DEBUGPROP_INFO_ATTRIB;
		
		DEBUG_PROPERTY_INFO dpi;
		hr = dp->GetPropertyInfo(diflags, 10, 1000, NULL, 0, &dpi);
		if (FAILED(hr))
			return nullptr;
		
		DWORD size = 0;
		dpi.pProperty->GetSize(&size);
		bool hasChildren = (dpi.dwAttrib & DBG_ATTRIB_OBJ_IS_EXPANDABLE == DBG_ATTRIB_OBJ_IS_EXPANDABLE);

		String^ scopedSymbolName = gcnew String(dpi.bstrName);
		String^ scopedSymbolType = gcnew String(dpi.bstrType);
		String^ scopedSymbolValue = nullptr;
		if (!IsBadStringPtr(dpi.bstrValue, 255)) // == 0xCDCDCDCD
			scopedSymbolValue = gcnew String(dpi.bstrValue);
		else
			scopedSymbolValue = gcnew String(String::Empty);
		String^ scopedSymbolFullName = gcnew String(dpi.bstrFullName);

		DebugScopedSymbol^ scopedSymbol = gcnew DebugScopedSymbol(scopedSymbolName, scopedSymbolType, scopedSymbolValue, scopedSymbolFullName, size, hasChildren);
		return scopedSymbol;
	}

	HRESULT SymbolResolver::EnumerateLocalSymbols(ULONG64 address, DWORD threadId, List<DebugScopedSymbol^>^ list)
	{

        HRESULT hr = S_OK;
		CComModule _Module;
		RefPtr<Mago::Thread> thread;
		if (!mDebuggee->GetThread(threadId, thread))
			return E_FAIL;

		Mago::Thread::Callstack callstack;
		thread->BuildCallstack(callstack);

		Mago::StackFrame* sfrm = NULL;
		int i = 0;
		for (Mago::Thread::Callstack::const_iterator it = callstack.begin();
			it != callstack.end();
			it++, i++)
		{
			Mago::Address64 addr;
			Mago::Address64 eip;
			hr = (*it)->GetAddress(addr);
			if (FAILED(hr))
				return hr;

			hr = (*it)->GetAddress(eip);
			if (FAILED(hr))
				return hr;

			if (addr == address)
			{
				sfrm = (*it);
				break;
			}
		}

		if (!sfrm)
			return E_FAIL;

		DEBUGPROP_INFO_FLAGS diflags =
			DEBUGPROP_INFO_NAME
			| DEBUGPROP_INFO_FULLNAME
			| DEBUGPROP_INFO_VALUE
			| DEBUGPROP_INFO_TYPE
			| DEBUGPROP_INFO_PROP
			| DEBUGPROP_INFO_ATTRIB;

		IEnumDebugPropertyInfo2* pi = NULL;	
		ULONG fetched = 0;
		hr = sfrm->EnumProperties(diflags, 10, guidFilterAllLocalsPlusArgs, 2000, &fetched, &pi);
		//array.Detach();
		
		if (FAILED(hr))
			return hr;

		ULONG cnt = fetched;
		fetched = 0;
		DEBUG_PROPERTY_INFO* dpiArray = new DEBUG_PROPERTY_INFO[cnt];
		while (fetched < cnt)
		{
			ULONG ft = 0;
			pi->Next(cnt - fetched, &dpiArray[fetched], &ft);
			if (FAILED(hr))
			{
				delete[] dpiArray;
				return hr;
			}

			fetched += ft;
		}

		for (ULONG i = 0; i < cnt; i++)
		{
			DWORD size = 0;
			dpiArray[i].pProperty->GetSize(&size);
			bool hasChildren = (dpiArray[i].dwAttrib & DBG_ATTRIB_OBJ_IS_EXPANDABLE == DBG_ATTRIB_OBJ_IS_EXPANDABLE);

			String^ scopedSymbolName = gcnew String(dpiArray[i].bstrName);
			String^ scopedSymbolType = gcnew String(dpiArray[i].bstrType);
			String^ scopedSymbolValue = nullptr;
			if (!IsBadStringPtr(dpiArray[i].bstrValue, 255)) // == 0xCDCDCDCD
				scopedSymbolValue = gcnew String(dpiArray[i].bstrValue);
			else
				scopedSymbolValue = gcnew String(String::Empty);
			String^ scopedSymbolFullName = gcnew String(dpiArray[i].bstrFullName);

			DebugScopedSymbol^ scopedSymbol = gcnew DebugScopedSymbol(scopedSymbolName, scopedSymbolType, scopedSymbolValue, scopedSymbolFullName, size, hasChildren);

			list->Add(scopedSymbol); 
		}

		delete[] dpiArray;

		return S_OK;		
	}

    bool SymbolResolver::InternalGetAddressesByLine( 
        bool exactMatch, 
        const char* fileName, 
        size_t fileNameLen, 
        uint16_t reqLineStart, 
        uint16_t reqLineEnd,
        std::list<AddressBinding>& bindings )
    {

		CComModule _Module;
		Mago::Program* prog = mDebuggee->GetProgram();
		IEnumDebugModules2* edm = NULL;
		HRESULT hr = prog->EnumModules(&edm);
		if (FAILED(hr))
			return false;

		ULONG cnt;
		hr = edm->GetCount(&cnt);
		if (FAILED(hr))
			return false;

		IDebugModule2** dmArray = new IDebugModule2*[cnt];
		ULONG fetched = 0;
		while (fetched < cnt)
		{
			ULONG ft = 0;
			hr = edm->Next(cnt - fetched, &dmArray[fetched], &ft);
			if (FAILED(hr)) {
				delete [] dmArray;
				return false;
			}
			fetched += ft;
		}
		
		for (ULONG i = 0; i < cnt; i++)
		{
			Mago::Module* mod = (Mago::Module*)dmArray[i];
			//Mago::Module* mod = reinterpret_cast<Mago::Module*>(it->second.Get());

			RefPtr<MagoST::ISession> session;
			if (!mod->GetSymbolSession(session))
				continue;

			std::list<MagoST::LineNumber> lines;
			if (!session->FindLines(exactMatch, fileName, fileNameLen, reqLineStart, reqLineEnd, lines))
				continue;

			for (std::list<MagoST::LineNumber>::iterator it = lines.begin(); it != lines.end(); ++it)
			{
				bindings.push_back(AddressBinding());
				bindings.back().Addr = session->GetVAFromSecOffset(it->Section, it->Offset);
				bindings.back().Mod = mod;
			}
		}

		delete [] dmArray;

		return bindings.size() > 0;
    }

    bool SymbolResolver::InternalGetLineByAddress( 
		ULONG64 address,
		const wchar_t ** fileName, 
        WORD* fileNameLen, 
		uint16_t* lineNum)
    {
		CComModule _Module;
		Mago::Program* prog = mDebuggee->GetProgram();
		IEnumDebugModules2* edm = NULL;
		HRESULT hr = prog->EnumModules(&edm);
		if (FAILED(hr))
			return false;

		ULONG cnt;
		hr = edm->GetCount(&cnt);
		if (FAILED(hr))
			return false;

		IDebugModule2** dmArray = new IDebugModule2*[cnt];
		ULONG fetched = 0;
		while (fetched < cnt)
		{
			ULONG ft = 0;
			hr = edm->Next(cnt - fetched, &dmArray[fetched], &ft);
			if (FAILED(hr)) {
				delete [] dmArray;
				return false;
			}
			fetched += ft;
		}

		bool found = false;
		for (ULONG i = 0; i < cnt; i++)
		{
			Mago::Module* mod = (Mago::Module*)dmArray[i];
			//Mago::Module*  mod =  reinterpret_cast<Mago::Module*>(it->second.Get());

            RefPtr<MagoST::ISession>    session;
            uint32_t compCount = 0;

			if ( !mod->Contains(address))
				continue;

            if ( !mod->GetSymbolSession( session ) )
                break;

			uint16_t    sec = 0;
			uint32_t    offset = 0;
			sec = session->GetSecOffsetFromVA( address, offset );
			if ( sec == 0 )
				continue;

			MagoST::LineNumber line = { 0 };
			if ( !session->FindLine( sec, offset, line ) )
				continue;

			MagoST::FileInfo    fileInfo = { 0 };
			hr = session->GetFileInfo( line.CompilandIndex, line.FileIndex, fileInfo );
			if ( FAILED( hr ) )
				continue;

			BSTR bstrFileName = L"";
			hr = Utf8To16( fileInfo.Name.ptr, fileInfo.Name.length, bstrFileName );
			if ( FAILED( hr ) )
				continue;

			*lineNum = line.Number;
			*fileName = bstrFileName;
			*fileNameLen = fileInfo.Name.length;

			found =  true;
			break;
		}

		delete [] dmArray;
		return found;
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

        hr = Utf8To16( fileInfo.Name.ptr, fileInfo.Name.length, info.Filename.m_str );
        if ( FAILED( hr ) )
            return hr;

        info.LangName = L"D";
        info.LangGuid = GetDLanguageId();

        return hr;
    }

}