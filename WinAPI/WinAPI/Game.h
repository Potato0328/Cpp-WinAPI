#pragma once
#include "framework.h"

class Game
{
public:
	Game();				// 게임 생성자
	virtual ~Game();	// 게임 소멸자

public:
	void Start(HINSTANCE hInstance, HWND hWnd);	// 게임 시작
	void End();		// 게임 종료

	void Input();	// 게임 입력
	void Update();	// 게임 동작
	void Render();	// 게임 표현

public:
	HINSTANCE hInstance;
	HWND hWnd;

private:
	float x = 0;
	float y = 0;
};

