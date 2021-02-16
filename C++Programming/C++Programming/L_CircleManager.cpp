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
			cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
			cin >> name >> radius;
			p[i].setCircle(name, radius);
		}
	}
	void searchByName() {
		cout << "검색하고자 하는 원의 이름 >> ";
		string select = "";
		cin >> select;
		for (int i = 0; i<size; i++) {
			if (p[i].getName() == select)
				cout << p[i].getName() << "의 면적은 " << p[i].getArea()<<endl;
		}
	}
	void serarchByArea() {
		cout << "최소 면적을 정수로 입력하세요 >> ";
		int select = 0;
		cin >> select;
		cout << select << "보다 큰 원을 검색합니다." << endl;
		for (int i = 0; i < size; i++) {
			if (p[i].getArea() > select) {
				cout << p[i].getName()<< "의 면적은 " << p[i].getArea() << ", ";
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
	cout << "원의 개수 >> ";
	int select = 0;
	cin >> select;
	CircleManager cm(select);
	cm.searchByName();
	cm.serarchByArea();
	return 0;
}