#pragma once
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
class String
{
private:
	char* buffer;
	int length;
	int size;

	String(int m);
public:
	String();
	String(String&);
	String(char* init, int m); //길이 m인 스트링 init으로 초기화
	~String();
	String Concat(String t);//연결된 스트링을 반환
	String& operator=(const String& s);
	bool operator==(String t);//동일한지 비교
	bool operator!();//공백이면 true 아니면 false
	int Length();//문자수를 반환
	String Substr(int i, int j);//i~j 사이의 스트링을 반환
	int Find(String pat);//스트링에서 pat 스트링을 찾아서 위치 반환, 없으면 -1
	void print();//스트링 출력
}; #pragma once
