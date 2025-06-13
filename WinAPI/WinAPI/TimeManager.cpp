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
	// ���������ӿ��� ���������ӱ��� �ɸ� �ð��� ����
	curTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> delta = curTime - prevTime;

	deltaTime = delta.count();
	fps = 1 / deltaTime;

	prevTime = curTime;
}
