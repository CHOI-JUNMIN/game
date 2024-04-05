#include "PlayerScript.h"
#include "input.h"
#include "Transform.h"
#include "Time.h"
#include "Gameobject.h"

namespace me
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::update()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->Getposition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->Getposition();
			pos.x -= 100.0f * Time::DeltaTime();

			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->Getposition();
			pos.y -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->Getposition();
			pos.y += 100.0f * Time::DeltaTime();

			tr->SetPosition(pos);
		}
	}
	void PlayerScript::Lateupdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}