#include "A_Color.h"

//객체에서 바로 클래스메소드 사용하는 경우면 .으로 이어주지만 포인터 p에 할당한 후 사용하려 했기 때문에 ->로 사용하는거였지
int main(void) {
	A_Color screenColor(255, 0, 0); //빨간색의 screenColor 객체 생성
	A_Color* p; //Color 타입의 포인터 변수 p 선언
	p = &screenColor; //(1) p가 screenColor의 주소를 가지도록 코드 작성
	p->show();//(2) p와 show()를 이용하여 screenColor 색 출력
	A_Color colors[3];//(3)Color의 일차원 배열 colors 선언, 원소는 3개
	p = colors;//(4) p가 colors 배열을 가리키도록 코드 작성

	//(5) p와 setColor()를 이용하여 colorsp[0], colors[1], colors[2]가 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
	p[0].setColor(255, 0, 0);
	p[1].setColor(0, 255, 0);
	p[2].setColor(0, 0, 255);

	//(6) p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력, for 문 이용
	for (int i = 0; i < 3; i++) {
		p[i].show();
	}
}