#include "meScene.h"

namespace me
{
	Scene::Scene()
		: mLayers{}
	{
		CreateLayers();
	}
	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}
	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->update();
		}
	}
	void Scene::Lateupdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Lateupdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
		}
	}
	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}
	void Scene::AddGameobject(Gameobject* gameobj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameobject(gameobj);
	}
	void Scene::EraseGameobject(Gameobject* gameobj)
	{
		eLayerType layerType = gameobj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameobject(gameobj);
	}

	void Scene::CreateLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}
	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{

	}
}