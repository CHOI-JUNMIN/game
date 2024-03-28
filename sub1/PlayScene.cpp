#include "PlayScene.h"
#include "Gameobject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
namespace me
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//for (size_t i = 0; i < 100; i++)
		//{
		//	Gameobject* obj = new Gameobject();
		//	obj->SetPosition(rand() % 1600, rand() % 900);
		//	AddGameobject(obj);
		//}
		{
			Player* p1 = new Player();
			Transform* tr
				= p1->AddComponent<Transform>();
			tr->SetPos(800, 450);
			tr->SetName(L"TR");
			SpriteRenderer* sr
				= p1->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameobject(p1);
		}
		{
			Player* p1 = new Player();
			Transform* tr
				= p1->AddComponent<Transform>();
			tr->SetPos(300, 450);
			tr->SetName(L"TR");
			SpriteRenderer* sr
				= p1->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameobject(p1);
		}
		{
			Player* p1 = new Player();
			Transform* tr
				= p1->AddComponent<Transform>();
			tr->SetPos(100, 650);
			tr->SetName(L"TR");
			SpriteRenderer* sr
				= p1->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameobject(p1);
		}
	}
	void PlayScene::update()
	{
		Scene::update();
	}
	void PlayScene::Lateupdate()
	{
		Scene::Lateupdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}