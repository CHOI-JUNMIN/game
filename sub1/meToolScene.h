#pragma once
#include "..//soursecode/meScene.h"


namespace me
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize() override;
		void Update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	};
}

