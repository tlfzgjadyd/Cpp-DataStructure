#include <iostream>
#include <string>
using namespace std;
int main(void) {
	cout << "���ڿ� �Է�>> ";
	string str;
	getline(cin, str);
	int count = 0;
	int i = 0;
	while (i < str.length()) {
		int index = str.find('a', i);
		if (index != -1)
		{
			count++;
			i = index + 1;
		}
		else
			i++;
	}
	cout << "���� a�� " << count << "�� �ֽ��ϴ�."<<endl;
	
}