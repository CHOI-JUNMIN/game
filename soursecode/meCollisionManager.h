#pragma once
#include "Commoninclude.h"
#include "meBoxCollider2D.h"
#include "meCircleCollier2D.h"
namespace me
{
	using namespace enums;
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Lateupdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(Collider* left, Collider* right);
	private:
		static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
	};
}

