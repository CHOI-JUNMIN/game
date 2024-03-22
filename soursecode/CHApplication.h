#pragma once
#include "Gameobject.h"
namespace me
{
	class Application
	{
	public:
		Application();
		~Application();
		
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void update();
		void Lateupdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;
		
		UINT mWidth;
		UINT mHeight;

		Gameobject mPlayer;
	};
}