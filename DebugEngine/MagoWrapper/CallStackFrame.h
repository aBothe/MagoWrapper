#pragma once

namespace MagoWrapper
{
	public ref struct CallStackFrame
	{
		Address InstructionPointer;
		Address BasePointer;
	};
		
}