#pragma once

using namespace System;

namespace MagoWrapper{

	public ref class ExceptionRecord
	{
	public:
		ExceptionRecord(String^ exceptionName, String^ exceptionInfo, DWORD exceptionCode, DWORD exceptionFlags, PVOID exceptionAddress)
		{
			this->exceptionName = gcnew String(exceptionName);
			this->exceptionInfo = gcnew String(exceptionInfo);
			this->exceptionCode = exceptionCode;
			this->exceptionFlags = exceptionFlags;
			this->exceptionAddress = exceptionAddress;
		}

		property String^ ExceptionName
		{
			String^ get() { return exceptionName; }
		}

		property String^ ExceptionInfo
		{
			String^ get() { return exceptionInfo; }
		}

		property DWORD ExceptionCode { 
		   DWORD get() { return exceptionCode; }
		}

		property DWORD ExceptionFlags { 
		   DWORD get() { return exceptionFlags; }
		}

		property PVOID ExceptionAddress { 
		   PVOID get() { return exceptionAddress; }
		}

	private:
		String^ exceptionName;
		String^ exceptionInfo;
		DWORD exceptionCode;
		DWORD exceptionFlags;
		PVOID exceptionAddress;
	};
	
	//typedef struct _EXCEPTION_RECORD {
	//	DWORD    ExceptionCode;
	//	DWORD ExceptionFlags;
	//	struct _EXCEPTION_RECORD *ExceptionRecord;
	//	PVOID ExceptionAddress;
	//	DWORD NumberParameters;
	//	ULONG_PTR ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
	//	} E

}