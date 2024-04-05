#pragma once
#include "../soursecode/Resources.h"
#include "../soursecode/Texture.h"

namespace me
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG", L"..//Resource/CloudOcean.png");
	}
}