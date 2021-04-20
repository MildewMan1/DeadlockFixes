#include <Windows.h>
#include "CrashFixCode.h"

//define CreateWindowExA pointer.
pCreateWindowExA realCreateWindowExA = CreateWindowExA;

HWND WINAPI myCreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
    LPCSTR mainWndClassName = "XenoMainWnd"; //Class name that Deadlock uses for its main window.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN); //get width of screen.
    int wndWidth = screenWidth + 2; //Deadlock adds 2 to the screen width when calling this function.
    BOOL bVersionCheck = FALSE; //will be set to True if the value of screenWidth is found at one of the 2 memory locations below.

    //Don't need to interfere with the call if screen width is <= 1280
    if (screenWidth > 1280 && wndWidth == nWidth && lstrcmpA(lpClassName, mainWndClassName) == 0)
    {
        //Check to see which version of DL1 this is.
        int* pScreenWidth131 = (int*)0x4DD8EC; //memory location of global screenWidth variable for DL1 v1.31.
        int* pScreenWidth120 = (int*)0x4DB704; //memory location of global screenWidth variable for DL1 v1.20.
        
        if (*pScreenWidth131 == screenWidth)
        {
            *pScreenWidth131 = 1280; //overwrite the screenWidth in the game.
            bVersionCheck = TRUE;
        }
        else if (*pScreenWidth120 == screenWidth)
        {
            *pScreenWidth120 = 1280; //overwrite the screenWidth in the game.
            bVersionCheck = TRUE;
        }

        if (bVersionCheck)
        {
            //only overwrite the value of nWidth if the screenWidth memory location for DL was changed.
            //if it wasn't found, then this version of Deadlock is not supported.
            nWidth = 1280;
        }
    }

    //call the real CreateWindowExA and return its value to the caller.
    return realCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle,
        X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}