#pragma once
#include "meEntity.h"
#include "meComponent.h"
#include "meTexture.h"
namespace me
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();

		void Initialize() override;
		void Update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:

		Vector2 mTileSize;

		graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
	};
}