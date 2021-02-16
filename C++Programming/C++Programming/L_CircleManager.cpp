#include <iostream>
#include <string>
using namespace std;
class Circle {
private :
	int radius=0; 
	string name="";
public:
	void setCircle(string name, int radius) {
		this->name = name;
		this->radius = radius;
	}
	double getArea() {
		return 3.14* radius * radius;
	}
	string getName() {
		return name;
	}
};
class CircleManager {
private:
	Circle* p;
	int size;
public:
	CircleManager(int size) {
		this->size = size;
		p = new Circle[size];
		string name="";
		int radius=0;
		for (int i = 0; i < size; i++) {
			cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
			cin >> name >> radius;
			p[i].setCircle(name, radius);
		}
	}
	void searchByName() {
		cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
		string select = "";
		cin >> select;
		for (int i = 0; i<size; i++) {
			if (p[i].getName() == select)
				cout << p[i].getName() << "�� ������ " << p[i].getArea()<<endl;
		}
	}
	void serarchByArea() {
		cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
		int select = 0;
		cin >> select;
		cout << select << "���� ū ���� �˻��մϴ�." << endl;
		for (int i = 0; i < size; i++) {
			if (p[i].getArea() > select) {
				cout << p[i].getName()<< "�� ������ " << p[i].getArea() << ", ";
			}
		}
	}
	~CircleManager() {
		for (int i = 0; i < size; i++) {
			p[i].setCircle("", 0);
		}
		delete[] p;
	}
};
int main(void) {
	cout << "���� ���� >> ";
	int select = 0;
	cin >> select;
	CircleManager cm(select);
	cm.searchByName();
	cm.serarchByArea();
	return 0;
}