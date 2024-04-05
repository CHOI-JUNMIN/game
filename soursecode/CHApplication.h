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
		HDC GetHdc() { return mHdc; }

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;
		
		UINT mWidth;
		UINT mHeight;

		//std::vector<Scene*> mScenes;

		void clearRenderTarget();
		void copyRenderTarget(HDC source,HDC dest);

	};
}