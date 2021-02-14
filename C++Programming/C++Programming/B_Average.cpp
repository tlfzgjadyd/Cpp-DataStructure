#include <iostream>
using namespace std;
//아 자바 계속 헷갈림 c++에도 new있고 동적할당에 쓰임
//동적배열 길이는 (_msize(배열명)/sizeof(자료형크기)) 를 통해서 구할 수 있음
int main(void) {
	cout << "정수 5개 입력>> ";
	int* num = new int[5]; //이러면 for문 알아서 안돌리더라도 알아서 5칸 동적배열 할당됨
	int sum = 0;
	//그리고 c++은 for문 안돌리더라도 cin한줄로 여러개 입력 가능한거였지 근데 여기선 하나씩 칸 쓰는게 더 귀찮으므로 for문 돌릴거임
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}
	int size = _msize(num) / sizeof(int);
	cout << "평균 " << (double)sum/size;
	delete[] num; //string배열같은게 아니라서 이것만 소멸시키면 되는거였지
	//배열이라 그냥 delete num 말고 delete[] num

}