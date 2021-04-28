#include<iostream>
#include<algorithm>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main(void) {
	Stack<int> s(5);
	int n;
	cout << "스택에 삽입할 5개의 정수 입력>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		s.Push(n); //스택에 푸시
	}
	cout << "Top에 있는 원소 : " << s.Top() << endl;
	cout << "스택의 모든 원소를 팝하여 출력했다 " << endl;
	while (!s.IsEmpty()) {
		s.Pop(); //스택에서 팝
	}
	cout << "스택이 비어있는가? : ";
	if (s.IsEmpty())
		cout << "그렇다" << endl;
	else
		cout << "아니다" << endl;

	Queue<int> q(5);
	cout << "큐에 삽입할 5개의 정수 입력>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		q.Push(n); //큐에 푸시
	}
	cout << "Front에 있는 원소 : " << q.Front() << endl;
	cout << "Rear에 있는 원소 : " << q.Rear() << endl;
	cout << "큐의 모든 원소를 팝하여 출력했다 " << endl;
	while (!q.IsEmpty()) {
		q.Pop(); //큐에서 팝
	}
	cout << "큐는 비어있는가? : ";
	if (q.IsEmpty())
		cout << "그렇다" << endl;
	else
		cout << "아니다" << endl;
}