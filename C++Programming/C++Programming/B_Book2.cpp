#include <iostream>
using namespace std;
//friend는 뭔지 까먹었음
/* 그래서 찾아봤는데 2종류가 있었음
* 1. 프렌드 클래스
* 2. 프렌드 함수
* 그중에서 이번에 사용해야 하는 프렌드 함수는 클래스 내에 친구로 등록할 외부함수 선언부를 등록하고
* 그 친구 함수는 클래스의 private, protected 멤버들까지 자유롭게 접근이 가능해지는 방식이다
* 그러므로 프렌드함수로 만들려면 기존에 작성해놨던 클래스 함수들을 외부로 뺀 후
* 그 선언부들만 클래스 내에 모아둬야한다
* 
* 그리고 그렇게만 한다고 되는게 아니라 기존에 전달인자로 피연산자 하나만 받았다면 이번엔 클래스 자체도 참조로 받도록 바꿔야한다는 점이다
*/
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

	friend bool operator ==(Book& book, int a);		//그래서 에러나던 것에 Book& book 전달인자를 추가하자 에러나던게 사라졌다
	friend bool operator ==(Book& book, string str);
	friend bool operator ==(Book& book, Book b);
};
bool operator ==(Book& book, int a)
{
	if (book.price == a)
		return true;
	else
		return false;
}
bool operator ==(Book& book, string str)
{
	if (book.title == str)
		return true;
	else
		return false;
}
bool operator ==(Book& book, Book b) {
	if (book.title == b.title && book.price == b.price && book.pages == b.pages)
		return true;
	else
		return false;
}
int main(void) {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000)cout << "정가 30000원" << endl; //price 비교
	if (a == "명품 C++")cout << "명품 C++입니다." << endl; //책 title 비교
	if (a == b) cout << "두 책이 같은 책입니다." << endl; //title, price, pages 모두 비교
}