#include <iostream>
using namespace std;
//언뜻 보면 코드에 문제 없는데 왜 수정이 안되지 착각할수도 있지만 사실 참조로 안보내고 값에 의한 호출 하면 값 수정해도 수정안됨
//그러므로 class함수 안건드리고 increaseBy만 수정해서 올바른 값을 나오게 하려면 전달인자를 &로 바꿔야한다
class Circle {
private:
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};
void increaseBy(Circle& a, Circle& b){
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}
int main(void) {
	Circle x(10), y(5);
	increaseBy(x, y); //x의 반지름이 15인 원을 만들고자 한다
	x.show(); //"반지름이 15인 원"을 출력한다
}