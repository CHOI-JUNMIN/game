#include "meSpriteRenderer.h"
#include "meGameobject.h"
#include "meTransform.h"
#include "meTexture.h"
#include "meRenderer.h"

namespace me
{


	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::Lateupdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();
		pos = renderer::mainCamera->CaluatePosition(pos);

		if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;

				AlphaBlend(hdc, pos.x, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y
					, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
					, func);
			}

			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphics(hdc);
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);
			graphics.DrawImage(mTexture->GetImage()

				, Gdiplus::Rect(pos.x, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y)
				, 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), Gdiplus::UnitPixel, nullptr/*imgAtt*/);
		}
	}
}