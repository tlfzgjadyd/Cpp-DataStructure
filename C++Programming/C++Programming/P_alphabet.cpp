#include <iostream>
using namespace std;

//å ��Ʈ�� �������� getline ����ҋ� 3���� ���ڷ� char �ָ� �� ���ڰ� ���� ������ �Է¹ްԵȴ�
//�ٵ� cin.getline(text, 999, ';')�� �о���̸� ;�� �ȵ����⿡ ���߿� ���ڿ� ���� ;�� �˻��ϴ°� �Ұ����� �ƿ� �ȵ��ͼ� Ž�� �ȵ�
//�̹����� getline������ char������ ���߰ڳ�
//�׸��� char �ʱ�ȭ ''�� �ȵǱ淡 �ƿ� ���߾��µ� �׷� �������Ƿ� ' '�� ���� 1���� �ʱ�ȭ�ؾߵ�
//�׸��� isalpha�Լ��� ���� ���ĺ����� �˻� �����ε� ���ĺ��� ���� ��� ���ƿ��� ���� true�� �ƴ϶� 2�� �������� ���� ���� ���̳����� bool �� �� �����鼭 �ֱ׷��°���
int main(void) {
	char text[10000];
	int current = 0;
	int count = 0;
	int nums[123] = { 0 };
	char words[123];

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�." << endl;
	cin.getline(text, 999, ';');

	for (int i = 97; i < 123; i++) {
		words[i] = (char)i;
	}

	while(true){
		if ((int)text[current] == -52) //�������� ���� Ž���Ϸ��ߴµ� �ν� �ȵż� ����� �ƽ�Ű�ڵ� ���� -52�ΰ� Ȯ����
			break;
		if (isalpha(text[current]) >0)//�빮�ڸ� ������ Ž�� �ȵǱ淡 �빮���� isalpha ����� ������ �׷����� �ҹ��ڴ� 2������ �빮�ڴ� 1������ ��ȣ�� 0���� �׷��� a;�ϸ� 20�����°� �ѱ��� ������ ����� ����� >0���� ����
		{
			int index = (int)(tolower(text[current]));
			nums[index]++;
			count++;
		}
		current++;
	}

	cout << "�� ���ĺ� �� " << count << endl << endl;
	for (int i = 97; i < 123; i++) {
		cout << words[i] << " (" << nums[i] << ")	: ";
		for (int j = 0; j < nums[i]; j++)
			cout << "*";
		cout << endl;
	}


	return 0;
}