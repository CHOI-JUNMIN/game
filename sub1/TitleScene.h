#pragma once
#include "..//soursecode/Scene.h"

namespace me
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();


		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;

	private:
	};

}