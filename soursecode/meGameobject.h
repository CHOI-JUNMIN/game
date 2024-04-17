#pragma once
#include "Commoninclude.h"
#include "meComponent.h"

namespace me
{
	class Gameobject
	{
	public:

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

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
		eState GetActive() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		void Death() { mState = eState::Dead; }

	private:
		void initializeAddTransform();

	private:
		eState mState;
		std::vector<Component*> mComponents;
	};
}