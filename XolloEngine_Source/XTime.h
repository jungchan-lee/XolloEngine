#pragma once
#include "CommonInclude.h"

namespace xollo
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float GetDeltaTime() { return DeltaTime; }
	private:
		//CPU의 고유 진동 수를 저장
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		
		//CPU 진동수를 시간으로 변경한 값 저장
		static float DeltaTime;
	};

}

