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
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }
	bool operator ==(int a)//ó���� ��ü �� ���� �� �ְ� ���� ����Ÿ������ �޾ƾ��ϳ� ���������� �׳� ������ �����ε��ؼ� �ۼ��ϴ°� �ϳ��ϳ� ���࿡�� ���� ����������
	{						//�׸��� ���� �������� Book&Ÿ������ �����ߴ� ������ ���� �����Ұ� ���µ� �����۵� ���ؼ����� �̹��� ==�� ����� �˷���� �ϴϱ� bool���ϵ���
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
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000)cout << "���� 30000��" << endl; //price ��
	if (a == "��ǰ C++")cout << "��ǰ C++�Դϴ�." << endl; //å title ��
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl; //title, price, pages ��� ��
}