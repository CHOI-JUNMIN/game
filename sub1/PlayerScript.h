#pragma once
#include "../soursecode/Script.h"


namespace me
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;
	private:

	};
}