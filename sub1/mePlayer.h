#pragma once
#include "..//soursecode/meGameobject.h"

namespace me
{
	class Player : public Gameobject
	{
	public:

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;
	
	private:
	};
}
