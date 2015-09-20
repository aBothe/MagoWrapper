#pragma once

#include <map>
//
#include "..\Exec\Types.h"
//#include "..\Exec\Exec.h"
//#include "..\Exec\EventCallback.h"

#include "..\..\CVSym\CVSTI\CVSTI.h"
#include "..\..\CVSym\CVSym\CVSymPublic.h"
//#include "..\..\CVSym\CVSym\cvconst.h"

#include "..\MagoNatDE\Utility.h"
#include "..\MagoNatDE\Module.h"
#include "..\MagoNatDE\StackFrame.h"
#include "..\MagoNatDE\Thread.h"

namespace MagoWrapper
{

		typedef std::map< Mago::Address64, Mago::Module* > ModuleMap;
		typedef std::map< DWORD, Mago::Thread* > ThreadMap;

        struct StackLineInfo
        {
            CComBSTR        Filename;
            Address         Address;
            TEXT_POSITION   LineBegin;
            TEXT_POSITION   LineEnd;
            CComBSTR        LangName;
            GUID            LangGuid;
        };
}