#include <iostream>
#include <string>
using namespace std;
class Person {
private :
	string name;
public:
	Person() {}
	Person(string name) { this->name = name;}
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};
class Family {
	Person* p; //Person �迭 ������
	string name;
	int size; //Person �迭 ũ��, ���� ��������
public:
	Family(string name, int size) {
		this->name = name;
		this->size = size;
		this->p = new Person[size]; //�� �� Person()�ϰ��־��� �迭�̴ϱ� �翬�� []�� �ؾ��ϴ°� �翬���ݾ�

	}; //size ������ŭ Person �迭 ���� ����
	void show() {
		cout << name << "������ ������ ���� " << size << "�� �Դϴ�." << endl; //��� ���� ������ ���
		for (int i = 0; i < size; i++) {
			cout << p[i].getName() << "    ";
		}
	}
	void setName(int index, string name) {
		p[index].setName(name);
	}
	~Family() {
		delete[] p;
		this->name = "";
		this->size = 0;
	}
};
int main(void) {
	Family* simpson = new Family("Simpson", 3); //3������ ������ Simpson ����
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}