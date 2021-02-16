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
	Person* p; //Person 배열 포인터
	string name;
	int size; //Person 배열 크기, 가족 구성원수
public:
	Family(string name, int size) {
		this->name = name;
		this->size = size;
		this->p = new Person[size]; //아 또 Person()하고있었네 배열이니까 당연히 []로 해야하는게 당연하잖아

	}; //size 개수만큼 Person 배열 동적 생성
	void show() {
		cout << name << "가족은 다음과 같이 " << size << "명 입니다." << endl; //모든 가족 구성원 출력
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
	Family* simpson = new Family("Simpson", 3); //3명으로 구성된 Simpson 가족
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}