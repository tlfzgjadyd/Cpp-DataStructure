#include <iostream>
using namespace std;
class Book {
private:
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	bool operator !() { //이번에도 이전에 하던대로 operator 타입 전달인자 리턴타입 본문 순서대로 작성하려 했음
		if (this->price == 0)  //!뒤에 책이 오길래 전달인자로 책을 받나 했더니 에러가 나는거임
			return true;   //보니까 !는 단항연산자라 안된대 즉 전달인자를 안받고 this의 price로 판단해야한다는 뜻이지
		else
			return false;	//이처럼 연산자 오버로딩은 형태가 매우 다양하다
	}
};
int main(void) {
	Book book("벼룩시장", 0, 50); //가격은 0
	if (!book) cout << "공짜다" << endl;
}