#pragma once
#include "Entity.h"
#include "Commoninclude.h"
#include "Gameobject.h"

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

		void AddGameobject(Gameobject* gameobject);
	
	private:
		//eLayerType mType;
		std::vector<Gameobject*> mGameobject;
	};
}
