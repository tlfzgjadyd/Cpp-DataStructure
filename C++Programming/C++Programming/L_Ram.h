#pragma once
#include <iostream>
using namespace std;

class L_Ram
{
private:
	char mem[100 * 1024]; //100KB �޸�. �� ������ �� ����Ʈ�̹Ƿ� char Ÿ�� ���
	int size;
public:
	L_Ram(); //mem �迭�� 0���� �ʱ�ȭ�ϰ� size�� 100*1024�� �ʱ�ȭ
	~L_Ram(); //"�޸� ���ŵ�" ���ڿ� ���
	char read(int addrss);//address �ּ��� �޸� ����Ʈ ����
	void write(int address, char value); //address �ּҿ� �� ����Ʈ�� value ����
};

