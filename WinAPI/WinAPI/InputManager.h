#pragma once
#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
public: 
	void Start();
	void End();

	void CheckInput();				// Ű �Է� Ȯ��

	bool GetKey(int key);			// Ű�� ������ �ִ� ��
	bool GetKeyDown(int key);		// Ű�� ���� ����
	bool GetKeyUp(int key);			// Ű�� �� ����

private:
	bool prevKeys[255];				// ���� Ű �Է� ����
	bool curKeys[255];				// ���� Ű �Է� ����
};

#define GAME_INPUT InputManager::GetInstance()
