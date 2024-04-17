#pragma once
#include "meEntity.h"
#include "meComponent.h"
#include "meTexture.h"
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