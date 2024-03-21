#pragma once
#include "Commoninclude.h"
namespace me
{
	class Gameobject
	{
	public:
		Gameobject();
		~Gameobject();

		void update();
		void Lateupdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		float GetPositionX(){	return mX;	}
		float GetPositionY(){	return mY;	}
	private:
		float mX;
		float mY;
	};
}