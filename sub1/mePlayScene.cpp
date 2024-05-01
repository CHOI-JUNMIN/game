#include "mePlayScene.h"
#include "meGameobject.h"
#include "mePlayer.h"
#include "meTransform.h"
#include "meSpriteRenderer.h"
#include "meinput.h"
#include "meTitleScene.h"
#include "meSceneManager.h"
#include "meObject.h"
#include "meTexture.h"
#include "meResources.h"
#include "mePlayerScript.h"
#include "meCamera.h"
#include "meRenderer.h"
#include "meAnimator.h"
#include "meCat.h"
#include "meCatScript.h"
#include "meBoxCollider2D.h"
#include "meCircleCollier2D.h"
#include "meCollisionManager.h"
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
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);

		Gameobject* camera = object::Instantiate<Gameobject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		//BoxCollier2D* collider = mPlayer->AddComponent<BoxCollier2D>();
		CircleCollier2D* collider = mPlayer->AddComponent<CircleCollier2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));


		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);
		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.f, 250.f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));


		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		cat->AddComponent<CatScript>();
		//cameraComp->SetTarget(cat);
		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* CatAnimator = cat->AddComponent < Animator>();
		CircleCollier2D* boxCatCollider = cat->AddComponent<CircleCollier2D>();
		boxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));

		////CatAnimator->CreateAnimation(L"DownWalk", catTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		////CatAnimator->CreateAnimation(L"RightWalk", catTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		////CatAnimator->CreateAnimation(L"UpWalk", catTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		////CatAnimator->CreateAnimation(L"LeftWalk", catTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		////CatAnimator->CreateAnimation(L"SitDown", catTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		////CatAnimator->CreateAnimation(L"Grooming", catTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		////CatAnimator->CreateAnimation(L"LayDown", catTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		////CatAnimator->PlayAnimation(L"SitDown", false);
		CatAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resource\\Mushroom", Vector2::Zero, 0.1f);

		CatAnimator->PlayAnimation(L"MushroomIdle", true);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
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
		Scene::OnEnter();
	}
	void PlayScene::OnExit()
	{
		Scene::OnExit();
	}
}