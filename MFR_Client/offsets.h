#pragma once

class Offsets
{
public:
	static void Initialize10EU(void);
	static void Initialize10US(void);
	static void InitializeCommon10(void);

	static DWORD HOOKPOS_EndWorldColors;
	static DWORD HOOKPOS_CWorld_ProcessVerticalLineSectorList ;
};