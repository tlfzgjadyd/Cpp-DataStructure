#include <iostream>
using namespace std;

class Rectangle {
private:
	int x;
	int y;
	int width;
	int height;
public:
	Rectangle() {
		this->x = 1;//좌표는 양수만 처리하기
		this->y = 1;
		this->width = 0;
		this->height = 0;
	}
	Rectangle(int x, int y, int width, int height) {
		if (x > 0 && y > 0) {//좌표는 양수만 처리하기
			cout << "생성자 : 직사각형을 생성합니다" << endl;
			this->x = x;
			this->y = y;
		}
		else
		{
			cout << "좌표에 양수가 아닌 것이 섞여있어 1로 바꿔 생성합니다" << endl;
			this->x = 1;//좌표는 양수만 처리하기
			this->y = 1;
		}
		if (width > 0 && height > 0)
		{
			this->width = width;
			this->height = height;
		}
		else
		{
			this->width = 0;
			this->height = 0;
		}
	}
	~Rectangle() {
	}
	void read() {
		cout << "x, y, width, height를 입력하시오 : ";
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
		cin >> x >> y >> width >> height;
		if (x > 0 && y > 0) {//좌표는 양수만 처리하기
			cout << "생성자 : 직사각형을 생성합니다" << endl;
			this->x = x;
			this->y = y;
		}
		else
		{
			cout << "좌표에 양수가 아닌 것이 섞여있어 1로 바꿔 생성합니다" << endl;
			this->x = 1;//좌표는 양수만 처리하기
			this->y = 1;
		}
		if (width > 0 && height > 0)
		{
			this->width = width;
			this->height = height;
		}
		else
		{
			this->width = 0;
			this->height = 0;
		}
	}
	void print() {
		cout << "직사각형의 정보 : 이 직사각형은 x=" << x << ", y=" << y << ",width=" << width << ", height=" << height << "입니다." << endl;
	}
	int getArea() {
		return width * height;
	}

	Rectangle operator +(Rectangle& r) {// + 기호는 합집합 --> 2개의 사각형을 내부에 포함하는 가장작은 사각형의 시작좌표 및 길이와, 높이를 계산 ( 강의내용 참고 )
		int smallX = 0;
		int bigX = 0;
		int bigWidth = 0;

		int smallY = 0;
		int bigY = 0;
		int bigHeight = 0;

		if (this->x < r.x)
		{
			smallX = this->x;
			bigX = r.x;
			bigWidth = r.width;
		}
		else
		{
			smallX = r.x;
			bigX = this->x;
			bigWidth = this->width;
			if (this->x == r.x)
			{
				if (this->width > r.width)
					bigWidth = this->width;
				else
					bigWidth = r.width;
			}
		}
		if (this->y < r.y)
		{
			smallY = this->y;
			bigY = r.y;
			bigHeight = r.height;
		}
		else
		{
			smallY = r.y;
			bigY = this->y;
			bigHeight = this->height;
			if (this->y == r.y)
			{
				if (this->height > r.height)
					bigHeight = this->height;
				else
					bigHeight = r.height;
			}
	}
		return Rectangle(smallX, smallY, bigX - smallX + bigWidth, bigY - smallY + bigHeight);
	}
	Rectangle operator /(Rectangle& r) {//  / 기호는 교집합 --> 2개의 사각형이 교차되는 부분의 사각형의 시작좌표 및 길이와 높이를 계산 ( 강의내용 참고 )
		int smallX = 0;
		int smallWidth = 0;
		int bigX = 0;

		int smallY = 0;
		int smallHeight = 0;
		int bigY = 0;

		if (this->x < r.x)
		{
			smallX = this->x;
			bigX = r.x;
			smallWidth = this->width;
		}
		else
		{
			smallX = r.x;
			bigX = this->x;
			smallWidth = r.width;
			if (this->x == r.x)
			{
				if (this->width > r.width)
					smallWidth = r.width;
				else
					smallWidth = this->width;
			}
		}
		if (this->y < r.y)
		{
			smallY = this->y;
			smallHeight = this->height;
			bigY = r.y;
		}
		else
		{
			smallY = r.y;
			bigY = this->y;
			smallHeight - r.height;
			if (this->y == r.y)
			{
				if (this->height > r.height)
					smallHeight = r.height;
				else
					smallHeight = this->height;
			}
		}
		if ((smallX + smallWidth < bigX) || (smallY + smallHeight < bigY))//안만나는 경우
		{
			return Rectangle(1, 1, 0, 0);//좌표는 양수만 가능
		}
		else if ((smallX + smallWidth == bigX) && (smallY + smallHeight == bigY)) {//딱붙은 경우
			return Rectangle(1, 1, 0, 0);//좌표는 양수만 가능
		}
		else {//겹치는 경우
			return Rectangle(bigX, bigY, smallX + smallWidth - bigX, smallY + smallHeight - bigY);
		}
	}
	friend bool operator ==(Rectangle& r1, Rectangle& r2);
	friend ostream& operator<<(ostream& cout, Rectangle r);// << 기호는 출력 --> cout 를 통해 출력할수 있도록 연산자를 구현 ( 강의내용 및 교재 참고 )
};
ostream& operator<<(ostream& cout, Rectangle r)
{
	if (r.width == 0 || r.height == 0)
		cout << "직사각형의 정보 : 이 직사각형은 너비나 높이가 0입니다" << endl;
	else
		cout << "직사각형의 정보 : 이 직사각형은 x=" << r.x << ", y=" << r.y << ",width=" << r.width << ", height=" << r.height << "입니다."<<endl;
	return cout;
}
bool operator ==(Rectangle& r1, Rectangle& r2) {// == 기호는 동일성 판단 --> 2개의 사각형이 동일한 좌표 및 길이와 높이를 가지고 있는지를 판단 ( 교재 참고 )
	if ((r1.x == r2.x) && (r1.y == r2.y) && (r1.width == r2.width) && (r1.height == r2.height))
		return true;
	else
		return false;
}
int main(void) {
	cout << "기본 생성자로 직사각형 r1을 생성합니다" << endl;
	Rectangle r1;
	r1.print();
	r1.read();
	r1.print();
	cout<<"이 직사각형의 넓이 : "<<r1.getArea()<<endl<<endl;

	cout << "인자를 포함한 생성자로 직사각형 r2를 생성합니다" << endl;
	Rectangle r2(3, 3, 2, 2);
	r2.print();
	cout << "이 직사각형의 넓이 : "<< r2.getArea()<<endl << endl;

	cout << "음수를 인자로 주고 직사각형 r3 생성을 시도합니다 " << endl;
	Rectangle r3(-1, -2, -3, -4);
	r3.print();
	cout << "이 직사각형의 넓이 : " << r3.getArea()<<endl << endl;

	cout << endl<<"=========================================" << endl;
	cout << "+연산자로 r1과 r2의 합집합을 구하자 "<<endl;
	cout << r1 + r2;
	cout << "=========================================" << endl;
	cout << "/연산자로 r1과 r2의 교집합을 구하자 "<<endl;
	cout << r1 / r2;
	cout << "=========================================" << endl;
	cout << "==연산자로 r1과 r2가 같을지 구하자 "<<endl;
	cout << (r1 == r2)<<endl;
	cout << "=========================================" << endl;
	cout<< "<<연산자로 r1과 r2를 출력해보자 " << endl;
	cout << r1 << endl << r2 << endl;
}