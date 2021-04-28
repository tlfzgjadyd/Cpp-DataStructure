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
	String(char* init, int m); //���� m�� ��Ʈ�� init���� �ʱ�ȭ
	~String();
	String Concat(String t);//����� ��Ʈ���� ��ȯ
	String& operator=(const String& s);
	bool operator==(String t);//�������� ��
	bool operator!();//�����̸� true �ƴϸ� false
	int Length();//���ڼ��� ��ȯ
	String Substr(int i, int j);//i~j ������ ��Ʈ���� ��ȯ
	int Find(String pat);//��Ʈ������ pat ��Ʈ���� ã�Ƽ� ��ġ ��ȯ, ������ -1
	void print();//��Ʈ�� ���
}; #pragma once
