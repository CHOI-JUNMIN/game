#include "CHApplication.h"
#include "meinput.h"
#include "meTime.h"
#include "meSceneManager.h"
#include "meResources.h"
#include "meCollisionManager.h"
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

		Input::Initailize();
		Time::Initailize();
		CollisionManager::Initialize();
		SceneManager::Initialize();

	}
	void Application::Run()
	{
		Update();
		Lateupdate();
		Render();
		Destroy();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		SceneManager::Update();
	}
	void Application::Lateupdate()
	{
		CollisionManager::Lateupdate();
		SceneManager::Lateupdate();
	}
	void Application::Render()
	{

		clearRenderTarget();

		Time::Render(mBackHdc);
		CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Release()
	{
		SceneManager::Release();
		Resources::Relese();
	}
	void Application::clearRenderTarget()
	{
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);

		Rectangle(mBackHdc, -1, -1, 1601, 901);
		(HBRUSH)SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);
	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}

