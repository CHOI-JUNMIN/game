#include "Component.h"

namespace me
{
	Component::Component(enums::eComponentType type)
		:mType(type)
	{

	}
	Component::~Component()
	{
	
	}
	void Component::Initialize()
	{
	}
	void Component::update()
	{
	}
	void Component::Lateupdate()
	{
	}
	void Component::Render(HDC hdc)
	{
	}
}