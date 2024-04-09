#pragma once
#include "../soursecode/Script.h"


namespace me
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			Attack,
		};
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;
	private:
		void sitDown();
		void move();
	private:
		eState mState;
		class  Animator* mAnimator;
	};
}