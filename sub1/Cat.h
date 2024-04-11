#pragma once
#include "..//soursecode/Gameobject.h"

namespace me
{
	class Cat : public Gameobject
	{
	public:
		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
