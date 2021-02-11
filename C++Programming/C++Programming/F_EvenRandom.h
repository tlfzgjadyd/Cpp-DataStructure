#pragma once
#include <iostream>
#include <random>
using namespace std;

class F_EvenRandom
{
public:

	int run(int start, int end) {
		int num = 1;
		while (num % 2 != 0) {
			num = rand() % end + start;
		}
		return num;
	}
};

