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
#include "Animator.h"
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

			Gameobject* camera = object::Instantiate<Gameobject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle);
			//SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
			//sr->SetSize(Vector2(3.0f, 3.0f));
			mPlayer->AddComponent<PlayerScript>();

			graphcis::Texture* packmanTexture = Resources::Find<graphcis::Texture>(L"Cat");
			Animator* animator = mPlayer->AddComponent < Animator>();
			animator->CreateAnimation(L"DownWalk", packmanTexture, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"RightWalk", packmanTexture, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"UpWalk", packmanTexture, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"LeftWalk", packmanTexture, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"SitDown", packmanTexture, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"Grooming", packmanTexture, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			
			animator->PlayAnimation(L"SitDown", false);

			mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.f, 100.f));
			mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			//sr->SetTexture(packmanTexture);

			Gameobject* bg = object::Instantiate<Gameobject>(enums::eLayerType::Player);
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
			//bgSr->SetSize(Vector2(3.0f, 3.0f));

			graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"Bubble");
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