#pragma once

using namespace System;

namespace MagoWrapper
{
	public ref struct CallStackFrame
	{
		Address InstructionPointer;
		//Address BasePointer;
		UINT64 AddressMin;
		UINT64 AddressMax;
		String^ FunctionName;
		String^ ReturnType;
		String^ Args;
		String^ Language;
	};
		
}