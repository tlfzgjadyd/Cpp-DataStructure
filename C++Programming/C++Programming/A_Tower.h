#pragma once
#include <iostream>
using namespace std;

//�ڹٿ� �޸� private int height�ϴ°� �ƴ϶� private: �ؿ� ���� �ۼ� public: �ؿ� ���� �ۼ�
class A_Tower
{
private:
	int height;
public:
	A_Tower() {
		height = 1;
	}
	A_Tower(int h) {
		height = h;//�׸��� this�� ���⿡ ����� �̸� �ٸ����ؼ� �������� �޾� �ʱ�ȭ�ؾߵ� ���� �̸����� �ϸ� �ȸ�������
	}
	int getHeight() {
		return height;
	}
};