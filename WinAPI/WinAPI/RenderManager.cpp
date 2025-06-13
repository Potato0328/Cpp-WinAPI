#include "RenderManager.h"

void RenderManager::Start(HWND hWnd)
{
	this->hWnd = hWnd;
	
	// 윈도우 화면 사이즈 확인
	RECT rect;
	GetWindowRect(hWnd, &rect);
	this->winSizeX = rect.right - rect.left;
	this->winSizeY = rect.bottom - rect.top;

	this->hDC = GetDC(hWnd);
	this->hBackDC = CreateCompatibleDC(hDC);
	this->hBitmap = CreateCompatibleBitmap(hDC, winSizeX, winSizeY);

	SelectObject(hBackDC, hBitmap);
}

void RenderManager::End()
{
	DeleteObject(hBackDC);
	DeleteObject(hBitmap);
	ReleaseDC(hWnd, hDC);
}

void RenderManager::BeginDraw()
{
	PatBlt(hBackDC, 0, 0, winSizeX, winSizeY, WHITENESS);
}

void RenderManager::EndDraw()
{
	BitBlt(hDC, 0, 0, winSizeX, winSizeY, hBackDC, 0, 0, SRCCOPY);
}

void RenderManager::Rect(int startX, int startY, int endX, int endY)
{
	Rectangle(hBackDC, startX, startY, endX, endY);
}

void RenderManager::Text(std::wstring str, float x, float y)
{
	TextOutW(hBackDC, x, y, str.c_str(), str.size());
}
