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
	bool operator ==(int a)//처음엔 전체 다 받을 수 있게 제일 상위타입으로 받아야하나 생각했지만 그냥 여러개 오버로딩해서 작성하는게 하나하나 실행에는 좋지 않을까했음
	{						//그리고 이전 예제에서 Book&타입으로 리턴했던 이유는 딱히 리턴할게 없는데 내부작동 위해서였고 이번껀 ==의 결과를 알려줘야 하니까 bool리턴됐음
		if (this->price == a)
			return true;
		else
			return false;
	}
	bool operator ==(string str)
	{
		if (this->title == str)
			return true;
		else
			return false;
	}
	bool operator ==(Book b) {
		if (this->title == b.title && this->price == b.price && this->pages == b.pages)
			return true;
		else
			return false;
	}
};
int main(void) {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000)cout << "정가 30000원" << endl; //price 비교
	if (a == "명품 C++")cout << "명품 C++입니다." << endl; //책 title 비교
	if (a == b) cout << "두 책이 같은 책입니다." << endl; //title, price, pages 모두 비교
}