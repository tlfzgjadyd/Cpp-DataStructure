#include <iostream>
#include <string>
using namespace std;
int main(void) {
	cout << "문자열 입력>> ";
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
	cout << "문자 a는 " << count << "개 있습니다."<<endl;
	
}