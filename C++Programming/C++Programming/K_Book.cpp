#include <iostream>
using namespace std;
//기존 NULL은 문제 있어서 nullptr로 대체됐다함
class Book {
private:
	string title;
	int price;
public:
	Book(string title, int price) {
		this->title = title;
		this->price = price;
	}
	Book(const Book& book) { //복사생성자에는 const 붙이는게 좋다
		this->title = book.title;
		this->price = book.price;
	}
	void set(string title, int price) {
		this->title = title;
		this->price = price;
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};
int main(void) {
	Book cpp("명품C++", 10000);
	Book java = cpp; //복사 생성자 호출됨
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}