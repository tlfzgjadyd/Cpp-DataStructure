#pragma once
#include <iostream>
using namespace std;

class D_Sample
{
private:
	int* p;
	int size;
public:
	D_Sample(int n) { size = n; p = new int[n]; }//n개 정수 배열의 동적 생성, 생성식 기억해놓기
	void read() {
		for(int i=0;i<size;i++)
			cin >> p[i];
	} //동적 할당받은 정수 배열 p에 사용자로부터 정수를 입력 받음
	void write() {
		for (int i = 0; i < size; i++)
			cout << p[i] << " ";
		cout << endl;
	}//정수 배열 화면에 출력
	int big() {
		int biggest = p[0];
		for (int i = 1; i < size; i++) {
			if (biggest < p[i])
				biggest = p[i];
		}
		return biggest;
	}//정수 배열에서 가장 큰수 리턴
	~D_Sample() {
		delete[] p;
	} //소멸자
};

