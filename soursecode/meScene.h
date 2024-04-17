#pragma once
#include "meEntity.h"
#include "meGameobject.h"
#include "meLayer.h"
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
		virtual void Destroy();
		virtual void OnEnter();
		virtual void OnExit();

		void AddGameobject(Gameobject* gameobj, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}