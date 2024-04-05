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
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
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

			Gameobject* camera = object::Instantiate<Gameobject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			mPlayer = object::Instantiate<Player>
				(enums::eLayerType::Player/*, Vector2(100.0f, 100.0f)*/);
			SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
			sr->SetSize(Vector2(3.0f, 3.0f));
			mPlayer->AddComponent<PlayerScript>();

			graphcis::Texture* packmanTexture = Resources::Find<graphcis::Texture>(L"PackMan");
			sr->SetTexture(packmanTexture);

			Gameobject* bg = object::Instantiate<Gameobject>
				(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
			bgSr->SetSize(Vector2(3.0f, 3.0f));

			graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"Map");
			bgSr->SetTexture(bgTexture);
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
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}