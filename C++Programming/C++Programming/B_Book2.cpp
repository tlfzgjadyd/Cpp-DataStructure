#include <iostream>
using namespace std;
//friend�� ���� ��Ծ���
/* �׷��� ã�ƺôµ� 2������ �־���
* 1. ������ Ŭ����
* 2. ������ �Լ�
* ���߿��� �̹��� ����ؾ� �ϴ� ������ �Լ��� Ŭ���� ���� ģ���� ����� �ܺ��Լ� ����θ� ����ϰ�
* �� ģ�� �Լ��� Ŭ������ private, protected �������� �����Ӱ� ������ ���������� ����̴�
* �׷��Ƿ� �������Լ��� ������� ������ �ۼ��س��� Ŭ���� �Լ����� �ܺη� �� ��
* �� ����ε鸸 Ŭ���� ���� ��Ƶ־��Ѵ�
* 
* �׸��� �׷��Ը� �Ѵٰ� �Ǵ°� �ƴ϶� ������ �������ڷ� �ǿ����� �ϳ��� �޾Ҵٸ� �̹��� Ŭ���� ��ü�� ������ �޵��� �ٲ���Ѵٴ� ���̴�
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
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }

	friend bool operator ==(Book& book, int a);		//�׷��� �������� �Ϳ� Book& book �������ڸ� �߰����� ���������� �������
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
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000)cout << "���� 30000��" << endl; //price ��
	if (a == "��ǰ C++")cout << "��ǰ C++�Դϴ�." << endl; //å title ��
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl; //title, price, pages ��� ��
}