#pragma once
#include "meCollider.h"

namespace me
{
	class CircleCollier2D : public Collider
	{
	public:
		CircleCollier2D();
		~CircleCollier2D();

		virtual void Initialize();
		virtual void Update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);
	private:
		float mRadius;
	};
}

