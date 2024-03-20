#include "CHApplication.h"

namespace me
{
	Application::Application()
		:mHwnd(nullptr),mHdc(nullptr)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.SetPosition(0, 0);
	}
	void Application::Run()
	{
		update();
		Lateupdate();
		Render();
	}
	void Application::update()
	{
		mPlayer.update();
	}
	void Application::Lateupdate()
	{

	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
		
	}
}
