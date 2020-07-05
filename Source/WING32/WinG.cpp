#include "pch.h"
#include "WinG.h"

Ext HDC WINGAPI WinGCreateDC(void)
{
	return CreateCompatibleDC(NULL);
}

Ext BOOL WINGAPI WinGRecommendDIBFormat(BITMAPINFO* pHeader)
{
	if (!pHeader) return FALSE;

	HDC screen = GetDC(NULL);

	pHeader->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pHeader->bmiHeader.biWidth = 320;
#if(WINVER < 0x0600) //If Windows version is less than Windows Vista
	pHeader->bmiHeader.biHeight = 1;
#else
	pHeader->bmiHeader.biHeight = -1;
#endif
	pHeader->bmiHeader.biPlanes = 1;
	pHeader->bmiHeader.biBitCount = 8;
	pHeader->bmiHeader.biCompression = BI_RGB;
	pHeader->bmiHeader.biSizeImage = 0;
	pHeader->bmiHeader.biXPelsPerMeter = 0;
	pHeader->bmiHeader.biYPelsPerMeter = 0;
	pHeader->bmiHeader.biClrUsed = 0;
	pHeader->bmiHeader.biClrImportant = 0;

	return TRUE;
}

Ext HBITMAP WINGAPI WinGCreateBitmap(HDC WinGDC, BITMAPINFO* pHeader, void** ppBits)
{
	return CreateDIBSection(WinGDC, pHeader, DIB_RGB_COLORS, ppBits, 0, 0);
}

Ext void* WINGAPI WinGGetDIBPointer(HBITMAP WinGBitmap,	BITMAPINFO* pHeader)
{
	DIBSECTION ds;

	ZeroMemory(&ds, sizeof(ds));

	if (GetObject(WinGBitmap, sizeof(ds), &ds) == sizeof(ds))
	{
		pHeader->bmiHeader = ds.dsBmih;
		return ds.dsBm.bmBits;
	}
	return NULL;
}

Ext UINT WINGAPI WinGGetDIBColorTable(HDC WinGDC, UINT StartIndex, UINT NumberOfEntries, RGBQUAD* pColors)
{
	return GetDIBColorTable(WinGDC, StartIndex, NumberOfEntries, pColors);
}

Ext UINT WINGAPI WinGSetDIBColorTable(HDC WinGDC, UINT StartIndex, UINT NumberOfEntries, const RGBQUAD* pColors)
{
		return SetDIBColorTable(WinGDC, StartIndex, NumberOfEntries, pColors);
}

Ext HPALETTE WINGAPI WinGCreateHalftonePalette(void)
{
	HDC WinGDC = GetDC(NULL);
	HPALETTE hPal = CreateHalftonePalette(WinGDC);

	ReleaseDC(NULL, WinGDC);

	return hPal;
}

Ext HBRUSH WINGAPI WinGCreateHalftoneBrush(HDC Context, COLORREF crColor, INT DitherType)
{
	return CreateSolidBrush(crColor);
}

Ext BOOL WINGAPI WinGBitBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc)
{
	return BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, SRCCOPY);
}

Ext BOOL WINGAPI WinGStretchBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc)
{
	INT mode = SetStretchBltMode(hdcDest, COLORONCOLOR);
	BOOL ret = StretchBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, SRCCOPY);
	SetStretchBltMode(hdcDest, mode);
	return ret;
}