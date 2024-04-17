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

	void SpriteRenderer::update()
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
		Vector2 pos = tr->Getposition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();
		pos = renderer::mainCamera->CaluatePosition(pos);

		if (mTexture->GetTextureType()
			== graphcis::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x*scale.x, mTexture->GetHeight() * mSize.y*scale.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()== graphcis::Texture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphcis(hdc);
			graphcis.TranslateTransform(pos.x, pos.y);
			graphcis.RotateTransform(rot);
			graphcis.TranslateTransform(-pos.x, -pos.y);
			graphcis.DrawImage(mTexture->GetImage()

				, Gdiplus::Rect(pos.x, pos.y
					, mTexture->GetWidth() * mSize.x*scale.x, mTexture->GetHeight() * mSize.y*scale.y)
			,0,0,mTexture->GetWidth(),mTexture->GetHeight(),Gdiplus::UnitPixel,nullptr/*imgAtt*/);
		}
	}
}