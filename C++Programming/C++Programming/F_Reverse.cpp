#include <iostream>
#include <string>
using namespace std;
int main(void) {
	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)"<<endl;
	string str="";
	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str == "exit")
			break;
		for (int i = str.length()-1; i >=0; i--) {
			cout << str[i]; //�ٸ� string�� ������ �Ҵ��ؼ� ����Ϸ��� �ߴ��� ���� ���� �������淡 �׳� �ٷ� �ѱ��ھ� �������
		}
		cout << endl; 
	}
}