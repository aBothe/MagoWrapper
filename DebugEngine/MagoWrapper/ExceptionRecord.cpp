#include "Stdafx.h"
#include "ExceptionRecord.h"

namespace MagoWrapper
{
	ExceptionRecord::ExceptionRecord()
	{}
	
	void ExceptionRecord::Init(Mago::DRuntime* druntime, const EXCEPTION_RECORD64* exceptionRec)
	{
		mInnerException = nullptr;

		CComBSTR exceptionName;
		CComBSTR exceptionInfo = NULL;
		wchar_t name[100] = L"";
		static const DWORD  DExceptionCode = 0xE0440001;
		if (exceptionRec->ExceptionCode == DExceptionCode)
		{
			mRootExceptionName = "D Exceptions";
			druntime->GetClassName(exceptionRec->ExceptionInformation[0], &exceptionName);
			druntime->GetExceptionInfo(exceptionRec->ExceptionInformation[0], &exceptionInfo);

			if (exceptionName == NULL)
				exceptionName = L"D Exception";
		}
		else
		{
			mRootExceptionName = "Win32 Exceptions";
			// make it a Win32 exception
			swprintf_s(name, L"%08x", exceptionRec->ExceptionCode);
			exceptionName = name;
		}
		mExceptionName = gcnew String(exceptionName.m_str);
		mExceptionInfo = gcnew String(exceptionInfo.m_str);
		mNumberParameters = exceptionRec->NumberParameters;
		mExceptionCode = exceptionRec->ExceptionCode;
		mExceptionFlags = exceptionRec->ExceptionFlags;
		mExceptionAddress = (PVOID)exceptionRec->ExceptionAddress;

		if (exceptionRec->ExceptionRecord)
		{
			mInnerException = gcnew ExceptionRecord();
			mInnerException->Init(druntime, (const EXCEPTION_RECORD64*)exceptionRec->ExceptionRecord);
		}
		else
		{
			mInnerException = nullptr;
		}

	}

	String^ ExceptionRecord::RootExceptionName::get()
	{
		return mRootExceptionName;
	}

	String^ ExceptionRecord::ExceptionName::get()
	{
		return mExceptionName;
	}

	String^ ExceptionRecord::ExceptionInfo::get()
	{
		return mExceptionInfo;
	}

	DWORD ExceptionRecord::ExceptionCode::get()
	{
		return mExceptionCode;
	}

	DWORD ExceptionRecord::ExceptionFlags::get()
	{
		return mExceptionFlags;;
	}

	PVOID ExceptionRecord::ExceptionAddress::get()
	{
		return mExceptionAddress;
	}

	ExceptionRecord^ ExceptionRecord::InnerExceptionRecord::get()
	{
		return mInnerException;
	}
}