#pragma once
#include "framework.h"

class Game
{
public:
	Game();				// ���� ������
	virtual ~Game();	// ���� �Ҹ���

public:
	void Start(HINSTANCE hInstance, HWND hWnd);	// ���� ����
	void End();		// ���� ����

	void Input();	// ���� �Է�
	void Update();	// ���� ����
	void Render();	// ���� ǥ��

public:
	HINSTANCE hInstance;
	HWND hWnd;

private:
	float x = 0;
	float y = 0;
};

