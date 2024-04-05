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
			comp->Initialize();
			comp->SetOwner(this);
			mComponents[(UINT)comp->GetType()] = comp;
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
		void initializeAddTransform();

	private:
		std::vector<Component*> mComponents;
	};
}