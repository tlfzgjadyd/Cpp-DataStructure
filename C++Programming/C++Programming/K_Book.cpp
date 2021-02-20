#include <iostream>
using namespace std;
//���� NULL�� ���� �־ nullptr�� ��ü�ƴ���
class Book {
private:
	string title;
	int price;
public:
	Book(string title, int price) {
		this->title = title;
		this->price = price;
	}
	Book(const Book& book) { //��������ڿ��� const ���̴°� ����
		this->title = book.title;
		this->price = book.price;
	}
	void set(string title, int price) {
		this->title = title;
		this->price = price;
	}
	void show() { cout << title << ' ' << price << "��" << endl; }
};
int main(void) {
	Book cpp("��ǰC++", 10000);
	Book java = cpp; //���� ������ ȣ���
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}