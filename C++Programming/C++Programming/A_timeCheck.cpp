#include <iostream>
#include <time.h>
using namespace std;
int main(void)
{
	int start, end;
	int i, j;

	start = time(NULL); //1970년 1월 1일~현재까지 경과한 초 수
	//forr (i = 0; i < 10000; i++);
	//for (i = 0; i < 10000; i++);
	//for (i = 0; i < 10000; i++);//3(n)해도 너무 빨라서 0나옴

	for (i = 0; i < 10000; i++) {
		for (j = 0; j < 10000; j++) {

		}
	}
	end = time(NULL);

	cout << "경과시간: " << end - start << "초";
	//너무 짧은시간 하면 0나옴 그래서 개선했더니 1나왔다
	return 0;
}