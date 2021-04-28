#pragma once
#include "ChangeSize.h"
template <class T>
class Stack
{
private:
	T* stack;                // 스택 원소 배열, T타입으로 여러 자료형 수용 가능
	int top;				 // 맨 위의 원소 가리킴
	int capacity;			 // 스택의 용량

public:
	Stack(int stackCapacity = 10);
	//용량이 stackCapacity만큼인 스택을 생성한다

	bool IsEmpty() const;
	// 원소 개수 확인함

	T& Top() const;
	// top에 있는 원소 내용 리턴

	void Push(const T& item);
	// top에 원소 추가

	void Pop();
	// top원소 삭제
};
template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1) throw "용량은 0보다 커야함";
	stack = new T[capacity];
	top = -1;
}
template <class T>
inline bool  Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T>::Top() const
{
	if (IsEmpty()) throw "스택이 비어있다";
	return stack[top];
}
template <class T>
void Stack<T>::Push(const T& x)
{//스택에 원소 추가
	if (top == capacity - 1)
	{
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}
template <class T>
void Stack<T>::Pop()
{// top원소 삭제
	if (IsEmpty()) throw "스택이 비어있어서 삭제할 수 없다";
	stack[top--].~T();   //T 소멸자
}