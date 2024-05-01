#include "meDontDestroyOnLoad.h"

namespace me
{
	DontDestroyOnLoad::DontDestroyOnLoad()
	{
	}
	DontDestroyOnLoad::~DontDestroyOnLoad()
	{
	}
	void DontDestroyOnLoad::Initialize()
	{
		Scene::Initialize();
	}
	void DontDestroyOnLoad::Update()
	{
		Scene::Update();
	}
	void DontDestroyOnLoad::Lateupdate()
	{
		Scene::Lateupdate();
	}
	void DontDestroyOnLoad::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void DontDestroyOnLoad::OnEnter()
	{
		Scene::OnEnter();
	}
	void DontDestroyOnLoad::OnExit()
	{
		Scene::OnExit();
	}
}