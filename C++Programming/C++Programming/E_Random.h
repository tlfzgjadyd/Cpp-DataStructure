#pragma once
#include <iostream>
#include <cstdlib> //RAND_MAX��� �������
//�����Լ��δ� rand()�� ����ϸ� �õ尪�� ���� srand�� ��� �����
//�׳� rand�ϸ� �˾Ƽ� 0~�ִ���� ������, 0~1���� �����ϴ� �ڹٳ� ��Ʋ������ ���� �ٸ� �³״� �õ尪�� �ð����� �����൵ �ƾ��µ�
//��·�� ������ ū���̱� ������ *���ϴ¼� ��� %���ϴ� ���� �ذ��Ѵ�
//�ٵ� �̶� ���ۼ��� �޶����� %(num2-num1)+num1���� ó���ؾ��ؼ� ������
#include<ctime>
using namespace std;

class E_Random
{
public:
	int next() {
		return rand();
	}//0���� RAND_MAX(32767)������ ������ ����

	int nextInRange(int num1,int num2) {
		return rand()%(num2-num1) +num1;
	}//2���� 4 ������ ������ ����
};

