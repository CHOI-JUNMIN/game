#include "meCollisionManager.h"
#include "meScene.h"
#include "meSceneManager.h"
#include "meGameobject.h"
#include "meCollider.h"
#include "meTransform.h"

namespace me
{

	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionmap = {};
	void CollisionManager::Initialize()
	{

	}
	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene,(eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::Lateupdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
	{
	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}
		mCollisionLayerMatrix[row][col] = enable;
	}
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<Gameobject*>& lefts = scene->GetLayer(left)->GetGameobjects();
		const std::vector<Gameobject*>& rights = scene->GetLayer(right)->GetGameobjects();

		for (Gameobject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;
			for (Gameobject* right : rights)
			{ 
				if (right->IsActive() == false)
					continue;
				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (left == right)
					continue;
				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		// 두 충돌체 번호를 가져온 ID를 확인해서 CollisionID값을 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();
		// 해당 id로 충돌체 정보를검색, 충돌정보가 없다면 충돌정보 생성
		auto iter = mCollisionmap.find(id.id);
		if (iter == mCollisionmap.end())
		{
			mCollisionmap.insert(std::make_pair(id.id, false));
			iter = mCollisionmap.find(id.id);
		}
		// 충돌체크를 해주면 됨
		if (Intersect(left, right))
		{
			//최초 충돌
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			//이미 충돌 중
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);

				iter->second = false;
			}
		}
		else 
		{
			if (iter->second == true) //충돌중이였으나 이제는 충돌이 아닌상태
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		Vector2 leftSize = left->Getsize() * 100.0f;
		Vector2 rightSize = right->Getsize() * 100.0f;

		if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f) 
			&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
		{
			return true;
		}
		return false;
	}
}