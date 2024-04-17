#pragma once
#include "meEntity.h"
#include "meComponent.h"

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
		float GetRotation() { return mRotation; }
		Vector2 GetScale() { return mScale; }
		void SetRotation(float rotate) { mRotation = rotate; }
		void SetScale(Vector2 scale) { mScale = scale; }
	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};

}
