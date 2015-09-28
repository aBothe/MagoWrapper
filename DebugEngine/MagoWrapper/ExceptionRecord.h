#pragma once


//#include "..\Exec\Types.h"
//#include "..\Exec\IProcess.h"

#include "..\..\CVSym\CVSym\CVSymPublic.h"

#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\DRuntime.h"

//#include "DRuntime.h"

using namespace System;

namespace MagoWrapper{

	public ref class ExceptionRecord
	{
	public:
		property String^ RootExceptionName
		{
			String^ get();
		}

		property String^ ExceptionName
		{
			String^ get();
		}

		property String^ ExceptionInfo
		{
			String^ get();
		}

		property DWORD ExceptionCode { 
		   DWORD get();
		}

		property DWORD ExceptionFlags { 
		   DWORD get();
		}

		property PVOID ExceptionAddress { 
		   PVOID get();
		}

		property ExceptionRecord^ InnerExceptionRecord {
			ExceptionRecord^ get();
		}
	internal:
		ExceptionRecord();
		void Init(Mago::DRuntime* druntime, const EXCEPTION_RECORD64* exceptionRec);

	private:
		String^ mRootExceptionName;
		String^ mExceptionName;
		String^ mExceptionInfo;
		DWORD mNumberParameters;
		DWORD mExceptionCode;
		DWORD mExceptionFlags;
		PVOID mExceptionAddress;
		ExceptionRecord^ mInnerException;
	};
	
}