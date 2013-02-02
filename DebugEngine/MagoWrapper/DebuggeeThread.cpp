#include "Stdafx.h"
#include "DebuggeeThread.h"


namespace MagoWrapper
{

	DebuggeeThread::DebuggeeThread(uint32_t threadId)
	{
		mThreadId = threadId;
	}

	uint32_t DebuggeeThread::ThreadId::get()
	{
		return mThreadId;
	}


}
