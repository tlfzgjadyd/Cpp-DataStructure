#include "I_Person.h"

int main(void) {
	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���"<<endl;
	I_Person* people = new I_Person[3];  //������ = new �迭
	string name="";
	string tel="";
	for (int i = 0; i < 3; i++)
	{
		cout << "��� " << i + 1 << ">> ";
		cin >> name >> tel;
		people[i].set(name, tel);
	}
	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++)
		cout << people[i].getName() << " ";

	cout << endl<< "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
	cin >> name;
	for (int i = 0; i < 3; i++)
	{
		if (people[i].getName() == name)
		{
			tel = people[i].getTel();
			break;
		}
	}
	cout << "��ȭ��ȣ�� " << tel;
}