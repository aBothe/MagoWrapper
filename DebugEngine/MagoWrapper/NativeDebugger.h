#pragma once

#include "Types.h"
#include "Debuggee.h"
#include "SymbolResolver.h"

using namespace System;
using namespace System::Collections::Generic;
using MagoCore::DebuggerProxy;

namespace MagoWrapper
{
	/*
	 * A generic debugger for native executables.
	 */


	public ref class NativeDebugger
	{
	public:
		NativeDebugger(void);
		~NativeDebugger(void);

		SymbolResolver^ CreateSymbolResolver(Debuggee^ debuggee);

		void LaunchExecutable(String^ cmdLine, String^ dir, Debuggee^ debuggee);
	private:
		Mago::Engine* mEngine;
	};
}