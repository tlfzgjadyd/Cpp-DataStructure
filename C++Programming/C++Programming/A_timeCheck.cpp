#include <iostream>
#include <time.h>
using namespace std;
int main(void)
{
	int start, end;
	int i, j;

	start = time(NULL); //1970�� 1�� 1��~������� ����� �� ��
	//forr (i = 0; i < 10000; i++);
	//for (i = 0; i < 10000; i++);
	//for (i = 0; i < 10000; i++);//3(n)�ص� �ʹ� ���� 0����

	for (i = 0; i < 10000; i++) {
		for (j = 0; j < 10000; j++) {

		}
	}
	end = time(NULL);

	cout << "����ð�: " << end - start << "��";
	//�ʹ� ª���ð� �ϸ� 0���� �׷��� �����ߴ��� 1���Դ�
	return 0;
}