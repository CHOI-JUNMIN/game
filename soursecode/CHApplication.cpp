#include "CHApplication.h"
#include "input.h"
#include "Time.h"
namespace me
{
	Application::Application()
		:mHwnd(nullptr), mHdc(nullptr), mWidth(0), mHeight(0), mBackHdc(NULL), mBackBitmap(NULL)
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth , mHeight, 0);
		ShowWindow(mHwnd, true);
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height); //윈도우 해상도에 맞는 백버퍼 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
		mPlayer.SetPosition(0, 0);

		Input::Initailize();
		Time::Initailize();
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
		Time::Update();
		mPlayer.update();
	}
	void Application::Lateupdate()
	{

	}
	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);  //BackBuffer에 있는걸 원본 Buffer에 복사 
	}
}

