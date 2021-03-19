#include <iostream>
using namespace std;
/*1. 시작점의 좌표(x,y)와 길이(width) 와 높이(height)로 표현되는 Rectangle 클래스를 작성.

2. 기본생성자 및 소멸자(파괴자) 작성 ( 추가 생성 및 소멸자를 구현해도 됨 )

3. Rectangle 클래스의 데이터를 입력받는 read 함수 작성

4. Rectangle 클래스의 데이터를 출력하는 print 함수 작성

5. +, /, ==, << 4개의 연산자 오버로딩을 구현

  5.1 + 기호는 합집합 --> 2개의 사각형을 내부에 포함하는 가장작은 사각형의 시작좌표 및 길이와, 높이를 계산 ( 강의내용 참고 )

  5.2 / 기호는 교집합 --> 2개의 사각형이 교차되는 부분의 사각형의 시작좌표 및 길이와 높이를 계산 ( 강의내용 참고 )

  5.3 == 기호는 동일성 판단 --> 2개의 사각형이 동일한 좌표 및 길이와 높이를 가지고 있는지를 판단 ( 교재 참고 )

  5.4 << 기호는 출력 --> cout 를 통해 출력할수 있도록 연산자를 구현 ( 강의내용 및 교재 참고 )

** 5.5 넓이를 구하는 getArea()함수 작성 ( 강의내용 참고 )
**좌표는 양수만 처리하기
*/
class Rectangle {
private:
	int x;
	int y;
	int width;
	int height;
public:
	Rectangle(int x, int y, int width, int height) {
		if (x > 0 && y > 0 && width > 0 && height > 0) {
			cout << "생성자 : 직사각형을 생성합니다" << endl;
			this->x = x;
			this->y = y;
			this->width = width;
			this->height = height;
		}
		else
		{
			cout << "음수가 섞여있어 생성이 불가능합니다" << endl;
		}
	}
	void read(int data) {

	}
	void print() {
		cout << "직사각형의 정보 : 이 직사각형은 x=" << x << ", y=" << y << ",width=" << width << ", height=" << height << "입니다." << endl;
	}
	int getArea() {
		return width * height;
	}
	~Rectangle() {
		cout << "소멸자 : 직사각형을 제거합니다" << endl;
	}
	Rectangle& operator +(Rectangle& r) {// + 기호는 합집합 --> 2개의 사각형을 내부에 포함하는 가장작은 사각형의 시작좌표 및 길이와, 높이를 계산 ( 강의내용 참고 )
		//유형 판별하기
		Rectangle answer(x2, y2, w2, h2);
		return answer;
	}
	Rectangle& operator /(Rectangle& r) {//  / 기호는 교집합 --> 2개의 사각형이 교차되는 부분의 사각형의 시작좌표 및 길이와 높이를 계산 ( 강의내용 참고 )

	}
	bool operator ==(Rectangle& r) {// == 기호는 동일성 판단 --> 2개의 사각형이 동일한 좌표 및 길이와 높이를 가지고 있는지를 판단 ( 교재 참고 )
		if ((this->x == r.x) && (this->y == r.y) && (this->width == r.width) && (this->height == r.height))
			return true;
		else
			return false;
	}
	Rectangle& operator<<(ostream& cout) {// << 기호는 출력 --> cout 를 통해 출력할수 있도록 연산자를 구현 ( 강의내용 및 교재 참고 )
		print();
		return *this;
	}

};
int main(void) {
	cout << "직사각형의 x, y, width, height을 입력하시오>>";
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	cin >> x >> y >> width >> height;
}