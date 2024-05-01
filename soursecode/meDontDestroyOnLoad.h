#pragma once
#include "meScene.h"
namespace me
{
	class DontDestroyOnLoad : public Scene
	{
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();
		void Initialize() override;
		void Update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
	};
}


