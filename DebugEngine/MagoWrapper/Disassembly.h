#pragma once

#include "Stdafx.h"

using namespace System;
using namespace System::Collections::Generic;

namespace MagoWrapper
{
	public ref class DisassemblyData
	{
	private:
		::Address address;
		String^ opCode;
		uint32_t codeLocation; 
		String^ documentUrl;
		String^ symbol;

	public:
		property ::Address Address
		{
			::Address get(){ return address; };
		}
		property String^ OpCode
		{
			String^ get(){ return opCode; };
		}
		property uint32_t CodeLocation
		{
			uint32_t get(){ return codeLocation; };
		}
		property String^ DocumentUrl
		{
			String^ get(){ return documentUrl; };
		}
		property String^ Symbol
		{
			String^ get(){ return symbol; };
		}

	internal:
		DisassemblyData(::Address address, String^ opCode, uint32_t codeLocation, String^ documenetUrl, String^ symbol)
		{
			this->address = address;
			this->opCode = opCode;
			this->codeLocation = codeLocation;
			this->documentUrl = documentUrl;
			this->symbol = symbol;
		}

	};

}