#include "J_Calculate.h"
//�� ���� ��ü���� �ϴٿԴ��� �Է¹޴°� ��Ծ c���� �˰� scanf�ϰ��־��� cin������
int main(void) {
	Add a;
	Sub s;
	Mul m;
	Div d;

	int x = 0;
	int y = 0;
	char select = ' ';
	
	while (true) {
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		cin >> x >> y >> select;
		switch (select) {
		case '+': {
			a.setValue(x, y);
			cout << a.calculate()<<endl;
		}break;
		case '-': {
			s.setValue(x, y);
			cout << s.calculate()<<endl;
		}break;
		case '*': {
			m.setValue(x, y);
			cout << m.calculate()<<endl;
		}break;
		case '/': {
			d.setValue(x, y);
			cout << d.calculate()<<endl;
		}break;
		}
	}
}