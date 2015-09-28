#pragma once

#include "..\..\CVSym\CVSTI\CVSTI.h"
//#include "..\..\CVSym\CVSym\CVSymPublic.h"
//#include "..\..\CVSym\CVSym\cvconst.h"

#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\ExprContext.h"

#include "Types.h"
#include "Debuggee.h"

using namespace System;
using namespace System::Collections::Generic;

namespace MagoWrapper
{
	/*
	 * A generic debugger for native executables.
	 */

    struct AddressBinding
    {
        uint64_t        Addr;
        RefPtr<Mago::Module>  Mod;
    };

	public ref struct DebugScopedSymbol
	{
	public:
		String^ Name;
		String^ TypeName;
		String^ TextValue;
		String^ FullName;
		ULONG Size;
		bool HasChildren;


		~DebugScopedSymbol();
	internal:
		int mPtrSize;

		DebugScopedSymbol(
			String^ name, 
			String^ typeName, 
			String^ textValue, 
			String^ fullName, 
			ULONG size,
			bool hasChildren);

	};

	public ref class SymbolResolver
	{
	public:
		SymbolResolver(Debuggee^ debuggee, int ptrSize);
		~SymbolResolver();

		ULONG64 GetAddressFromCodeLine(
			String^ str, 
			uint16_t line); 
		bool GetCodeLineFromAddress(
			ULONG64 address,
			[Runtime::InteropServices::Out] String^ %File,
			[Runtime::InteropServices::Out] ULONG %Line);


		List<DebugScopedSymbol^>^ GetLocalSymbols(DWORD threadId);
		List<DebugScopedSymbol^>^ GetLocalSymbols(DWORD threadId, Address frameAddress);
		List<DebugScopedSymbol^>^ GetChildSymbols(String^ expression, DWORD threadId);
		DebugScopedSymbol^ Evaluate(String^ expression, DWORD threadId);

	internal:

	private:

		Debuggee^ mDebuggee;
		int mPtrSize;

		HRESULT EnumerateLocalSymbols(ULONG64 address, DWORD threadId, List<DebugScopedSymbol^>^ list);

		bool InternalGetAddressesByLine(
			bool exactMatch, 
			const char* fileName, 
			size_t fileNameLen, 
			uint16_t reqLineStart, 
			uint16_t reqLineEnd,
			std::list<AddressBinding>& bindings );

		bool InternalGetLineByAddress( 
			ULONG64 address,
			const wchar_t** fileName, 
			WORD* fileNameLen, 
			uint16_t* lineNum);

		HRESULT EvaluateExpression(String^ expression, DWORD threadId, IDebugProperty2** dp);

		HRESULT SymbolResolver::GetStackLineInfo(
			uintptr_t address,
			Mago::Module* module,
			StackLineInfo& info );

	};

}