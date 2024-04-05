#pragma once
#include "..//soursecode/Scene.h"

namespace me 
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();
		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* bg;
	};
}