#include "stdafx.h"
#include <crtdbg.h>

#include "..\Exec\Types.h"
#include "..\Exec\IProcess.h"
#include "..\Exec\IProcess.h"
#include "..\Exec\Process.h"
//#include "..\Exec\Utility.h"
//#include "..\Exec\Machine.h"
//#include "..\Exec\MachineX86.h"

//#include "..\..\CVSym\CVSTI\CVSTI.h"
#include "..\..\CVSym\CVSym\CVSymPublic.h"
//#include "..\..\CVSym\CVSym\cvconst.h"


#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\ICoreProcess.h"
#include "..\MagoNatDE\DebuggerProxy.h"
#include "..\MagoNatDE\Program.h"

#include "NativeDebugger.h"

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
		//need a better way to get pointer size
		return gcnew SymbolResolver(debuggee, 4);
	}

	void NativeDebugger::LaunchExecutable(String^ cmdLine, String^ dir, Debuggee^ debuggee)
	{
		CComModule _Module;
		debuggee->SetDebuggerProxy(new Mago::DebuggerProxy());

		RefPtr<Mago::Program> prog;
		HRESULT hr = MakeCComObject(prog);
		if (FAILED(hr))
			throw gcnew System::Exception("Error launching Executable" + hr.ToString());

		hr = debuggee->GetDebuggerProxy()->Init(debuggee->mEventCallback);

		debuggee->GetDebuggerProxy()->Start();

		LaunchInfo  info = { 0 };
		//IProcess* proc = NULL;
		RefPtr<Mago::ICoreProcess> proc;

		pin_ptr<const wchar_t> strCmdLine = PtrToStringChars(cmdLine);
		info.CommandLine = strCmdLine;
		info.Exe = strCmdLine; 
		pin_ptr<const wchar_t> strDir = PtrToStringChars(dir);
		info.Dir = strDir;
		info.EnvBstr = L"";
		info.Suspend = false;
		info.NewConsole = false;
		hr = debuggee->GetDebuggerProxy()->Launch(&info, proc.Ref());
		if (FAILED(hr)) 
			throw gcnew System::Exception("Error launching Executable" + hr.ToString());

		prog->SetCoreProcess(proc);
		prog->SetDebuggerProxy(debuggee->GetDebuggerProxy());
		debuggee->SetProgram(prog);

	}

}