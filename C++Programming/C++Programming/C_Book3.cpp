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

	bool operator !() { //�̹����� ������ �ϴ���� operator Ÿ�� �������� ����Ÿ�� ���� ������� �ۼ��Ϸ� ����
		if (this->price == 0)  //!�ڿ� å�� ���淡 �������ڷ� å�� �޳� �ߴ��� ������ ���°���
			return true;   //���ϱ� !�� ���׿����ڶ� �ȵȴ� �� �������ڸ� �ȹް� this�� price�� �Ǵ��ؾ��Ѵٴ� ������
		else
			return false;	//��ó�� ������ �����ε��� ���°� �ſ� �پ��ϴ�
	}
};
int main(void) {
	Book book("�������", 0, 50); //������ 0
	if (!book) cout << "��¥��" << endl;
}