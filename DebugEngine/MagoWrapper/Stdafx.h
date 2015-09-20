// stdafx.h : Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.

#pragma once

#include <string>
#include <list>
#include <map>

#include <vcclr.h>
#include <vector>
#include <map>
#include <memory>
#include <basetsd.h>

#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <atlstr.h>

using namespace ATL;

// VS Debug
#include <msdbg.h>

// Boost
#include <boost/shared_ptr.hpp>

// Magus
#include <crtdbg.h>
#include <SmartPtr.h>
#include <Guard.h>
#include <stdint.h>


#if defined(_M_CEE) // this is defined when /clr flag is used

#if !defined(GetClassName)
#ifdef UNICODE
#define GetClassName GetClassNameW
#else
#define GetClassName GetClassNameA
#endif // !UNICODE
#endif

#endif

// CVSym
//#include "..\..\CVSym\CVSTI\CVSTI.h"
#include "..\..\CVSym\CVSym\CVSymPublic.h"
//#include "..\..\CVSym\CVSym\cvconst.h"

// Debug Exec
#include "..\Exec\Types.h"
#include "..\Exec\Enumerator.h"
//#include "..\Exec\Error.h"
#include "..\Exec\Exec.h"
//#include "..\Exec\Utility.h"
////#include "..\Exec\Machine.h"
////#include "..\Exec\MakeMachineX86.h"
#include "..\Exec\EventCallback.h"
//#include "..\Exec\IProcess.h"
//#include "..\Exec\Process.h"
//#include "..\Exec\Thread.h"
//#include "..\Exec\IModule.h"
//#include "..\Exec\Module.h"
//#include "..\Exec\DebuggerProxy.h"

//MagoNATEE
//#include "..\..\EED\EED\EE.h"
//#include "..\..\EED\EED\Type.h"
//#include "..\..\EED\Real\Complex.h"
//#include "..\..\EED\EED\Eval.h"
//#include "..\..\EED\EED\Declaration.h"
//#include "..\..\EED\EED\FormatValue.h"
//#include "..\..\EED\EED\FormatValue.h"
//#include "..\..\EED\MagoNatEE\MagoNatEE.h"


// MagoNatDE
//#include "..\MagoNatDE\Common.h"
//#include "..\MagoNatDE\Config.h"
////#include "..\MagoNatDE\Utility.h"
//#include "..\MagoNatDE\ExprContext.h"
//#include "..\MagoNatDE\StackFrame.h"
//#include "..\MagoNatDE\DebuggerProxy.h"
//#include "..\MagoNatDE\Expr.h"
//#include "..\MagoNatDE\Module.h"
//#include "..\MagoNatDE\CVDecls.h"
//#include "..\MagoNatDE\RegisterSet.h"
//#include "..\MagoNatDE\winternl2.h"
//#include "..\MagoNatDE\Program.h"

//#include "..\MagoNatDE\EventCallback.h"

// Unit Tests
//#include "..\UnitTests\utestExec\Utility.h"
//#include "..\UnitTests\utestExec\EventCallbackBase.h"

