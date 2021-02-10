#pragma once
#include <iostream>
#include <cstdlib> //RAND_MAX상수 들어있음
//랜덤함수로는 rand()를 사용하며 시드값을 위해 srand를 섞어서 사용함
//그냥 rand하면 알아서 0~최대범위 생성함, 0~1값을 생성하는 자바나 코틀린과는 많이 다름 걔네는 시드값도 시간으로 안해줘도 됐었는데
//어쨌든 시작이 큰수이기 때문에 *원하는수 대신 %원하는 수로 해결한다
//근데 이때 시작수가 달라지면 %(num2-num1)+num1으로 처리해야해서 복잡함
#include<ctime>
using namespace std;

class E_Random
{
public:
	int next() {
		return rand();
	}//0에서 RAND_MAX(32767)사이의 랜덤한 정수

	int nextInRange(int num1,int num2) {
		return rand()%(num2-num1) +num1;
	}//2에서 4 사이의 랜덤한 정수
};

