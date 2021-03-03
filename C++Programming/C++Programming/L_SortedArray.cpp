#include <iostream>
#include <algorithm>
using namespace std;
class SortedArray {
	int size;//현재 배열의 크기
	int* p; //정수 배열에 대한 포인터
	void sort() {//정렬은 함수인데 private에 둔 이유는 main에선 sort를 사용할 수 없고 show할때만 내부적으로 사용하는 함수이기 때문이다
		int temp = 0;
		for (int i = size-1; i > 0; i--) {//i는 정렬할 최대 수를 가리키고 점차 하나씩 줄어들음
			for (int j = 0; j < i; j++) {//실질적인 비교는 j와 j+1만으로 이루어진다
				if (p[j] > p[j + 1])
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
		}//원래는 효율 좋은 정렬을 쓰려고 했었음 근데 코드가 복잡하잖아 그래서 연습문제에선 간단한 배열을 쓰곤 한다
	}//정수 배열을 오름차순으로 정렬
public:
	SortedArray() {
		this->size = 0;
		p = NULL; //c++ 에서 널은 전부 대문자 
	}//p는 NULL로 size는 0으로 초기화
	SortedArray(SortedArray& src) {
		this->size = src.size;
		p = new int[size]; //여기서 src.p의 주소를 복사하는게 아니라 배열 돌며 내용물을 복사해 오는거였지, new 키워드 빼먹지 말고 소멸자에서 delete로 동적할당 해제도 해주고
		for (int i = 0; i < size; i++) {
			p[i] = src.p[i];
		}
	}//복사 생성자
	SortedArray(int p[], int size) {//이번엔 복사생성자가 아니라 배열과 사이즈를 직접 전달해서 초기화했는데 이럴 경우에도 마찬가지로 1. 동적할당부터 해서 공간 마련하고 2. 내용물 복사해야됨
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
	}//생성자, 정수 배열과 크기를 전달받음
	~SortedArray() {
		delete[] p; //배열에 대한 동적할당 해제는 그냥 delete가 아니라 delete[]였지
		size = 0;
	}//소멸자
	SortedArray operator + (SortedArray& op2) {//배열 맨처음 공간 할당할때 이미 크기 정해놨기 때문에 이제와서 거기에 이어서 저장하는건 불가능하다 왜냐면 잠깐사이에 뒷공간에 자리 부여했을수도 있기 때문
		int size2 = this->size+op2.size;//그러므로 두 배열을 합친 크기만큼의
		int* p2 = new int[size2];//새로운 공간을 할당해줘야한다, 바로 this에 안넣고 새 변수들 할당하는 이유는 아래에서 for문 돌며 기존배열 내용을 얻어오려면 기존 내용이 남아있어야 하기 때문
		for (int i = 0; i < this->size; i++) {//효율성때문에 한 for문 안에서 두 배열 같이 추가하려 했는데 어느쪽 배열 길이가 더 클지 모르니까 코드가 괜히 복잡해져서 그냥 for문 2번 돌렸음
			p2[i] = this->p[i];
		}
		for (int i = 0; i < op2.size; i++) {
			p2[this->size + i] = op2.p[i];
		}
		SortedArray newArray (p2, size2);//리턴할때 참조형태가 아닌 일반 SortedArray로 문제에서 정해줬기 때문에 this리턴 못하고 새로 만들어서 리턴한다, *this없이 그냥 this 리턴도 안됐음
		return newArray;//이때 return자리에 바로 익명객체 했더니 에러났음
	}//현재 배열에 op2 배열 추가
	SortedArray& operator = (const SortedArray& op2) {
		this->size = op2.size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = op2.p[i];
		}
		return *this;
	}//현재 배열에 op2 배열 복사
	void show() {
		sort();
		cout << "배열 출력 : ";
		for (int i = 0; i < size; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}//배열의 원소 출력
};
int main(void) {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;
	c = a + b; // +, = 연산자 작성 필요, 여기서 걸려서 작동이 안됐었음
	//+연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
	
	a.show();
	b.show();
	c.show();
}