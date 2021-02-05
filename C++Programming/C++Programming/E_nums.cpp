#include <iostream>
#include <string>
using namespace std;

//getline는 문자열 입력받을때 쓰는데 어떻게 쓰는거냐면 cin.getline(저장할변수명, 저장문자개수)
//그리고 c++에서의 string은 대문자 아님
int main(void) {
	int count = 0;
	char str[100];
	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(str, 99);
	for (int i = 0; i < 100; i++)
	{
		if (str[i] == 'x')
			count++;
	}
	cout << "x의 개수는 " << count << endl;
	return 0;
}