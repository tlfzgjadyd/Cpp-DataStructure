#include <iostream>
using namespace std;
//�� �ڹ� ��� �򰥸� c++���� new�ְ� �����Ҵ翡 ����
//�����迭 ���̴� (_msize(�迭��)/sizeof(�ڷ���ũ��)) �� ���ؼ� ���� �� ����
int main(void) {
	cout << "���� 5�� �Է�>> ";
	int* num = new int[5]; //�̷��� for�� �˾Ƽ� �ȵ������� �˾Ƽ� 5ĭ �����迭 �Ҵ��
	int sum = 0;
	//�׸��� c++�� for�� �ȵ������� cin���ٷ� ������ �Է� �����Ѱſ��� �ٵ� ���⼱ �ϳ��� ĭ ���°� �� �������Ƿ� for�� ��������
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}
	int size = _msize(num) / sizeof(int);
	cout << "��� " << (double)sum/size;
	delete[] num; //string�迭������ �ƴ϶� �̰͸� �Ҹ��Ű�� �Ǵ°ſ���
	//�迭�̶� �׳� delete num ���� delete[] num

}