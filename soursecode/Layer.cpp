#include "Layer.h"

namespace me
{

	Layer::Layer()
		:mGameobject{}
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (Gameobject* gameobj : mGameobject)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->Initialize();
		}
	}

	void Layer::update()
	{
		for (Gameobject* gameobj : mGameobject)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->update();
		}
	}

	void Layer::Lateupdate()
	{
		for (Gameobject* gameobj : mGameobject)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->Lateupdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (Gameobject* gameobj : mGameobject)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->Render(hdc);
		}
	}

	void Layer::AddGameobject(Gameobject* gameobject)
	{
		if (gameobject == nullptr)
			return;
		mGameobject.push_back(gameobject);
	}
}