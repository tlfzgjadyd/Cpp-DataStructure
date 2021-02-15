#include<iostream>
#include<random>
#include<string>
using namespace std;

int main(void) {
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
	string str="";
	while (true) {
		cout << ">>";
		getline(cin, str);
		//수정
		if (str == "exit")
			break;
		srand((unsigned)time(0)); //이전에는 이거 했더니 계속 똑같은 수만 나오길래 버렸었는데 이번엔 오히려 실행할때마다 똑같은 패턴으로 바뀌길래 시드 줘봤더니 잘작동함
		if (str.length() <= 1)
			continue;
		int randNum = (int)(rand() % (str.length() - 1) + 1);
		char randChar = (char)(rand()%26 + 97);
		str[randNum] = randChar;
		cout << str << endl;
	}

}