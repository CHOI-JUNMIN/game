#include "SpriteRenderer.h"
#include "Gameobject.h"
#include "Transform.h"
#include "Texture.h"
me::SpriteRenderer::SpriteRenderer()
	:Component(), mTexture(nullptr),mSize(Vector2::One)
{
	
}

me::SpriteRenderer::~SpriteRenderer()
{
}

void me::SpriteRenderer::Initialize()
{
}

void me::SpriteRenderer::update()
{
}

void me::SpriteRenderer::Lateupdate()
{
}

void me::SpriteRenderer::Render(HDC hdc)
{
	if (mTexture == nullptr)
		assert(false);

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->Getposition();

	if (mTexture->GetTextureType()
		== graphcis::Texture::eTextureType::Bmp)
	{
		TransparentBlt(hdc, pos.x, pos.y
			, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
			, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
			, RGB(255, 0, 255));
	}
	else if (mTexture->GetTextureType()
		== graphcis::Texture::eTextureType::Png)
	{
		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mTexture->GetImage()
			, Gdiplus::Rect(pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
	}
}

//void me::SpriteRenderer::ImageLoad(const std::wstring& path)
//{
//	mImage = Gdiplus::Image::FromFile(path.c_str());
//	mWidth = mImage->GetWidth();
//	mHeight = mImage->GetHeight();
//}

