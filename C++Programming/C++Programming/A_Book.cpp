#include <iostream>
using namespace std;
//�̹� �ܿ������� ������� ������ �ߺ��� ���� �ǽ��Ұ���
class Book {
private:
	string title;
	int price;
	int pages;
public :
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }
	Book& operator +=(int num) {  //�� �Ⱥ��� �ѹ��� ����س¾� ����س� ������ ������ ����
		this->price += num;       //1. operator��� �̸��� �ʿ��ߴ�
		return *this;			  //2. � �����ڸ� �����ε� �Ұ��� �����ڸ� ������ߴ� �׷��� +��µ� �������� +=�� �غô��� �ߵ���
								  //3. �������ڷ� �ǿ������� ������ �޾ƾ��ϰ��� ���⼱ int���� �ǿ����ڷ� ����ϹǷ� int�� �������ڸ� �޾Ҵ�
								  //4. �������� �ʿ��� ������ ����
								  //5. ���ϰ��� �ʿ��ϵ��� �����߱淡 ������ �����ϱ� �ؾ��ϴµ� ���⼭ ���� ����� �����ϴ°� �̻��ϰ�
								  //   �ڱ��ڽ��� �����ϴ°� ���ö��� �ٵ� �׳� Ŭ���������� �ƴ϶� ���� �پ �����ϴ°ſ��� �׷��� ���� ���������� �� ����
								  //   *this�� ��������
	}
	Book& operator -=(int num) {
		this->price -= num;
		return *this;
	}
};
int main(void) {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500; //å a�� ���� 500�� ����
	b -= 500; //å b�� ���� 500�� ����
	a.show();
	b.show();
}