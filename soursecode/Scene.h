#pragma once
#include "Entity.h"
#include "Gameobject.h"
namespace me
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();
		virtual void Initialize();
		virtual void update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);

		void AddGameobject(Gameobject* gameobject);

	private:
		std::vector<Gameobject*> mGameobjects;
	};
}