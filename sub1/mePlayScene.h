#pragma once
#include "..//soursecode/meScene.h"

namespace me 
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();
		void Initialize() override;
		void Update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* mPlayer;
	};
}