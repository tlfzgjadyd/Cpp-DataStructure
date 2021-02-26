#include <iostream>
using namespace std;
class Statistics {
private:
	int* arr;
	int size;
public:
	Statistics() {
		size=0;
		arr = new int[size]; //이러면 size가 바뀜에 따라 알아서 동적으로 배열이 커지겠지
	}
	bool operator !() { //단항연산자 순서바뀌는건줄 알았는데 이건 괜찮나보네 !stat해도 알아서 stat이 !연산자 호출한걸로 되나봄 하긴 그래야겠지
		if (this->size == 0)
			return true; //여기서 헷갈렸던게 !stat이 리턴값 온다음 또 부정표시 먹히는건줄 알았음 그냥 !stat 그자체로 리턴값과 대체되는거였음
		else
			return false;
	}
	Statistics& operator <<(int value) {
		arr[size] = value;
		size++;
		return *this; //<<연산자 이후에 연속해서 연산해야 하므로 자기자신 리턴해줬음
		//특히나 이번 예제에서는 더욱더 stat<<100<<200로 연속연산 하고있으므로 stat<<100연산후에 stat이 100을 먹고 다음칸으로 이동해서 stat<<200이 되게 하기 위해선 Statistics&를 리턴해줘야됨
	}
	void operator ~() {//출력기능으로 정의했으므로 아무것도 리턴하지 않는다
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void operator >>(int& value) {//리턴값받아서 쓰는게 아니라 avg에 저장된 값을 나중에 이용해야하므로 value를 참조전달해서 value값을 수정
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		value= (int)sum/size;
	}
};
int main(void) {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다" << endl;
	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++)cin >> x[i]; //x[i]에 정수 입력
	for (int i = 0; i < 5; i++)stat << x[i]; //x[i]값을 통계 객체에 삽입한다
	stat << 100 << 200; //100, 200을 통계 객체에 삽입한다.
	~stat; //통계 데이터를 모두 출력한다

	int avg=0;
	stat >> avg; //통계 객체로부터 평균을 받는다
	cout << "avg=" << avg << endl; //평균을 출력한다
}