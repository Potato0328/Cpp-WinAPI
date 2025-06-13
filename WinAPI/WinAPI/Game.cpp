#include "Game.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include "InputManager.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Start(HINSTANCE hInstance, HWND hWnd)
{
	RENDER->Start(hWnd);
	TIME->Start();
}

void Game::End()
{
	RENDER->End();
	TIME->End();
}

void Game::Input()
{
	GAME_INPUT->CheckInput();
}

bool isLeft = false;
void Game::Update()
{
	TIME->CheckTime();

#pragma region 자동움직임
	/*if (isLeft)
	{
		x -= 300 * DT;
		if (x < 0)
		{
			isLeft = false;
		}
	}
	else
	{
		x += 300 * DT;
		if (x > 500)
		{
			isLeft = true;
		}
	}*/
#pragma endregion

#pragma region 방향키 이동
	/*if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		x -= 0.1;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		x += 0.1;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		y -= 0.1;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		y += 0.1;
	}*/
#pragma endregion

	if (GAME_INPUT->GetKey(VK_UP))
	{
		y -= 100 * DT;
	}
	if (GAME_INPUT->GetKey(VK_DOWN))
	{
		y += 100 * DT;
	}
	if (GAME_INPUT->GetKey(VK_LEFT))
	{
		x -= 100 * DT;
	}
	if (GAME_INPUT->GetKey(VK_RIGHT))
	{
		x += 100 * DT;
	}
}

void Game::Render()
{
	// 블링킹
	// 게임의 화면을 지우지 않고 원하는 그림을 그리면
	// 지워지지 않는 그림이 계속 남아있기 때문에 잔상이 남아있음
	//
	// 게임의 화면을 모두 지우고, 원하는 그림을 그려야 한다.
	// 하지만, 게임의 화면을 모두 지우는 과정도 눈으로 보이기 때문에
	// 모두 지워진 흰 화면이 계속 눈에 보여서
	// 깜빡깜빡하는 현상을 눈으로 보게된다.

	// 더블 버퍼링

	RENDER->BeginDraw();

	std::wstring text = L"FPS :" + std::to_wstring(FRAME);
	RENDER->Text(text, 1000, 0);
	std::wstring dttext = L"FPS :" + std::to_wstring(DT);
	RENDER->Text(dttext, 1100, 0);

	RENDER->Rect(x, y, x + 100, y + 100);

	RENDER->EndDraw();
}
