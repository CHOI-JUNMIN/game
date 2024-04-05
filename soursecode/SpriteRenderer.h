#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"
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

		void SetTexture(graphcis::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphcis::Texture* mTexture;
		math::Vector2 mSize;
	};
}