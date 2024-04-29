#include "meAnimation.h"
#include "meTime.h"
#include "meTransform.h"
#include "meGameObject.h"
#include "meAnimator.h"
#include "meRenderer.h"
#include "meCamera.h"


namespace me
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::update()
	{
		if (mbComplete)
			return;
		mTime += Time::DeltaTime();
		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void Animation::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		Gameobject* gameobj = mAnimator->GetOwner();
		Transform* tr = gameobj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();
		if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);
		Sprite sprite = mAnimationSheet[mIndex];
		graphcis::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphcis::Texture::eTextureType::Bmp)
		{

			HDC imgHdc = mTexture->GetHdc();

			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 225; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, func);
			}
			else
			{

				TransparentBlt(hdc
					, pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255, 0, 255));
			}
			Rectangle(hdc, pos.x, pos.y, pos.x + 10, pos.y + 10);
		}

		else if (type == graphcis::Texture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};

			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, /*&imgAtt*/nullptr
			);
		}
	}

	void Animation::CreateAnimation(const std::wstring& name, graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}

}