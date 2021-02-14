#include <iostream>
#include <string>
using namespace std;

//아ㅏㅏㅏㅏㅏgetline 쓰려면 string말고 char배열로 해야하는줄 알았는데
//cin.getline()이런식으로 쓰지 말고 getline(cin,str) 이런식으로 하면 string으로 해도 되는거였음
//중간에 이거 깨달아서 쓴적이 있었나 모르겠지만 일단 앞으론 이렇게 쓰는걸로
//getline 써야되는데 string 연습문제래서 뭔소린가 했네
int main(void) {
	cout << "문자열 입력>> ";
	string str;
	getline(cin, str); 

	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a')
			count++;
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;
}