#include "J_Calculate.h"
//아 뭐야 객체지향 하다왔더니 입력받는거 까먹어서 c인줄 알고 scanf하고있었음 cin이잖음
int main(void) {
	Add a;
	Sub s;
	Mul m;
	Div d;

	int x = 0;
	int y = 0;
	char select = ' ';
	
	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
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