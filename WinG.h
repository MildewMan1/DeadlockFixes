#pragma once
#ifndef WING_H
#define WING_H

#define WINGAPI WINAPI

#ifdef WINGREPLACEMENT_EXPORTS
#define Ext extern "C" __declspec(dllexport) 
#else
#define Ext extern "C" __declspec(dllimport) 
#endif


Ext HDC WINGAPI WinGCreateDC(void);
Ext BOOL WINGAPI WinGRecommendDIBFormat(BITMAPINFO* pHeader);
Ext HBITMAP WINGAPI WinGCreateBitmap(HDC WinGDC, BITMAPINFO* pHeader, void** ppBits);
Ext void* WINGAPI WinGGetDIBPointer(HBITMAP WinGBitmap, BITMAPINFO* pHeader);
Ext UINT WINGAPI WinGGetDIBColorTable(HDC WinGDC, UINT StartIndex, UINT NumberOfEntries, RGBQUAD* pColors);
Ext UINT WINGAPI WinGSetDIBColorTable(HDC WinGDC, UINT StartIndex, UINT NumberOfEntries, const RGBQUAD* pColors);
Ext HPALETTE WINGAPI WinGCreateHalftonePalette(void);
Ext HBRUSH WINGAPI WinGCreateHalftoneBrush(HDC Context, COLORREF crColor, INT DitherType);
Ext BOOL WINGAPI WinGBitBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc);
Ext BOOL WINGAPI WinGStretchBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc);

#endif