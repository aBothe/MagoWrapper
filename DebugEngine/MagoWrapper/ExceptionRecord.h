#pragma once

namespace MagoWrapper{

	public ref class ExceptionRecord
	{
	public:
		ExceptionRecord(DWORD exceptionCode, DWORD exceptionFlags, PVOID exceptionAddress)
		{
			this->exceptionCode = exceptionCode;
			this->exceptionFlags = exceptionFlags;
			this->exceptionAddress = exceptionAddress;
		}

		property DWORD ExceptionCode { 
		   public: DWORD get() { return exceptionCode; }
		   //private: void set(DWORD value) { exceptionCode = value; }
		}

		property DWORD ExceptionFlags { 
		   public: DWORD get() { return exceptionFlags; }
		   //private: void set(DWORD value) { exceptionCode = value; }
		}

		property PVOID ExceptionAddress { 
		   public: PVOID get() { return exceptionAddress; }
		   //private: void set(DWORD value) { exceptionCode = value; }
		}

	private:
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