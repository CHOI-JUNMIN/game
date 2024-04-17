#pragma once
#include "../soursecode/meResources.h"
#include "../soursecode/meTexture.h"

namespace me
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Player", L"..//Resource/Player.bmp");
		Resources::Load<graphcis::Texture>(L"Cat", L"..//Resource/ChickenAlpha.bmp");
	}
}