//�˹ٸ� �ϱ� ���� �ܿ����ϴ� �޴� ���� ������
#include <iostream>
#include <random>
#define MAX_MENU_NUM 7
using namespace std;
int main(void) {
	string menu[MAX_MENU_NUM] = {"��������������", "����������", "Ŀ�� �ٳ��� ������", "Ŀ�� ������", "�� ũ����", "���� �� ũ����", "�ٳ��� �� ũ����"};
	string answer[MAX_MENU_NUM] = { "��������������", "����������", "Ŀ�� �ٳ��� ������", "Ŀ�� ������", "�� ũ����", "���� �� ũ����", "�ٳ��� �� ũ����" };
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<int> dis(0, 6);
	int num = 0;
	while (true) {
		num = dis(gen);
		cout << menu[num] << "��(��) �����Ͻÿ�" << endl;
		getchar();
		cout << "======================================" << endl;
		cout << answer[num] << endl;
		cout << "======================================" << endl<<endl<<endl;
		getchar();
	}
	return 0;
}