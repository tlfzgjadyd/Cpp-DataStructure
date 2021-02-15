#pragma once
#include <iostream>
#include <corecrt_math_defines.h>
using namespace std;

class H_CircleChange
{
private:
	int radius; //원의 반지름 값
public:
	void setRadius(int radius) {
		this->radius = radius; //반지름 설정
	}
	double getArea() {
		return (M_PI*radius * radius);//면적 리턴
	}
};

