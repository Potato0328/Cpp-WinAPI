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
	int fps;				// Frame per Seconds : 1초당 그려진 화면수
	float deltaTime;		// Delta Time : 단위시간, 1프레임당 소요된 시간

	std::chrono::high_resolution_clock::time_point prevTime;	// 이전시간
	std::chrono::high_resolution_clock::time_point curTime;		// 지금시간

public:
	int GetFPS() { return fps; }
	float GetDT() { return deltaTime; }
};

#define TIME TimeManager::GetInstance()
#define FRAME TimeManager::GetInstance()->GetFPS()
#define DT TimeManager::GetInstance()->GetDT()

