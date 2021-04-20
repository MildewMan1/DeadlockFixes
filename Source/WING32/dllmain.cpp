#include "framework.h"
#include <assert.h>

//Microsoft Detours header files - must download Detours lib from Microsoft.
#include <detours.h>
#include <detver.h>
#include <syelog.h>

#include "CrashFixCode.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        assert(false);
        DisableThreadLibraryCalls(hModule);
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        //use Microsoft Detours to detour CreateWindowExA to our custom version.
        assert(DetourAttach(&(PVOID&)realCreateWindowExA, myCreateWindowExA) == NO_ERROR);

        DetourTransactionCommit();

        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        //Detach detour when DLL is unloaded.
        DetourDetach(&(PVOID&)realCreateWindowExA, myCreateWindowExA);

        DetourTransactionCommit();
        break;
    }
    return TRUE;
}
