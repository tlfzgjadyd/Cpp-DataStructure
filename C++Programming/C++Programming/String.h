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
	void DeepCopy(const char* src, int size);
	String();
	String(String& s);
	String(char* init, int m); //���� m�� ��Ʈ�� init���� �ʱ�ȭ
	String(char c);
	String(const char* str);
	String(char* str);
	String(const char* init, int m);
	~String();
	String Concat(String t);//����� ��Ʈ���� ��ȯ
	String& operator=(const String& s);
	bool operator==(String t);//�������� ��
	bool operator!();//�����̸� true �ƴϸ� false
	int Length();//���ڼ��� ��ȯ
	String Substr(int i, int j);//i~j ������ ��Ʈ���� ��ȯ
	int Find(String pat);//��Ʈ������ pat ��Ʈ���� ã�Ƽ� ��ġ ��ȯ, ������ -1
	void print();//��Ʈ�� ���
	ostream& operator<<(ostream& o);
	char getItem(int i);
	int Strtoi();
	char* getBuffer();
};