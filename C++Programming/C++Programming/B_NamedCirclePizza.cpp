#include <iostream>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};
class NamedCircle : public Circle {//또다른 매우 중요한 다른점이 있었다 코틀린은 그냥 자식 : 부모 하면 되는데 c++는 그렇게 하면 암묵적으로 private 상속으로 인지하기 때문에
								    //자식클래스 내부에선 부모 클래스 함수를 쓸 수 있지만 바깥에서는 자식클래스 객체를 통해 부모클래스 함수를 호출할 수 없어진다
									//뭔가 처음에 배울때랑 많이 달라진것같음 어쨌든 문법이 그렇게 다른 언어들이랑 서로 비슷해져갔고
									//자식 : public 부모 로 상속해줄 경우 바깥에서도 내가 원래 알던것처럼 부모의 함수 호출이 가능해진다
private:
	string name;
public:
	NamedCircle(int radius=0) : Circle(radius) {
		;
	}
	void set(int radius, string name) { 
		setRadius(radius);
		this->name = name;  
	} //이거 원래 안해줬었거든 처음에 세팅을 반지름만 하는줄 알고 있는 상태였는데
		//상속받았으니까 Circle의 public함수를 NamedCircle도 가지잖아 근데 에러나는거임
		 //즉 public 없이 자식:부모로만 상속받은 자식은 내부적으론 부모의 접근지정자 허락된 함수에 접근이 가능하지만 바깥에선 불가능하기에 자식 : public 부모로 해야했음
											
	string getName() { return name; }
};
int main(void) {
	NamedCircle pizza[5];//여기서 에러났던 이유는 NamedCircle에 별거 필요 없는줄 알고 private: public: 안해놨다가 그냥 생성자 써서 private:로 자동인식 됐기 때문
	int radius = 0;
	string name = "";
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ">> ";
		cin >> radius;
		cin >> name;
		pizza[i].set(radius, name);
	}
	int biggest = 0;
	for (int i = 0; i < 4; i++) {
		if (pizza[i].getArea() < pizza[i + 1].getArea())
			biggest = i+1;
	}
	cout << "가장 면적이 큰 피자는 " << pizza[biggest].getName() << "입니다" << endl;
}