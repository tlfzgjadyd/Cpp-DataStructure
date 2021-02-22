#include <iostream>
#include <vector>
using namespace std;
class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size) {
		int* res= new int[size];
		for (int i = 0; i < 5;i++) {
			res[i] = s1[i];
			res[5+i] = s2[i];
		}
		return res;
	}//s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	static int* remove(int s1[], int s2[], int size, int& retSize) { 
		vector<int> res;
		bool flag=true;
		for (int i = 0; i < 5; i++) {
			flag = true;
			for (int j = 0; j < 5; j++) {
				if (s1[i] == s2[j]) {
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				res.push_back(s1[i]);
			}
		}
		retSize = res.size();
		int* resPtr = new int[retSize];
		for (int i = 0; i < retSize; i++) {
			resPtr[i] = res[i];
		}
		return resPtr;
	}; //s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����, �����ϴ� �迭�� ũ��� retSize�� ����. retSize�� 0�� ��� NULL ����
};
int main() {
	cout << "������ 5�� �Է��϶�. �迭 x�� �����Ѵ�>>";
	int* s1= new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> s1[i];
	}
	cout << "������ 5�� �Է��϶�. �迭 y�� �����Ѵ�>>";
	int* s2 = new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> s2[i];
	}

	cout << endl<<"��ģ ���� �迭�� ����Ѵ�" << endl;
	int * res = ArrayUtility2::concat(s1, s2, 10); //static���� ������ �Լ��� Ŭ������ü ���� ���� ������ Ŭ���� �̸��� ���� ȣ���ؾ��Ѵ�
	for (int i = 0; i<10; i++) {
		cout << res[i]<<" ";
	}
	cout << endl << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ 2" << endl;
	int retSize = 5;
	int* res2 = ArrayUtility2::remove(s1, s2, 10, retSize);
	for (int i = 0; i<retSize; i++) {
		cout << res2[i] << " ";
	}
	
}