// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstdint>

// TODO: reference additional headers your program requires here
#include "ini.h"
#include "INIReader.h"

#include "main.h"
#include "memory.h"
#include "hooks.h"
#include "CSingleton.h"
#include "settings.h"
#include "offsets.h"