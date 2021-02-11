#pragma once
#include <iostream>
#include <string>
using namespace std;

class H_Integer
{
private:
	int content;
public:
	H_Integer(string str)
	{
		content = stoi(str);
	}
	H_Integer(int num) {
		content = num;
	}
	int get() {
		return content;
	}
	void set(int num) {
		content = num;
	}
	bool isEven() {
		if (content % 2 == 0)
			return true;
		else
			return false;
	}

};

