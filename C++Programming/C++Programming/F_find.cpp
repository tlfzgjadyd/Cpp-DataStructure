#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success);

int main(void) {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����" << endl;
		return 0;
	}
	loc = 'm'; //'M' ��ġ�� 'm' ���
	cout << s << endl;// "mike"�� ��µ�
}
char& find(char a[], char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) { //�迭���̴� a.size()�� �ƴϰ� a.length()�� �ƴϰ� strlen(a)�� �ؾ�����
		if (a[i] == c)
		{
			success = true;
			return a[i];
		}
		return c;
	}
}