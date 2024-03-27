#include "Scene.h"
namespace me
{
	Scene::Scene()
		: mGameobjects{}
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
	}
	void Scene::update()
	{
		//for (size_t i = 0; i < mGameobjects.size(); i++)
		//{
		//	mGameobjects[i]->update();
		//}
		//범위 기반 for문
		for (Gameobject* gameobj : mGameobjects)
		{
			gameobj->update();
		}
	}
	void Scene::Lateupdate()
	{
		for (Gameobject* gameobj : mGameobjects)
		{
			gameobj->Lateupdate();
 		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Gameobject* gameobj : mGameobjects)
		{
			gameobj->Render(hdc);
		}
	}
	void Scene::AddGameobject(Gameobject* gameobject)
	{
		mGameobjects.push_back(gameobject);
	}
}