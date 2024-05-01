#pragma once
#include "meGameobject.h"
namespace me
{
	class Application
	{
	public:
		Application();
		~Application();
		
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void Lateupdate();
		void Render();
		void Destroy();
		void Release();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

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