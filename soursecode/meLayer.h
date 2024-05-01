#pragma once
#include "meEntity.h"
#include "Commoninclude.h"
#include "meGameobject.h"

namespace me
{

	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();
		void EraseGameobject(Gameobject* erasegameobj);
		void AddGameobject(Gameobject* gameobject);
	
		const std::vector<Gameobject*> GetGameobjects() { return mGameobjects; }

	private:
		void findDeadGameobjects(OUT std::vector<Gameobject*>& gameobjs);
		void deleteGameobjects(std::vector<Gameobject*> gameobjs);
		void eraseDeadGameobject();
	private:
		std::vector<Gameobject*> mGameobjects;
	};
	typedef std::vector<Gameobject*>::iterator GameObjectIter;
}
