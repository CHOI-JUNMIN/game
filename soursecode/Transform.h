#pragma once
#include "Entity.h"
#include "Component.h"

namespace me {

	struct Pos
	{
		int mX;
		int mY;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void SetPos(int x, int y) { mX = x; mY = y; }
		int GetX() { return mX;}
		int GetY() { return mY; }

	private:
		int mX;
		int mY;
	};

}
