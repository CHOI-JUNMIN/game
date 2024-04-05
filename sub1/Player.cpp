#include "Player.h"
#include "input.h"
#include "Transform.h"
#include "Time.h"
namespace me
{
	void Player::Initialize()
	{
		Gameobject::Initialize();
	}

	void Player::update()
	{
		Gameobject::update();
	}

	void Player::Lateupdate()
	{
		Gameobject::Lateupdate();

		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->Getposition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		Gameobject::Render(hdc);
	}

}
