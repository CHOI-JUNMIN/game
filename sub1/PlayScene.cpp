#include "PlayScene.h"
#include "Gameobject.h"
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
		for (size_t i = 0; i < 100; i++)
		{
			Gameobject* obj = new Gameobject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameobject(obj);
		}
	}
	void PlayScene::update()
	{
		Scene::update();
		//for (Gameobject* gameobj : mGameobjects)
		//{
		//	gameobj->update();
		//}
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