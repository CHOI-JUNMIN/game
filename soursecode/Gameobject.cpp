#include "Gameobject.h"
#include "input.h"
#include "Time.h"
#include "Transform.h"
namespace me
{
	Gameobject::Gameobject()
	{
		initializeAddTransform();
	}
	Gameobject::~Gameobject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void Gameobject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}
	void Gameobject::update()
	{
		for (Component* comp : mComponents)
		{
			comp->update();
		}
	}
	void Gameobject::Lateupdate()
	{
		for (Component* comp : mComponents)
		{
			comp->Lateupdate();
		}
	}
	void Gameobject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
	void Gameobject::initializeAddTransform()
	{
		AddComponent<Transform>();
	}
}