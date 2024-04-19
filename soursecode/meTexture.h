#pragma once
#include "meResource.h"
namespace me::graphcis
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		static Texture* Create(const std::wstring& name, UINT width, UINT height);
		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path)override;

		UINT GetWidth() { return mWidth; }
		void SetWidth(UINT width) { mWidth = width; }
		UINT GetHeight() { return mHeight; }
		void SetHeight(UINT height) { mHeight = height; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
		bool IsAlpha() { return mbAlpha; }
	private:
		bool mbAlpha;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		eTextureType mType;
		HDC mHdc;


		UINT mWidth;
		UINT mHeight;
	};
}

