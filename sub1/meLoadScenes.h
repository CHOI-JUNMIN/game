#pragma once
#include "..//soursecode/meSceneManager.h"
#include "mePlayScene.h"
#include "meTitleScene.h"
namespace me
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		

		SceneManager::LoadScene(L"PlayScene"); 
	}
}