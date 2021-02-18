#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success);

int main(void) {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다" << endl;
		return 0;
	}
	loc = 'm'; //'M' 위치에 'm' 기록
	cout << s << endl;// "mike"가 출력됨
}
char& find(char a[], char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) { //배열길이는 a.size()도 아니고 a.length()도 아니고 strlen(a)로 해야했음
		if (a[i] == c)
		{
			success = true;
			return a[i];
		}
		return c;
	}
}