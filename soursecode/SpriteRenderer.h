#pragma once
#include "Entity.h"
#include "Component.h"

namespace me
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

	private:
	};
}