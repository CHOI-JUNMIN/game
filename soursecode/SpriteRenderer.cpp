#include "SpriteRenderer.h"
#include "Gameobject.h"
#include "Transform.h"

me::SpriteRenderer::SpriteRenderer()
{
}

me::SpriteRenderer::~SpriteRenderer()
{
}

void me::SpriteRenderer::Initialize()
{
}

void me::SpriteRenderer::update()
{
}

void me::SpriteRenderer::Lateupdate()
{
}

void me::SpriteRenderer::Render(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255,0,255)); //파랑 브러쉬 생성
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush); //파랑 브러쉬 DC에 선택, 흰색 브러쉬 반환
	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));   //테두리 만들기
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen); //흰 테두리 선택
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY()); //사각형 만드는 함수

	SelectObject(hdc, oldbrush); //흰색 브러쉬 선택
	
	DeleteObject(brush);  //파랑 삭제
	DeleteObject(redPen); //빨강 삭제

	//// DC란 화면에 출력에 필요한 모든 정보를 가지는 데이터 구조체, GDI모듈에 의해 관리됨 ex) 글꼴 폰트 선의 굵기등등 
	//// 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업을 진행할 수 있다.
	//// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
}
