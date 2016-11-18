#include "stdafx.h"

DWORD Offsets::HOOKPOS_EndWorldColors = NULL;
DWORD Offsets::HOOKPOS_CWorld_ProcessVerticalLineSectorList = NULL;

void Offsets::Initialize10EU(void)
{
	InitializeCommon10();
}

void Offsets::Initialize10US(void)
{
	InitializeCommon10();
}

void Offsets::InitializeCommon10(void)
{
	HOOKPOS_EndWorldColors = 0x561795;
	HOOKPOS_CWorld_ProcessVerticalLineSectorList = 0x563357;
}