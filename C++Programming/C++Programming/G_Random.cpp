#include <iostream>
using namespace std;
class Random {
public:
	//�׻� �ٸ� �������� �߻���Ű�� ���� seed�� �����ϴ� �Լ�
	static void seed() { srand((unsigned)time(0)); } //���� ����
	static int nextInt(int min = 0, int max = 32767) {
		return (int)(rand() % (max - min) + min);
	}//min�� max ������ ���� ���� ����
	static char nextAlphabet() {
		int temp = 0;
		while (true) {
			temp = (int)(rand() % (122 - 65) + 65);
			if (90 < temp && temp < 97)
				continue;
			else break;
		}
		return (char)(temp);
	}//���� ���ĺ� ���� ����
	static double nextDouble() {
		return ((rand() % 1000000)/1000000.0); //������ ������ �Ǽ��� �ȸ����ϱ� �����Ҷ� �Ǽ��� ������
	}//0���� ũ�ų� ���� 1���� ���� ���� �Ǽ� ����
};
int main(void) {
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�"<<endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextInt(0, 100) << " ";
	cout<<endl;

	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�"<<endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << " ";
	cout << endl;

	cout << "������ �Ǽ��� 10���� ����մϴ�"<<endl;
	for (int i = 0; i < 10; i++)
	{
		cout << Random::nextDouble() << " ";
		if (i == 4)
			cout << endl;
	}
}