#include <iostream>
using namespace std;
int main(void) {
	for (int i = 1; i <= 100; i++)
	{
		cout << i<<"	";
		if ((i%10) == 0)
			cout << endl;
	}
	return 0;
}