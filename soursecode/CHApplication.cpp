#include "CHApplication.h"
#include "input.h"
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

		Input::Initailize();
	}
	void Application::Run()
	{
		update();
		Lateupdate();
		Render();
	}
	void Application::update()
	{
		Input::Update();
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
