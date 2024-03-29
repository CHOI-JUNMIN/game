#pragma once
#include "Commoninclude.h"
#include "Component.h"

namespace me
{
	class Gameobject
	{
	public:
		Gameobject();
		~Gameobject();

		virtual void update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);
		virtual void Initialize();

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);
			mComponents.push_back(comp);
			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

		private:
			std::vector<Component*> mComponents;
	};
}