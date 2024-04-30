#include "meBoxCollider2D.h"
#include "meTransform.h"
#include "meGameobject.h"
#include "meRenderer.h"
#include "meCamera.h"

namespace me
{
	BoxCollier2D::BoxCollier2D()
		: Collider(enums::eColliderType::Rect2D)
	{
	}

	BoxCollier2D::~BoxCollier2D()
	{
	}

	void BoxCollier2D::Initialize()
	{
	}

	void BoxCollier2D::Update()
	{
	}

	void BoxCollier2D::Lateupdate()
	{
	}

	void BoxCollier2D::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);


		Rectangle(hdc, pos.x+ offset.x, pos.y+ offset.y, pos.x + offset.x+ 100* Getsize().x, pos.y + offset.y + 100*Getsize().y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}
