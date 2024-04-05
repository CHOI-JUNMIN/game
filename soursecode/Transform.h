#pragma once
#include "Entity.h"
#include "Component.h"

namespace me {

	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 Getposition() { return mPosition; }

	private:
		Vector2 mPosition;
	};

}
