#include <iostream>
using namespace std;
class MyIntStack{
private:
	int p[10]; //�ִ� 10���� ���� ����
	int tos; //������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() {
		tos = 0;
	}
	bool push(int n) {
		if (tos == 10)
		{
			return false;
		}
		else
		{
			p[tos] = n;
			tos++;
			return true;
		}
	}//���� n Ǫ�� ���������� false, �ƴϸ� true ����
	bool pop(int& n) {
		if (tos == 0) 
		{
			return false;
		}
		else
		{
			n=p[tos - 1];
			tos--;
			return true;
		}
		
	}//���Ͽ� n�� ����, ������ ��������� false, �ƴϸ� true ����
};
int main(void) {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i))cout << i << ' ';
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n))cout << n << ' ';
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}