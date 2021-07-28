//�˹ٸ� �ϱ� ���� �ܿ����ϴ� �޴� ���� ������
#include <iostream>
#include <random>
#define MAX_MENU_NUM 7
#define MAX_DAY_NUM 3
using namespace std;
bool isDayPractice(int select);
bool isQuit(int select);
void doDayPractice(int day, string* menu, string* answer, int* start, int* end);
int main(void) {
	string menu[MAX_MENU_NUM] = {"��������������", "����������", "Ŀ�� �ٳ��� ������", "Ŀ�� ������", "�� ũ����", "���� �� ũ����", "�ٳ��� �� ũ����"};
	string answer[MAX_MENU_NUM] = { "��������������", "����������", "Ŀ�� �ٳ��� ������", "Ŀ�� ������", "�� ũ����", "���� �� ũ����", "�ٳ��� �� ũ����" };
	int start[MAX_DAY_NUM] = {1, 3, 5};
	int end[MAX_DAY_NUM] = {2, 4, 6};
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<int> dis(0, 6);
	int num = 0;
	char select =' ';
	while (true) {
		num = dis(gen);
		cout << menu[num] << "��(��) �����Ͻÿ�" << endl;
		int select = (int)getchar();
		if (!isDayPractice(select))
		{
			cout << "======================================" << endl;
			cout << answer[num] << endl;
			cout << "======================================" << endl << endl << endl;
		}
		else
			doDayPractice(select-48, menu, answer, start, end);

	}
	return 0;
}
bool isDayPractice(int select)
{
	if (select == 10)
		return false;
	else
		return true;
}
bool isQuit(int select)
{
	if (select != 113)
		return false;
	else
		return true;
}
void doDayPractice(int day, string* menu, string* answer, int* start, int* end) {
	cout <<"<<<<< "<< day << "���� �н��� �����մϴ�" <<" >>>>>"<<endl<<endl;
	for(int i=start[day];i<end[day]+1;i++)
	{
		cout <<i-start[day]+1<<". "<< menu[i] << "��(��) �����Ͻÿ�" << endl;
		if (isQuit(getchar()))
			break;
		cout << "======================================" << endl;
		cout << answer[i] << endl;
		cout << "======================================" << endl << endl;
		if (isQuit(getchar()))
			break;
	}
	cout <<"<<<<< "<< day <<"���� �н��� �������ϴ�" <<" >>>>>"<< endl << endl << endl;
	return;
}