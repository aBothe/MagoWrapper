#include "stdafx.h"
#include "NativeDebugger.h"
#include <crtdbg.h>

namespace MagoWrapper{

	NativeDebugger::NativeDebugger(void)
	{
		//Can remove this line after figuring out the problem with "~" in the watch list window .e.g. [str ~ "a"], comes from eval.cpp
		_CrtSetReportMode(_CRT_ASSERT, 0);
	}

	NativeDebugger::~NativeDebugger(void)
	{

	}

	SymbolResolver^ NativeDebugger::CreateSymbolResolver(Debuggee^ debuggee)
	{
		return gcnew SymbolResolver(debuggee);
	}

	void NativeDebugger::LaunchExecutable(String^ cmdLine, String^ dir, Debuggee^ debuggee)
	{
		RefPtr<IMachine> machine;
		HRESULT hr = MakeMachineX86( machine.Ref() );
		if ( FAILED( hr ) )
			throw "MakeMachineX86 failed.";

		debuggee->SetDebuggerProxy(new DebuggerProxy());

		hr = debuggee->GetDebuggerProxy()->Init(machine.Get(), debuggee->mEventCallback);

		debuggee->GetDebuggerProxy()->Start();

		LaunchInfo  info = { 0 };
		IProcess* proc = NULL;

		pin_ptr<const wchar_t> strCmdLine = PtrToStringChars(cmdLine);
		info.CommandLine = strCmdLine;
		info.Exe = strCmdLine; 
		pin_ptr<const wchar_t> strDir = PtrToStringChars(dir);
		info.Dir = strDir;
		info.EnvBstr = L"";
		info.Suspend = false;
		info.NewConsole = false;

		hr = debuggee->GetDebuggerProxy()->Launch(&info, proc);
		if (FAILED(hr)) 
			throw gcnew System::Exception("Error launching Executable" + hr.ToString());
	}



}