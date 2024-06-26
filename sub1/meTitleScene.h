#pragma once
#include "..//soursecode/meScene.h"

namespace me
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();


		void Initialize() override;
		void Update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
	};

}