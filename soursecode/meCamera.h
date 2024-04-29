#pragma once
#include "meComponent.h"

namespace me
{
	using namespace me::math;
	class Camera : public Component
	{
	public:
		Vector2 CaluatePosition(Vector2 pos) { return pos - mDistance; };

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void SetTarget(Gameobject* target) { mTarget = target; };

	private:
		class Gameobject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};

}