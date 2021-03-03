#include <iostream>
using namespace std;
class Circle {
private://자식이 radius 사용하긴 하지만 사용할 때에는 모두 Circle 통해서 접근하기에 protected로 안해줘도됨
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};
class NamedCircle : Circle {//헐 뭐야 원래 이랬나? 원래 자바랑 똑같지 않았나? 상속하는 방식이 코틀린처럼됐는데?
private:
	string name;
public:
	NamedCircle(int radius, string name) :Circle(radius){//뭐야 이부분도 코틀린처럼 바뀌었어 아니면 두개 배운 간격이 멀어서 똑같은데 내가 눈치를 못챘던건가 완전히 똑같은데
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;//getRadius는 부모의 함수이긴 하지만 public으로 상속받았기에 별도의 이름 사용 없이도 호출 가능 super는 자바만의 것이었나봐
	}
};
int main(void) {
	NamedCircle waffle(3, "waffle");//반지름이 3이고 이름이 waffle인 원
	waffle.show();
}