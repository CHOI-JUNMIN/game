#include "meLayer.h"

namespace me
{

	Layer::Layer()
		:mGameobjects{}
	{
	}

	Layer::~Layer()
	{
		for (Gameobject* gameObj : mGameobjects)
		{
			if (gameObj == nullptr)
				continue;
			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (Gameobject* gameobj : mGameobjects)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->Initialize();
		}
	}

	void Layer::update()
	{
		for (Gameobject* gameobj : mGameobjects)
		{
			if (gameobj == nullptr)
				continue;
			Gameobject::eState state = gameobj->GetActive();
			if (state == Gameobject::eState::Paused
				|| state == Gameobject::eState::Dead)
				continue;
			gameobj->update();
		}
	}

	void Layer::Lateupdate()
	{
		for (Gameobject* gameobj : mGameobjects)
		{
			if (gameobj == nullptr)
				continue;
			Gameobject::eState state = gameobj->GetActive();
			if (state == Gameobject::eState::Paused
				|| state == Gameobject::eState::Dead)
				continue;
			gameobj->Lateupdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (Gameobject* gameobj : mGameobjects)
		{
			if (gameobj == nullptr)
				continue;
			Gameobject::eState state = gameobj->GetActive();
			if (state == Gameobject::eState::Paused
				|| state == Gameobject::eState::Dead)
				continue;
			gameobj->Render(hdc);
		}
	}
	void Layer::Destroy()
	{
		for (GameObjectIter iter = mGameobjects.begin()
			; iter != mGameobjects.end()
			; )
		{
			Gameobject::eState active = (*iter)->GetActive();
			if (active == Gameobject::eState::Dead)
			{
				Gameobject* deathobj = (*iter);
				iter = mGameobjects.erase(iter);

				delete deathobj;
				deathobj = nullptr;

				continue;
			}

			iter++;
		}
	}
	void Layer::AddGameobject(Gameobject* gameobject)
	{
		if (gameobject == nullptr)
			return;
		mGameobjects.push_back(gameobject);
	}
}