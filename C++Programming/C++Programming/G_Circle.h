#pragma once
#include <iostream>
#include <corecrt_math_defines.h>
using namespace std;
//�� �̷����� this.���� setter �ϴ°� �ȸ����淡 this �ڹٿ��� �ִ°ɷ� ��������
//�ٵ� �˰��� ���� �̸����� setter�� �Ҵ��Ϸ��� this->radius = radius�� �ϸ� �ƴ��� ->�� �κ��� �ٸ���
class G_Circle
{
private:
	int radius; //���� ������ ��
public:
	void setRadius(int radius) {
		this->radius = radius; //������ ����
	}
	double getArea(){
		return (radius * radius * M_PI);//���� ����
	}
};

