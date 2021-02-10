#include <iostream>
using namespace std;

//책 힌트에 나와있음 getline 사용할떄 3번쨰 인자로 char 주면 그 문자가 들어올 때까지 입력받게된다
//근데 cin.getline(text, 999, ';')로 읽어들이면 ;는 안들어오기에 나중에 문자열 끝을 ;로 검사하는건 불가능함 아예 안들어와서 탐지 안됨
//이번에도 getline때문에 char쪽으로 가야겠네
//그리고 char 초기화 ''로 안되길래 아예 안했었는데 그럼 에러나므로 ' '로 공백 1개로 초기화해야됨
//그리고뭔 isalpha함수를 통해 알파벳인지 검사 가능인데 알파벳이 맞을 경우 돌아오는 값이 true가 아니라 2라서 뭔가싶음 사용법 에러 많이났었음 bool 쓸 수 있으면서 왜그러는거지
int main(void) {
	char text[10000];
	int current = 0;
	int count = 0;
	int nums[123] = { 0 };
	char words[123];

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
	cin.getline(text, 999, ';');

	for (int i = 97; i < 123; i++) {
		words[i] = (char)i;
	}

	while(true){
		if ((int)text[current] == -52) //공백으로 끝을 탐지하려했는데 인식 안돼서 빈곳의 아스키코드 찍어보고 -52인걸 확인함
			break;
		if (isalpha(text[current]) >0)//대문자면 여전히 탐지 안되길래 대문자의 isalpha 결과도 찍어봤음 그랬더니 소문자는 2나오고 대문자는 1나오고 기호는 0나옴 그래서 a;하면 20나오는것 한글은 에러남 결론은 영어면 >0으로 나옴
		{
			int index = (int)(tolower(text[current]));
			nums[index]++;
			count++;
		}
		current++;
	}

	cout << "총 알파벳 수 " << count << endl << endl;
	for (int i = 97; i < 123; i++) {
		cout << words[i] << " (" << nums[i] << ")	: ";
		for (int j = 0; j < nums[i]; j++)
			cout << "*";
		cout << endl;
	}


	return 0;
}