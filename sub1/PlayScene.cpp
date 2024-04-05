#include "PlayScene.h"
#include "Gameobject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "input.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Object.h"
#include "Texture.h"
#include "..//soursecode/Resources.h"
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
		{

			bg = object::Instantiate<Player>(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG");
			sr->SetTexture(bg);
			Scene::Initialize();
		}
	}
	void PlayScene::update()
	{
		Scene::update();
	}
	void PlayScene::Lateupdate()
	{
		Scene::Lateupdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}