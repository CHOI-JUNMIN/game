#include "SceneManager.h"


namespace me {

	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{

	}

	void SceneManager::update()
	{
		mActiveScene->update();
	}

	void SceneManager::Lateupdate()
	{
		mActiveScene->Lateupdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

}