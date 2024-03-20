#include "Gameobject.h"

namespace me
{
	Gameobject::Gameobject()
	{

	}
	Gameobject::~Gameobject()
	{

	}
	void Gameobject::update()
	{

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)  //'w' ->알파벳도 가능
		{
			mX -= 0.01;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01;
		}
		
	}
	void Gameobject::Lateupdate()
	{

	}
	void Gameobject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); //파랑 브러쉬 생성

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush); //파랑 브러쉬 DC에 선택, 흰색 브러쉬 반환
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));   //테두리 만들기
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); //사각형 만드는 함수

		//SelectObject(mHdc, oldbrush); //흰색 브러쉬 선택
		//DeleteObject(brush);  //파랑 삭제

		//HBRUSH brush1 = CreateSolidBrush(RGB(0, 255, 255));  //민트 브러쉬 생성
		//HBRUSH oldbrush1 = (HBRUSH)SelectObject(mHdc, brush1);


		//Ellipse(mHdc, 200, 200, 400, 400); //원 만드는 함수
		//SelectObject(mHdc, oldbrush1); //흰색 브러쉬 선택
		//DeleteObject(brush1);  //민트 삭제
		//
		//SelectObject(mHdc, oldPen); //흰 테두리 선택
		//DeleteObject(redPen); //빨강 삭제
		//// DC란 화면에 출력에 필요한 모든 정보를 가지는 데이터 구조체, GDI모듈에 의해 관리됨 ex) 글꼴 폰트 선의 굵기등등 
		//// 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업을 진행할 수 있다.
		//// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

		//Rectangle(mHdc,500, 500, 600, 600);
	}
}