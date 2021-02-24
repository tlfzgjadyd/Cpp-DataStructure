#include <iostream>
using namespace std;
class Color {
private:
	int r;
	int g;
	int b;
public:
	Color(){
		this->r = 0;
		this->g = 0;
		this->b = 0;
	}
	Color(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	void show() {
		cout << r << " " << g << " " << b << endl;
	}
	bool operator ==(const Color& c) {//이제 참조도 어느정도 익숙해졌으니 전달한 객체가 수정되지 말라고 const도 곁들여봤음
		if (this->r == c.r && this->g == c.g && this->b == c.b)//==비교 연산자는 c==fuchsia로 Color에서 호출하고 전달인자로 Color 하나 받으므로
			return true;										//굳이 밖으로 안빼고 멤버함수로 만들어줬다
		else
			return false;
	}
	friend Color operator+(const Color& c1, const Color& c2);//이제 참조도 어느정도 익숙해졌으니 전달한 객체가 수정되지 말라고 const도 곁들여봤음
};
Color operator+(const Color& c1, const Color& c2) { //이번 연산자 오버로딩은 구조가 기본생성자로 만든 c를 나중에 a+b 더한값으로 바꾸는 방식이었음
	int r = c1.r + c2.r;							//그래서 Color타입이 호출하고 전달인자로 Color타입 2개를 받아야하는 상황
	int g = c1.g + c2.g;							//일단 c=red+blue로 해놨으니 red+blud 연산의 결과로는 Color타입이 가야됨
	int b = c1.b + c2.b;							//평소처럼 Color&를 리턴하려고도 해봤지만 에러나서 *도 달아봤지만 에러나서
	return Color(r, g, b);							//어짜피 c도 일반 Color일텐데 연산 결과도 일반 Color여도 되지 않나 생각이 들었음
}													//그래서 아예 c1, c2값 수정은 건드리지 않고 새로운 변수 만들고 리턴할때 새 Color 만들어서 일반 Color를 리턴했다
int main(void) {									//아마 여기서 참조리턴이 안되는 이유는 함수 내에서 새로 만든 Color객체는 함수 종료와 함께 메모리에서 사라지기 때문일것임
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show(); //색 값 출력
	Color fuchsia(255, 0, 255); 
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}