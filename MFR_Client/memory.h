#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>

#define     MAX_JUMPCODE_SIZE           20

template < class T, class U >
void MemPut(U ptr, const T value)
{
	if (*(T*)ptr != value)
		memcpy((void*)ptr, &value, sizeof(T));
}

template < class T, class U >
void MemPutFast(U ptr, const T value)
{
	*(T*)ptr = value;
}

void SetInitialVirtualProtect(void);
bool HookInstall(DWORD dwInstallAddress, DWORD dwHookHandler, int iJmpCodeSize);
BYTE * CreateJump(DWORD dwFrom, DWORD dwTo, BYTE * ByteArray);
////////////////////////////////////////////////////////////////////

int	memcpy_safe(void *dest, const void *src, uint32_t len, int check = NULL, const void *checkdata = NULL);
int	memset_safe(void *_dest, int c, uint32_t len);
int	memcmp_safe(const void *_s1, const void *_s2, uint32_t len);

// Auto detect requirement of US/EU hook installation
#define EZHookInstall(type) \
        __if_not_exists( RETURN_##type##_US ) \
        { \
            HookInstall( HOOKPOS_##type, (DWORD)HOOK_##type, HOOKSIZE_##type ) \
        } \
        __if_exists( RETURN_##type##_US ) \
        { \
            if ( FindGameVersion () == VERSION_US_10 ) \
            { \
                EZHookInstall_HERE( type, US ) \
            } \
            else \
            { \
                EZHookInstall_HERE( type, EU ) \
            } \
        }


// US/EU hook installation
// Includes additional return pointer copies if required
#define EZHookInstall_HERE(type,CO) \
        HookInstall( HOOKPOS_##type##_##CO##, (DWORD)HOOK_##type, HOOKSIZE_##type##_##CO## ); \
        RETURN_##type##_BOTH = RETURN_##type##_##CO##; \
        __if_exists( RETURN_##type##B_##CO## ) \
        { \
            RETURN_##type##B_BOTH = RETURN_##type##B_##CO##; \
        } \
        __if_exists( RETURN_##type##C_##CO## ) \
        { \
            RETURN_##type##C_BOTH = RETURN_##type##C_##CO##; \
        }


// Structure for holding hook info
struct SHookInfo
{
	template < class T > SHookInfo(DWORD dwAddress, T dwHook, uint32_t uiSize) : dwAddress(dwAddress), dwHook((DWORD)dwHook), uiSize(uiSize) {}
	DWORD dwAddress;
	DWORD dwHook;
	uint32_t uiSize;
};

#define MAKE_HOOK_INFO(type)  SHookInfo ( HOOKPOS_##type, HOOK_##type, HOOKSIZE_##type )


// Structure for holding poke info
struct SPokeInfo
{
	DWORD dwAddress;
	BYTE ucValue;
};