#include "meTitleScene.h"
#include "meinput.h"
#include "mePlayScene.h"
#include "meSceneManager.h"

me::TitleScene::TitleScene()
{
}

me::TitleScene::~TitleScene()
{
}

void me::TitleScene::Initialize()
{
	Scene::Initialize();
}

void me::TitleScene::Update()
{
	Scene::Update();
}

void me::TitleScene::Lateupdate()
{
	Scene::Lateupdate();
	if (Input::GetKeyDown(eKeyCode::N))
	{
		SceneManager::LoadScene(L"PlayScene");
	}
}

void me::TitleScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void me::TitleScene::OnEnter()
{
	Scene::OnEnter();
}

void me::TitleScene::OnExit()
{
	Scene::OnExit();
}
