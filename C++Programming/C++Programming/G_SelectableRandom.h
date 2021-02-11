#pragma once
#include <iostream>
using namespace std;

class G_SelectableRandom
{
public:
	int odd(int start, int end) {
		int num = 0;
		while (num % 2 != 1) {
			num = rand() % end + start;
		}
		return num;
	}
	int even(int start, int end) {
		int num = 1;
		while (num % 2 != 0) {
			num = rand() % end + start;
		}
		return num;
	}
};

