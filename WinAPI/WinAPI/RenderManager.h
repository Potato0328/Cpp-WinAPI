#pragma once
#include "Singleton.h"
#include "framework.h"
#include <string>

class RenderManager : public Singleton<RenderManager>
{
public:
	void Start(HWND hWnd);
	void End();

	void BeginDraw();		// ���ο� �׸��ǿ� �غ�
	void EndDraw();			// ���ο� �׸��ǿ� �׸� ������ ����ȭ������ ����

	void Rect(int startX, int startY, int endX, int endY);
	void Text(std::wstring str, float x, float y);

private:
	HWND hWnd;
	HDC hDC;			// ���� ȭ��� �׸���
	HDC hBackDC;		// ���ο� �׸���
	HBITMAP hBitmap;	// �׸�

	int winSizeX;		// ȭ�� ���� ũ��
	int winSizeY;		// ȭ�� ���� ũ��
};

#define RENDER RenderManager::GetInstance()

