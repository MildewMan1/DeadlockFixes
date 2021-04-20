#pragma once
#ifndef CRASHFIX
#define CRASHFIX

#pragma comment(lib, "user32.lib") //where CreateWindowExA and GetSystemMetrics are defined.
#pragma comment(lib, "Kernel32.lib") //where lstrcmpA is defined.

//You will need to download the Detours library from Microsoft.
#pragma comment(lib, "detours.lib")

//function pointer typedef for CreateWindowExA
typedef HWND(WINAPI* pCreateWindowExA)(
	DWORD dwExStyle, 
	LPCSTR lpClassName, 
	LPCSTR lpWindowName, 
	DWORD dwStyle, 
	int X, 
	int Y, 
	int nWidth, 
	int nHeight, 
	HWND hWndParent, 
	HMENU hMenu, 
	HINSTANCE hInstance, 
	LPVOID lpParam
	);

//declare extern CreateWindowExA pointer.
extern pCreateWindowExA realCreateWindowExA;

//declare custom version of CreateWindowExA that will be used to detour the real version.
HWND WINAPI myCreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);

#endif //CRASHFIX