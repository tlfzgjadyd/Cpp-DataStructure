#pragma once
#include <iostream>
#include <corecrt_math_defines.h>
using namespace std;

class H_CircleChange
{
private:
	int radius; //���� ������ ��
public:
	void setRadius(int radius) {
		this->radius = radius; //������ ����
	}
	double getArea() {
		return (M_PI*radius * radius);//���� ����
	}
};

