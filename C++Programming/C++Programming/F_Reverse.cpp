#include <iostream>
#include <string>
using namespace std;
int main(void) {
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)"<<endl;
	string str="";
	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str == "exit")
			break;
		for (int i = str.length()-1; i >=0; i--) {
			cout << str[i]; //다른 string에 역으로 할당해서 출력하려고 했더니 뭔가 접근 에러나길래 그냥 바로 한글자씩 출력했음
		}
		cout << endl; 
	}
}