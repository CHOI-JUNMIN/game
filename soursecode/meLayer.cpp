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
			if (gameobj->IsActive() == false)
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
			if (gameobj->IsActive() == false)
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
			if (gameobj->IsActive() == false)
				continue;
			gameobj->Render(hdc);
		}
	}
	void Layer::Destroy()
	{
		std::vector<Gameobject*> deletobjects = {};
		findDeadGameobjects(deletobjects);
		eraseDeadGameobject();
		deleteGameobjects(deletobjects);
	}
	void Layer::EraseGameobject(Gameobject* erasegameobj)
	{
		std::erase_if(mGameobjects, [=](Gameobject* gameobj) {return gameobj == erasegameobj; });
	}
	void Layer::AddGameobject(Gameobject* gameobject)
	{
		if (gameobject == nullptr)
			return;
		mGameobjects.push_back(gameobject);
	}
	void Layer::findDeadGameobjects(OUT std::vector<Gameobject*>& gameobjs)
	{
		for (Gameobject* gameobj : mGameobjects)
		{
			Gameobject::eState active = gameobj->GetState();
			if (active == Gameobject::eState::Dead)
				gameobjs.push_back(gameobj);
		}
	}
	void Layer::deleteGameobjects(std::vector<Gameobject*> deleteobjs)
	{
		for (Gameobject* obj : deleteobjs)
		{
			delete obj;
			obj = nullptr;
		}
	}
	void Layer::eraseDeadGameobject()
	{
		std::erase_if(mGameobjects, [](Gameobject* gameobj) {return (gameobj)->IsDead(); });
	}
}