#include<iostream>
#include<random>
#include<string>
using namespace std;

int main(void) {
	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
	string str="";
	while (true) {
		cout << ">>";
		getline(cin, str);
		//����
		if (str == "exit")
			break;
		srand((unsigned)time(0)); //�������� �̰� �ߴ��� ��� �Ȱ��� ���� �����淡 ���Ⱦ��µ� �̹��� ������ �����Ҷ����� �Ȱ��� �������� �ٲ�淡 �õ� ��ô��� ���۵���
		if (str.length() <= 1)
			continue;
		int randNum = (int)(rand() % (str.length() - 1) + 1);
		char randChar = (char)(rand()%26 + 97);
		str[randNum] = randChar;
		cout << str << endl;
	}

}