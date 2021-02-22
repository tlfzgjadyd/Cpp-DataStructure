#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Trace {
private:
    static vector<pair<string, string>> debug;
public:
	static void put(string target, string content) { //��ü ���� ���� �Լ� ����ϱ� ���ϰ� �����Ƿ� static
		if(debug.size()<=100)
			debug.push_back(pair<string, string>(target, content)); //static���� static����� ��� �����ϹǷ� private ������Ƽ�� debug���� static�� �ٿ��� ���� �ȳ�
	}
	static void print(string target) {
		cout << "----- " << target << "�±��� Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < debug.size(); i++) {
			if (debug[i].first == target)
				cout << debug[i].first << ":" << debug[i].second << endl;//pair�� first, second�� �Լ������� �ƴ϶� ������Ƽó�� ȣ���ϴ� �ſ���
		}
	}
	static void print() {
		cout << "----- ��� Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < debug.size(); i++) {
			cout << debug[i].first << ":" << debug[i].second << endl;//pair�� first, second�� �Լ������� �ƴ϶� ������Ƽó�� ȣ���ϴ� �ſ���
		}
	}
};
vector<pair<string, string>> Trace::debug;  //�̺κ��� ������ �������� 
//class���� static���� ����� private ������Ƽ�� ��� class���� �Ʒ��� �ڷ��� Ŭ������::������ ���� �˷�����Ѵ�
//�̺κ��� ���������� �����ϴ� �κ��ε�
//Ŭ���� ��ü�� ���� �������� �ʱ� ������ ������Ƽ�� �Ҵ��� ������ �������� �ϱ� �����̴�
//�׷��� static ������Ƽ ����� �׻� �Լ� �ٱ��� �������� ������ �ʿ��ϴ�
//�ȱ׷��� �Ʒ��� ���� ������ ���
/*�ɰ���	�ڵ�	����	������Ʈ	����	��	��ǥ�� ����(Suppression) ����
����	LNK2001	Ȯ���� �� ���� �ܺ� ��ȣ "private: static class std::vector<class std::basic_string<char,struct 
std::char_traits<char>,class std::allocator<char> >,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > > >
Board::board" (?board@Board@@0V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@A)C++Programming
C:\Users\tlfzg\DataStructure-Cpp\C++Programming\C++Programming\I_Board.obj	1	
����	LNK1120	1���� Ȯ���� �� ���� �ܺ� �����Դϴ�.	C++Programming	C:\Users\tlfzg\DataStructure-Cpp\C++Programming\x64\Debug\C++Programming.exe	1	
*/

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���"); //����� ���� ����
	c = a + b;
	Trace::put("f()", "�� ���"); //����� ���� ����
	cout << "���� " << c << endl;
}
int main(void) {
	Trace::put("main()", "���α׷� �����մϴ�"); //����� ���� ����
	f();
	Trace::put("main()", "����"); //put()�� ù ��° �Ű������� �±��̰�
									//�� ��° �Ű������� ����� �����̴�
	Trace::print("f()"); //"f()" �±׸� ���� ����� ������ ��� ����Ѵ�.
	Trace::print(); //��� ����� ������ ����Ѵ�.*/
	;
}