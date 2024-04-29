#pragma once
#include "meCollider.h"

namespace me
{
	class BoxCollier2D : public Collider
	{
	public:
		BoxCollier2D();
		~BoxCollier2D();

		virtual void Initialize();
		virtual void Update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);
	private:
		Vector2 mSize;
	};
}

