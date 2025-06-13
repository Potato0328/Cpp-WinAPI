#pragma once
#include "Singleton.h"
#include <chrono>

class TimeManager : public Singleton<TimeManager>
{
public:
	void Start();
	void End();

	void CheckTime();

private:
	int fps;				// Frame per Seconds : 1�ʴ� �׷��� ȭ���
	float deltaTime;		// Delta Time : �����ð�, 1�����Ӵ� �ҿ�� �ð�

	std::chrono::high_resolution_clock::time_point prevTime;	// �����ð�
	std::chrono::high_resolution_clock::time_point curTime;		// ���ݽð�

public:
	int GetFPS() { return fps; }
	float GetDT() { return deltaTime; }
};

#define TIME TimeManager::GetInstance()
#define FRAME TimeManager::GetInstance()->GetFPS()
#define DT TimeManager::GetInstance()->GetDT()

