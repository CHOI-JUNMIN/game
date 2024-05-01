#pragma once
#include "../soursecode/meResources.h"
#include "../soursecode/meTexture.h"

namespace me
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Player", L"..//Resource/Player.bmp");
		Resources::Load<graphics::Texture>(L"Cat", L"..//Resource/ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"SpringFloor", L"..//Resource/SpringFloor.bmp");
	}
}