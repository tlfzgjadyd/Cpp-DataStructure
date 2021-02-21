#include <iostream>
using namespace std;
int add(int a[], int size);
int add(int a[], int size, int b[]);
int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9, 10 };
	int c = add(a, 5); //배열 a의 정수를 모두 더한 값 리턴
	int d = add(a, 5, b); //배열 a와 b의 정수를 모두 더한 값 리턴
	cout << c << endl; //15출력
	cout << d << endl; //55출력
}
int add(int a[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return sum;
}
int add(int a[], int size, int b[]) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i] + b[i];
	}
	return sum;
}