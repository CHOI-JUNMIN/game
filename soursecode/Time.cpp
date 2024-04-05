#include "Time.h"
namespace me
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue=0.0f;

	void Time::Initailize()
	{
		QueryPerformanceFrequency(&CpuFrequency);  //cpu 고유 진동수

		QueryPerformanceCounter(&PrevFrequency); //프로그램 시작시 현재 진동수
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequncy  //4byte
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);   //8byte(QuadPart)이기때문에 캐스팅을 함
			 
		DeltaTimeValue = differenceFrequncy / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;
		
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"FPS: %d", (int)fps);
		int len = wcsnlen_s(str, 50);
		
		TextOut(hdc, 0, 0, str, len);
	}
}