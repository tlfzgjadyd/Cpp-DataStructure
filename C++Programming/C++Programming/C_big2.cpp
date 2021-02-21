#include <iostream>
using namespace std;
int big(int a, int b, int biggest=100) {
	if (a > b) {
		if (a > biggest)
			return biggest;
		else
			return b;
	}
	else {
		if (b > biggest)
			return biggest;
		else
			return b;
	}
}
int main(void) {
	int x = big(3, 5); //과 5 중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
	int y = big(300, 60); //300과 60 중 큰 값 300이 최대값 100보다 크므로 100리턴
	int z = big(30, 60, 50); //30과 60중 큰 값 60이 최대값 50보다 크므로, 50 리턴
	cout << x << ' ' << y << ' ' << z << endl;
}