#pragma once
#include "meEntity.h"

namespace me
{
	using namespace enums;

	class Gameobject;
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);

		void SetOwner(Gameobject* owner) { mOwner = owner; };
		Gameobject* GetOwner() { return mOwner; }
		enums::eComponentType GetType() { return mType;}
	private:
		Gameobject* mOwner;
		enums::eComponentType mType;
	};
}


