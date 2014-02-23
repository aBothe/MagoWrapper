#include "Stdafx.h"
#include "ExceptionRecord.h"

namespace MagoWrapper
{
	ExceptionRecord::ExceptionRecord(IProcess* process, const EXCEPTION_RECORD* exceptionRec)
	{
		mProcess = process;
		mExceptionRecord = exceptionRec;
		mInnerExceptionRecord = nullptr;

		if (mExceptionRecord->ExceptionRecord)
			mInnerExceptionRecord = gcnew ExceptionRecord(process, mExceptionRecord->ExceptionRecord);
	}

	String^ ExceptionRecord::ExceptionName::get()
	{
		CComBSTR exceptionName = NULL;		
		HRESULT hr = GetClassName2(mProcess, mExceptionRecord->ExceptionInformation[0], &exceptionName);
		if ( FAILED(hr) )
			exceptionName = "";

		if (exceptionName == NULL)
			exceptionName = L"D Exception";

		return gcnew String(exceptionName.m_str);

	}

	String^ ExceptionRecord::ExceptionInfo::get()
	{
		CComBSTR exceptionInfo = NULL;
		
		HRESULT hr = GetExceptionInfo(mProcess, mExceptionRecord->ExceptionInformation[0], &exceptionInfo);
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
		return mExceptionRecord->ExceptionAddress;
	}

	ExceptionRecord^ ExceptionRecord::InnerExceptionRecord::get()
	{
		return mInnerExceptionRecord;
	}
}