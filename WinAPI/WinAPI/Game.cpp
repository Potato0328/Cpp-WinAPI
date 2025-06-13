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

#pragma region �ڵ�������
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

#pragma region ����Ű �̵�
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
	// ��ŷ
	// ������ ȭ���� ������ �ʰ� ���ϴ� �׸��� �׸���
	// �������� �ʴ� �׸��� ��� �����ֱ� ������ �ܻ��� ��������
	//
	// ������ ȭ���� ��� �����, ���ϴ� �׸��� �׷��� �Ѵ�.
	// ������, ������ ȭ���� ��� ����� ������ ������ ���̱� ������
	// ��� ������ �� ȭ���� ��� ���� ������
	// ���������ϴ� ������ ������ ���Եȴ�.

	// ���� ���۸�

	RENDER->BeginDraw();

	std::wstring text = L"FPS :" + std::to_wstring(FRAME);
	RENDER->Text(text, 1000, 0);
	std::wstring dttext = L"FPS :" + std::to_wstring(DT);
	RENDER->Text(dttext, 1100, 0);

	RENDER->Rect(x, y, x + 100, y + 100);

	RENDER->EndDraw();
}
