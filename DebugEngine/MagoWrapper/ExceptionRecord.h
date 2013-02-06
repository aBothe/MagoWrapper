#pragma once

using namespace System;

namespace MagoWrapper{

	public ref class ExceptionRecord
	{
	public:
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
		ExceptionRecord(IProcess* process, const EXCEPTION_RECORD* exceptionRec);

	private:
		IProcess* mProcess;
		const EXCEPTION_RECORD* mExceptionRecord;
		ExceptionRecord^ mInnerExceptionRecord;
	};
	
}