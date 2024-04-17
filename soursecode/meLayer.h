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
		void AddGameobject(Gameobject* gameobject);
	
	private:
		//eLayerType mType;
		std::vector<Gameobject*> mGameobjects;
	};
	typedef std::vector<Gameobject*>::iterator GameObjectIter;
}
