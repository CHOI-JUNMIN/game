#pragma once
#include "Component.h"
namespace me
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;
	};
}