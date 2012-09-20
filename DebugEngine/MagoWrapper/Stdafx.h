// stdafx.h : Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.

#pragma once


// VS Debug
#include <msdbg.h>

// Magus
#include <SmartPtr.h>
#include <Guard.h>

// Debug Exec
#include "..\Exec\Types.h"
#include "..\Exec\Enumerator.h"
#include "..\Exec\Error.h"
#include "..\Exec\Exec.h"
#include "..\Exec\Machine.h"
#include "..\Exec\EventCallback.h"
#include "..\Exec\MakeMachineX86.h"
#include "..\Exec\IProcess.h"
#include "..\Exec\Thread.h"
#include "..\Exec\IModule.h"

// Debug Symbol Table
#include "..\CVSTI\CVSTI.h"

