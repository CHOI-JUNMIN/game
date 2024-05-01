#pragma once
#include "Commoninclude.h"
#include "meComponent.h"


namespace me::object
{
	void Destory(Gameobject* gameobject);
}

namespace me
{
	class Gameobject
	{
	public:
		friend void object::Destory(Gameobject* obj);
		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		Gameobject();
		~Gameobject();

		virtual void Update();
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
		eState GetState() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool IsActive(){ return mState == eState::Active; }
		bool IsDead(){ return mState == eState::Dead; }
		void SetLayerType(eLayerType layerType) { mLayerType = layerType; }
		eLayerType GetLayerType() { return mLayerType; }
	private:
		void initializeAddTransform();
		void death() { mState = eState::Dead; }
	private:
		eState mState;
		std::vector<Component*> mComponents;
		eLayerType mLayerType;
	};
}