#include <iostream>
using namespace std;
class Random {
public:
	//항상 다른 랜덤수를 발생시키기 위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(0)); } //씨드 설정
	static int nextInt(int min = 0, int max = 32767) {
		return (int)(rand() % (max - min) + min);
	}//min과 max 사이의 랜덤 정수 리턴
	static char nextAlphabet() {
		int temp = 0;
		while (true) {
			temp = (int)(rand() % (122 - 65) + 65);
			if (90 < temp && temp < 97)
				continue;
			else break;
		}
		return (char)(temp);
	}//랜덤 알파벳 문자 리턴
	static double nextDouble() {
		return ((rand() % 1000000)/1000000.0); //나눗셈 연산은 실수는 안먹히니까 곱셈할때 실수로 해줬음
	}//0보다 크거나 같고 1보다 적은 랜덤 실수 리턴
};
int main(void) {
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다"<<endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextInt(0, 100) << " ";
	cout<<endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다"<<endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << " ";
	cout << endl;

	cout << "랜덤한 실수를 10개를 출력합니다"<<endl;
	for (int i = 0; i < 10; i++)
	{
		cout << Random::nextDouble() << " ";
		if (i == 4)
			cout << endl;
	}
}