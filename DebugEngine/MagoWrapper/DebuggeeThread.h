#pragma once

//#include <stdint.h>

namespace MagoWrapper
{
	public ref class DebuggeeThread
	{
	public:
		property uint32_t ThreadId
		{
			uint32_t get();
		}
	internal:
		DebuggeeThread(uint32_t threadId);

	private:
		uint32_t mThreadId;


	};
}