#pragma once
#include "..//soursecode/meGameobject.h"

namespace me
{
	class Tile : public Gameobject
	{
	public:

		void Initialize() override;
		void Update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

	private:
	};
}

