#include <iostream>
#include <string>
using namespace std;
//이번 문제는 Book클래스와 연관된 연산자 오버로딩은 맞는데
//호출하는쪽이 string이고 전달인자가 Book인걸로 보였음
//그럼 string클래스를 오버라이딩해야하나 싶었는데 
//생각해보니까 피연산자 위치 바뀌어도 먹히도록 하는 방법이 있었던것같음
//->멤버 함수로 오버로딩 할 경우 피연산자의 순서가 정해져있기에 문제가 된다
//->따라서 전역변수로 연산자 오버로딩을 하는 방식을 택해야 한다
//  전역함수로 만들 경우 피연산자 2개를 받는게 허용됨
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
	friend bool operator <(string b, Book& book);
};
bool operator <(string b, Book& book) {//메인함수에서 사용한 순서가 b<a로 string 연산자 Book이었기 때문에 전달인자의 순서도 맞춰줘야 에러가 안난다
	for (int i = 0; (i < book.title.length() || i < b.length()); i++)//전역함수로 바뀌면서 그대로 private프로퍼티를 사용하는 대신 getTitle()함수로 가져와야 한다
	{																 //이게 싫기 때문에 Book전달인자 받는것과는 별개로 private 사용 허락해달라고 프렌드 함수로 등록하는것
		if ((int)(book.title[i]) < (int)(b[i]))
			return true;
	}
	return false;
}
int main(void) {
	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세요>>";
	getline(cin, b); //키보드로부터 문자열로 책 이름을 입력받음
	if (b < a)
		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
}