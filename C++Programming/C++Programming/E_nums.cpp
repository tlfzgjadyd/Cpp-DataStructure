#include <iostream>
#include <string>
using namespace std;

//getline는 문자열 입력받을때 쓰는데 어떻게 쓰는거냐면 cin.getline(저장할변수명, 저장문자개수)
//근데 이러면 char 배열로 str 만들어야됨
//그래서 string으로 사용하기 위해선 getline(cin, 변수명) 이렇게 사용한다
//그리고 c++에서의 string은 대문자 아님
int main(void) {
	int count = 0;
	string str;
	cout << "문자들을 입력하라(100개 미만)." << endl;
	getline(cin, str);
	for (int i = 0; i < 100; i++)
	{
		if (str[i] == 'x')
			count++;
	}
	cout << "x의 개수는 " << count << endl;
	return 0;
}