#include <iostream>
#include <string>
using namespace std;

//�Ƥ���������getline ������ string���� char�迭�� �ؾ��ϴ��� �˾Ҵµ�
//cin.getline()�̷������� ���� ���� getline(cin,str) �̷������� �ϸ� string���� �ص� �Ǵ°ſ���
//�߰��� �̰� ���޾Ƽ� ������ �־��� �𸣰����� �ϴ� ������ �̷��� ���°ɷ�
//getline ��ߵǴµ� string ������������ ���Ҹ��� �߳�
int main(void) {
	cout << "���ڿ� �Է�>> ";
	string str;
	getline(cin, str); 

	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a')
			count++;
	}
	cout << "���� a�� " << count << "�� �ֽ��ϴ�." << endl;
}