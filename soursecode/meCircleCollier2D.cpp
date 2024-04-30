#include "meCircleCollier2D.h"
#include "meTransform.h"
#include "meGameobject.h"
#include "meRenderer.h"
#include "meCamera.h"

namespace me
{
	CircleCollier2D::CircleCollier2D()
		: Collider(enums::eColliderType::Circle2D)
	{
	}
	CircleCollier2D::~CircleCollier2D()
	{
	}
	void CircleCollier2D::Initialize()
	{
	}
	void CircleCollier2D::Update()
	{
	}
	void CircleCollier2D::Lateupdate()
	{
	}
	void CircleCollier2D::Render(HDC hdc)
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

		Vector2 rightBottom;
		rightBottom.x = pos.x + offset.x + 100 * Getsize().x;
		rightBottom.y = pos.y + offset.y + 100 * Getsize().y;

		Ellipse(hdc, pos.x + offset.x, pos.y + offset.y, rightBottom.x, rightBottom.y);
		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}