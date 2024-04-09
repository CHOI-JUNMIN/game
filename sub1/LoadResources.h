#pragma once
#include "../soursecode/Resources.h"
#include "../soursecode/Texture.h"

namespace me
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Map", L"..//Resource/img/map/map_pure.png");
		Resources::Load<graphcis::Texture>(L"PackMan", L"..//Resource/img/pacman/0.png");
		Resources::Load<graphcis::Texture>(L"Chicken", L"..//Resource/chicken.bmp");
		Resources::Load<graphcis::Texture>(L"Cat", L"..//Resource/ChickenAlpha.bmp");
	}
}