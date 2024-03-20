#pragma once
#include "Commoninclude.h"
#include "Gameobject.h"
namespace me
{


	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND mHwnd);
		void Run();
		void update();
		void Lateupdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		Gameobject mPlayer;
	};
}