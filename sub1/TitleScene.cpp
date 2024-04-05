#include "TitleScene.h"
#include "input.h"
#include "PlayScene.h"
#include "SceneManager.h"

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

void me::TitleScene::update()
{
	Scene::update();
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
	wchar_t str[50] = L"Title Scene";
	TextOut(hdc, 0, 0, str, 11);
}
