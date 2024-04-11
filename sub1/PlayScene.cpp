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
#include "Cat.h"
#include "CatScript.h"
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
			mPlayer->AddComponent<PlayerScript>();

			graphcis::Texture* playerTex = Resources::Find<graphcis::Texture>(L"Player");
			Animator* playerAnimator = mPlayer->AddComponent<Animator>();
			playerAnimator->CreateAnimation(L"Idle",playerTex,Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
			playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
			playerAnimator->PlayAnimation(L"Idle",false);

			mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.f, 100.f));
			//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));


			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
			cat->AddComponent<CatScript>();
			graphcis::Texture* catTex = Resources::Find<graphcis::Texture>(L"Cat");
			Animator* CatAnimator = cat->AddComponent < Animator>();
			CatAnimator->CreateAnimation(L"DownWalk", catTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			CatAnimator->CreateAnimation(L"RightWalk", catTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			CatAnimator->CreateAnimation(L"UpWalk", catTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			CatAnimator->CreateAnimation(L"LeftWalk", catTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			CatAnimator->CreateAnimation(L"SitDown", catTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			CatAnimator->CreateAnimation(L"Grooming", catTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			CatAnimator->CreateAnimation(L"LayDown", catTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			CatAnimator->PlayAnimation(L"SitDown", false);
			cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
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