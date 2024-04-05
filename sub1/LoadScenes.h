#pragma once
#include "..//soursecode/SceneManager.h"
#include "PlayScene.h"
#include "TitleScene.h"
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