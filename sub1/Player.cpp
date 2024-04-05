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
	}

	void Player::Render(HDC hdc)
	{
		Gameobject::Render(hdc);
	}

}
