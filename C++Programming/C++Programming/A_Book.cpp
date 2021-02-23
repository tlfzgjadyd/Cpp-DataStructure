#include <iostream>
using namespace std;
//이번 단원에서는 프랜드와 연산자 중복에 대해 실습할거임
class Book {
private:
	string title;
	int price;
	int pages;
public :
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	Book& operator +=(int num) {  //헐 안보고 한번에 기억해냈어 기억해낸 순서는 다음과 같다
		this->price += num;       //1. operator라는 이름이 필요했다
		return *this;			  //2. 어떤 연산자를 오버로딩 할건지 연산자를 써줘야했다 그래서 +썼는데 에러나서 +=로 해봤더니 잘됐음
								  //3. 전달인자로 피연산자인 상대방을 받아야하겠지 여기선 int형을 피연산자로 사용하므로 int형 전달인자를 받았다
								  //4. 본문에서 필요한 연산을 수행
								  //5. 리턴값이 필요하도록 에러뜨길래 뭔가를 리턴하긴 해야하는데 여기서 연산 결과를 리턴하는건 이상하고
								  //   자기자신을 리턴하는게 떠올랐음 근데 그냥 클래스리턴이 아니라 뭐가 붙어서 리턴하는거였지 그래서 참조 리턴형으로 한 다음
								  //   *this를 리턴했음
	}
	Book& operator -=(int num) {
		this->price -= num;
		return *this;
	}
};
int main(void) {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500; //책 a의 가격 500원 증가
	b -= 500; //책 b의 가격 500원 감소
	a.show();
	b.show();
}