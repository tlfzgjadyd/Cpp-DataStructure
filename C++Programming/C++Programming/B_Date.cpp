#include "B_Date.h"

int main() {
	B_Date birth(2014, 3, 20); //2014�� 3�� 20��
	B_Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}