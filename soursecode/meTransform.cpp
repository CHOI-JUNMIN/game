#include "meTransform.h"

me::Transform::Transform()
	:Component(enums::eComponentType::Transform)
	,mScale(Vector2::One)
	,mRotation(0.0f)
{
}

me::Transform::~Transform()
{
}

void me::Transform::Initialize()
{
}

void me::Transform::Update()
{
}

void me::Transform::Lateupdate()
{
}

void me::Transform::Render(HDC hdc)
{
}
