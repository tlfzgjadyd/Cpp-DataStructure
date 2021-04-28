#pragma once
#include "ChangeSize.h"
template <class T>
class Stack
{
private:
	T* stack;                // ���� ���� �迭, TŸ������ ���� �ڷ��� ���� ����
	int top;				 // �� ���� ���� ����Ŵ
	int capacity;			 // ������ �뷮

public:
	Stack(int stackCapacity = 10);
	//�뷮�� stackCapacity��ŭ�� ������ �����Ѵ�

	bool IsEmpty() const;
	// ���� ���� Ȯ����

	T& Top() const;
	// top�� �ִ� ���� ���� ����

	void Push(const T& item);
	// top�� ���� �߰�

	void Pop();
	// top���� ����
};
template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1) throw "�뷮�� 0���� Ŀ����";
	stack = new T[capacity];
	top = -1;
}
template <class T>
inline bool  Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T>::Top() const
{
	if (IsEmpty()) throw "������ ����ִ�";
	return stack[top];
}
template <class T>
void Stack<T>::Push(const T& x)
{//���ÿ� ���� �߰�
	if (top == capacity - 1)
	{
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}
template <class T>
void Stack<T>::Pop()
{// top���� ����
	if (IsEmpty()) throw "������ ����־ ������ �� ����";
	stack[top--].~T();   //T �Ҹ���
}