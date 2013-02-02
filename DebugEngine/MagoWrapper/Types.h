#pragma once

#include <map>

namespace MagoWrapper
{

		typedef std::map< Address, RefPtr<Mago::Module> > ModuleMap;
		//typedef std::map< DWORD, RefPtr<Mago::Thread> > ThreadMap;

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