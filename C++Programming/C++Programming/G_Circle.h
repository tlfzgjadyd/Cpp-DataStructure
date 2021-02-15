#pragma once
#include <iostream>
#include <corecrt_math_defines.h>
using namespace std;
//아 이럴수가 this.으로 setter 하는거 안먹히길래 this 자바에만 있는걸로 착각했음
//근데 알고보니 같은 이름으로 setter를 할당하려면 this->radius = radius로 하면 됐던것 ->인 부분이 다르다
class G_Circle
{
private:
	int radius; //원의 반지름 값
public:
	void setRadius(int radius) {
		this->radius = radius; //반지름 설정
	}
	double getArea(){
		return (radius * radius * M_PI);//면적 리턴
	}
};

