#include<iostream>
#include<algorithm>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main(void) {
	Stack<int> s(5);
	int n;
	cout << "���ÿ� ������ 5���� ���� �Է�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		s.Push(n); //���ÿ� Ǫ��
	}
	cout << "Top�� �ִ� ���� : " << s.Top() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����ߴ� " << endl;
	while (!s.IsEmpty()) {
		s.Pop(); //���ÿ��� ��
	}
	cout << "������ ����ִ°�? : ";
	if (s.IsEmpty())
		cout << "�׷���" << endl;
	else
		cout << "�ƴϴ�" << endl;

	Queue<int> q(5);
	cout << "ť�� ������ 5���� ���� �Է�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		q.Push(n); //ť�� Ǫ��
	}
	cout << "Front�� �ִ� ���� : " << q.Front() << endl;
	cout << "Rear�� �ִ� ���� : " << q.Rear() << endl;
	cout << "ť�� ��� ���Ҹ� ���Ͽ� ����ߴ� " << endl;
	while (!q.IsEmpty()) {
		q.Pop(); //ť���� ��
	}
	cout << "ť�� ����ִ°�? : ";
	if (q.IsEmpty())
		cout << "�׷���" << endl;
	else
		cout << "�ƴϴ�" << endl;
}