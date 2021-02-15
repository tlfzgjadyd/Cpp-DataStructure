#include "I_Person.h"

int main(void) {
	cout << "이름과 전화 번호를 입력해 주세요"<<endl;
	I_Person* people = new I_Person[3];  //포인터 = new 배열
	string name="";
	string tel="";
	for (int i = 0; i < 3; i++)
	{
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> tel;
		people[i].set(name, tel);
	}
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++)
		cout << people[i].getName() << " ";

	cout << endl<< "전화번호 검색합니다. 이름을 입력하세요>>";
	cin >> name;
	for (int i = 0; i < 3; i++)
	{
		if (people[i].getName() == name)
		{
			tel = people[i].getTel();
			break;
		}
	}
	cout << "전화번호는 " << tel;
}