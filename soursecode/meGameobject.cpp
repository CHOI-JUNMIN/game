#include "meGameobject.h"
#include "meinput.h"
#include "meTime.h"
#include "meTransform.h"

namespace me::object
{
	void Destory(Gameobject* gameobject)
	{
		if (gameobject != nullptr)
			gameobject->death();
	}
}

namespace me
{
	Gameobject::Gameobject()
		: mState(eState::Active)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeAddTransform();
	}
	Gameobject::~Gameobject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			delete comp;
			comp = nullptr;
		}
	}

	void Gameobject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Initialize();
		}
	}
	void Gameobject::update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Update();
		}
	}
	void Gameobject::Lateupdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Lateupdate();
		}
	}
	void Gameobject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Render(hdc);
		}
	}
	void Gameobject::initializeAddTransform()
	{
		AddComponent<Transform>();
	}
}