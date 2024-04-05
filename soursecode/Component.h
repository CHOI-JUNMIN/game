#pragma once
#include "Entity.h"

namespace me
{
	class Gameobject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);

		void SetOwner(Gameobject* owner) { mOwner = owner; };
		Gameobject* GetOwner() { return mOwner; }
	private:
		Gameobject* mOwner;
	};
}


