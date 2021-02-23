#include <iostream>
#include <string>
using namespace std;
//�̹� ������ BookŬ������ ������ ������ �����ε��� �´µ�
//ȣ���ϴ����� string�̰� �������ڰ� Book�ΰɷ� ������
//�׷� stringŬ������ �������̵��ؾ��ϳ� �;��µ� 
//�����غ��ϱ� �ǿ����� ��ġ �ٲ� �������� �ϴ� ����� �־����Ͱ���
//->��� �Լ��� �����ε� �� ��� �ǿ������� ������ �������ֱ⿡ ������ �ȴ�
//->���� ���������� ������ �����ε��� �ϴ� ����� ���ؾ� �Ѵ�
//  �����Լ��� ���� ��� �ǿ����� 2���� �޴°� ����
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
	friend bool operator <(string b, Book& book);
};
bool operator <(string b, Book& book) {//�����Լ����� ����� ������ b<a�� string ������ Book�̾��� ������ ���������� ������ ������� ������ �ȳ���
	for (int i = 0; (i < book.title.length() || i < b.length()); i++)//�����Լ��� �ٲ�鼭 �״�� private������Ƽ�� ����ϴ� ��� getTitle()�Լ��� �����;� �Ѵ�
	{																 //�̰� �ȱ� ������ Book�������� �޴°Ͱ��� ������ private ��� ����ش޶�� ������ �Լ��� ����ϴ°�
		if ((int)(book.title[i]) < (int)(b[i]))
			return true;
	}
	return false;
}
int main(void) {
	Book a("û��", 20000, 300);
	string b;
	cout << "å �̸��� �Է��ϼ���>>";
	getline(cin, b); //Ű����κ��� ���ڿ��� å �̸��� �Է¹���
	if (b < a)
		cout << a.getTitle() << "�� " << b << "���� �ڿ� �ֱ���!" << endl;
}