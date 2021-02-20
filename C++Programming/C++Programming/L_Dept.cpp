#include<iostream>
using namespace std;
class Dept {
private:
	int size; //scores �迭�� ũ��
	int* scores; //���� �Ҵ� ���� ���� �迭�� �ּ�
public:
	Dept(int size) {//������
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept) {//���� ������
		this->size = dept.size;
		this->scores = new int[size];
		for (int i = 0; i < size; i++) {
			scores[i] = dept.scores[i];
		}
	}
	~Dept() {
		delete scores;
		}//�Ҹ���
	int getSize() { return size; }
	void read() {
		cout << "10�� ���� �Է�>> ";
		for (int i = 0; i < size; i++)
			cin >> scores[i];
	}//size ��ŭ Ű���忡�� ������ �о� scores �迭�� ����
	bool isOver60(int index) {
		if (scores[index] > 60)
			return true;
		else
			return false; //60���� ������� falseó�� ���ϸ� �ڵ����� true���پ˰� �̻��ϰ� �۵���
	}//index�� �л��� ������ 60���� ũ�� true ����
};

int countPass(Dept dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}
int main(void) {
	Dept com(10); //�� 10���� �ִ� �а� com
	com.read(); //�� 10���� �л����� ������ Ű����κ��� �о� scores �迭�� ����
	int n = countPass(com); //com �а��� 60�� �̻����� ����� �л��� ���� ����
	cout << "60�� �̻��� " << n << "��";
}