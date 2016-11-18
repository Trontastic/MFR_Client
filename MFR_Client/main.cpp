// MFR_Client.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

void Log(const char *fmt, ...)
{
	static FILE* flLog = NULL;
	SYSTEMTIME	time;
	va_list		ap;
	if (flLog == NULL)
	{
		flLog = fopen("MFR.log", "w");
		if (flLog == NULL)
			return;
	}
	GetLocalTime(&time);
	fprintf(flLog, "[%d.%d.%d %02d:%02d:%02d.%03d] ", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
	va_start(ap, fmt);
	vfprintf(flLog, fmt, ap);
	va_end(ap);
	fprintf(flLog, "\n");
	fflush(flLog);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			Log("MFR.asi: Attach");
			Hooks::Get()->Initialize();
		}
		case DLL_THREAD_ATTACH:
		{

		}
		case DLL_THREAD_DETACH:
		{

		}
		case DLL_PROCESS_DETACH:
		{
			//Hooks::Get()->UnInitialize();
		}
		break;
	}
	return TRUE;
}
