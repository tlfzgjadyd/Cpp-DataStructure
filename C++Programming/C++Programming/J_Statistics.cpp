#include <iostream>
using namespace std;
class Statistics {
private:
	int* arr;
	int size;
public:
	Statistics() {
		size=0;
		arr = new int[size]; //�̷��� size�� �ٲ� ���� �˾Ƽ� �������� �迭�� Ŀ������
	}
	bool operator !() { //���׿����� �����ٲ�°��� �˾Ҵµ� �̰� ���������� !stat�ص� �˾Ƽ� stat�� !������ ȣ���Ѱɷ� �ǳ��� �ϱ� �׷��߰���
		if (this->size == 0)
			return true; //���⼭ �򰥷ȴ��� !stat�� ���ϰ� �´��� �� ����ǥ�� �����°��� �˾��� �׳� !stat ����ü�� ���ϰ��� ��ü�Ǵ°ſ���
		else
			return false;
	}
	Statistics& operator <<(int value) {
		arr[size] = value;
		size++;
		return *this; //<<������ ���Ŀ� �����ؼ� �����ؾ� �ϹǷ� �ڱ��ڽ� ����������
		//Ư���� �̹� ���������� ����� stat<<100<<200�� ���ӿ��� �ϰ������Ƿ� stat<<100�����Ŀ� stat�� 100�� �԰� ����ĭ���� �̵��ؼ� stat<<200�� �ǰ� �ϱ� ���ؼ� Statistics&�� ��������ߵ�
	}
	void operator ~() {//��±������ ���������Ƿ� �ƹ��͵� �������� �ʴ´�
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void operator >>(int& value) {//���ϰ��޾Ƽ� ���°� �ƴ϶� avg�� ����� ���� ���߿� �̿��ؾ��ϹǷ� value�� ���������ؼ� value���� ����
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		value= (int)sum/size;
	}
};
int main(void) {
	Statistics stat;
	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�" << endl;
	int x[5];
	cout << "5 ���� ������ �Է��϶�>>";
	for (int i = 0; i < 5; i++)cin >> x[i]; //x[i]�� ���� �Է�
	for (int i = 0; i < 5; i++)stat << x[i]; //x[i]���� ��� ��ü�� �����Ѵ�
	stat << 100 << 200; //100, 200�� ��� ��ü�� �����Ѵ�.
	~stat; //��� �����͸� ��� ����Ѵ�

	int avg=0;
	stat >> avg; //��� ��ü�κ��� ����� �޴´�
	cout << "avg=" << avg << endl; //����� ����Ѵ�
}