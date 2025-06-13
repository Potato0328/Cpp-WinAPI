#include "TimeManager.h"
#include <chrono>

void TimeManager::Start()
{
	fps = 1;
	deltaTime = 1;
	prevTime = std::chrono::high_resolution_clock::now();;
	curTime = std::chrono::high_resolution_clock::now();;

}

void TimeManager::End()
{

}

void TimeManager::CheckTime()
{
	// 이전프레임에서 현재프레임까지 걸린 시간을 측정
	curTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> delta = curTime - prevTime;

	deltaTime = delta.count();
	fps = 1 / deltaTime;

	prevTime = curTime;
}
