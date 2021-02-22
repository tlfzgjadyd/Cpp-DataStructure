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
	}//s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
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
	}; //s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴, 리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우 NULL 리턴
};
int main() {
	cout << "정수를 5개 입력하라. 배열 x에 삽입한다>>";
	int* s1= new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> s1[i];
	}
	cout << "정수를 5개 입력하라. 배열 y에 삽입한다>>";
	int* s2 = new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> s2[i];
	}

	cout << endl<<"합친 정수 배열을 출력한다" << endl;
	int * res = ArrayUtility2::concat(s1, s2, 10); //static으로 선언한 함수를 클래스객체 생성 없이 쓰려면 클래스 이름을 통해 호출해야한다
	for (int i = 0; i<10; i++) {
		cout << res[i]<<" ";
	}
	cout << endl << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 2" << endl;
	int retSize = 5;
	int* res2 = ArrayUtility2::remove(s1, s2, 10, retSize);
	for (int i = 0; i<retSize; i++) {
		cout << res2[i] << " ";
	}
	
}