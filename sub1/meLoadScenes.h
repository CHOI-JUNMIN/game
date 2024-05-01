#pragma once
#include "..//soursecode/meSceneManager.h"
#include "mePlayScene.h"
#include "meTitleScene.h"
#include "meToolScene.h"
namespace me
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		

		SceneManager::LoadScene(L"ToolScene"); 
	}
}