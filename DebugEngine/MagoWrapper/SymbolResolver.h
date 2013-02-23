#pragma once

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
		SymbolResolver(
			Debuggee^ debuggee);
		~SymbolResolver();

		ULONG64 GetAddressFromCodeLine(
			String^ str, 
			uint16_t line); 
		bool GetCodeLineFromAddress(
			ULONG64 address,
			[Runtime::InteropServices::Out] String^ %File,
			[Runtime::InteropServices::Out] ULONG %Line);

		String^ GetFunctionNameFromAddress(ULONG64 address, DWORD threadId);

		List<DebugScopedSymbol^>^ GetLocalSymbols(DWORD threadId);
		List<DebugScopedSymbol^>^ GetLocalSymbols(DWORD threadId, Address frameAddress);
		List<DebugScopedSymbol^>^ GetChildSymbols(String^ expression);
		DebugScopedSymbol^ Evaluate(String^ expression, DWORD threadId);

	internal:
        Guard* mModGuard;
        MagoEE::ITypeEnv* mTypeEnv;

		Guard* mExprContextGuard;

	private:
		Debuggee^ mDebuggee;

		HRESULT FindModuleContainingAddress(ULONG64 address, Mago::Module*& module);
		HRESULT EnumerateLocalSymbols(ULONG64 address, DWORD threadId, List<DebugScopedSymbol^>^ list);

		bool InternalGetAddressByLine( 
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

		HRESULT GetStackFrameName(
			uintptr_t address,
			DWORD threadId,
			Mago::Module* module,
			FRAMEINFO_FLAGS flags, 
			UINT radix, 
			BSTR* funcName );

		HRESULT AppendFunctionNameWithAddress( 
			uintptr_t address,
			Mago::Module* module,
			FRAMEINFO_FLAGS flags, 
			UINT radix, 
			CString& fullName );

		HRESULT AppendFunctionNameWithSymbols( 
			uintptr_t address,
			DWORD threadId,
			Mago::Module* module,
			FRAMEINFO_FLAGS flags, 
			UINT radix, 
			CString& fullName );

		HRESULT AppendFunctionNameWithSymbols( 
			uintptr_t address,
			DWORD threadId,
			Mago::Module* module,
			FRAMEINFO_FLAGS flags, 
			UINT radix,
			MagoST::ISession* session,
			MagoST::ISymbolInfo* symInfo, 
			MagoST::SymHandle& func,
			CString& fullName );

		HRESULT SymbolResolver::GetStackLineInfo(
			uintptr_t address,
			Mago::Module* module,
			StackLineInfo& info );

		HRESULT FindFunction(
			uintptr_t address, 
			Mago::Module* module, 
			MagoST::SymHandle& func,  
			MagoST::SymHandle& block);

		HRESULT AppendArgs(
			FRAMEINFO_FLAGS flags, 
			UINT radix, 
			uintptr_t address, 
			DWORD threadId,
			Mago::Module* module, 
			MagoST::ISession* session,
			MagoST::ISymbolInfo* symInfo,
			MagoST::SymHandle& func,
			CString& outputStr );

		HRESULT MakeExprContext(
			ULONG64 address, 
			DWORD threadId,
			Mago::Module* module, 
			Mago::IRegisterSet* regSet,
			MagoST::SymHandle& func,  
			MagoST::SymHandle& block,
			Mago::ExprContext*& exprCtx);

	};

}