#include "Stdafx.h"
#include "ExceptionRecord.h"

namespace MagoWrapper
{
	ExceptionRecord::ExceptionRecord(Mago::DRuntime* druntime, const EXCEPTION_RECORD64* exceptionRec)
	{
		mDRuntime = druntime;
		//mProcess = process;
		mExceptionRecord = exceptionRec;
		mInnerExceptionRecord = nullptr;

		if (mExceptionRecord->ExceptionRecord)
			mInnerExceptionRecord = gcnew ExceptionRecord(druntime, (const EXCEPTION_RECORD64*)mExceptionRecord->ExceptionRecord);
	}

	String^ ExceptionRecord::ExceptionName::get()
	{
		CComBSTR exceptionName = NULL;		
		HRESULT hr = mDRuntime->GetClassName(mExceptionRecord->ExceptionInformation[0], &exceptionName);
		if ( FAILED(hr) )
			exceptionName = "";

		if (exceptionName == NULL)
			exceptionName = L"D Exception";

		return gcnew String(exceptionName.m_str);

	}

	String^ ExceptionRecord::ExceptionInfo::get()
	{
		CComBSTR exceptionInfo = NULL;
		
		HRESULT hr = mDRuntime->GetExceptionInfo(mExceptionRecord->ExceptionInformation[0], &exceptionInfo);
		if ( FAILED(hr) )
			exceptionInfo = "";

		return gcnew String(exceptionInfo.m_str);
	}

	DWORD ExceptionRecord::ExceptionCode::get()
	{
		return mExceptionRecord->ExceptionCode;
	}

	DWORD ExceptionRecord::ExceptionFlags::get()
	{
		return mExceptionRecord->ExceptionFlags;
	}

	PVOID ExceptionRecord::ExceptionAddress::get()
	{
		return (PVOID)mExceptionRecord->ExceptionAddress;
	}

	ExceptionRecord^ ExceptionRecord::InnerExceptionRecord::get()
	{
		return mInnerExceptionRecord;
	}
}