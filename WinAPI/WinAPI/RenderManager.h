#pragma once
#include "Singleton.h"
#include "framework.h"
#include <string>

class RenderManager : public Singleton<RenderManager>
{
public:
	void Start(HWND hWnd);
	void End();

	void BeginDraw();		// 새로운 그림판에 준비
	void EndDraw();			// 새로운 그림판에 그린 내용을 게임화면으로 복사

	void Rect(int startX, int startY, int endX, int endY);
	void Text(std::wstring str, float x, float y);

private:
	HWND hWnd;
	HDC hDC;			// 게임 화면용 그림판
	HDC hBackDC;		// 새로운 그림판
	HBITMAP hBitmap;	// 그림

	int winSizeX;		// 화면 가로 크기
	int winSizeY;		// 화면 세로 크기
};

#define RENDER RenderManager::GetInstance()

