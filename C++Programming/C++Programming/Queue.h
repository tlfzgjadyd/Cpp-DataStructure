#pragma once
#include <algorithm>
using namespace std;
template <class T>
class Queue
{
private:
	T* queue;           //큐 원소 배열
	int front;          //front원소 가리키게
	int rear;           //rear원소 가리키게
	int capacity;       //큐 배열의 용량
public:
	Queue(int queueCapacity = 10);
	// 최초 용량 queueCapacity인 큐 생성

	bool IsEmpty() const;
	// 원소 개수 0인지 검사

	T& Front() const;
	// front의 원소를 돌려준다

	T& Rear() const;
	// rear의 원소를 돌려준다

	void Push(const T& item);
	// rear에 원소 추가

	void Pop();
	// front의 원소 삭제
};
template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1) throw "큐 용량은 0보다 커야한다";
	queue = new T[capacity];
	front = rear = 0;
}
template <class T>
inline bool Queue<T>::IsEmpty() const { return front == rear; }

template <class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty()) throw "큐가 비어있어서 front에도 원소 없음";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty()) throw "큐가 비어있어서 rear에도 원소 없음";
	return queue[rear];
}
template <class T>
void Queue<T>::Push(const T& x)
{// rear에 원소 추가
	if ((rear + 1) % capacity == front)
	{// 큐가 꽉찬 경우 용량을 2배로 늘린다
		T* newQueue = new T[2 * capacity];

		// 큐에서 새 큐로 복사한다
		int start = (front + 1) % capacity;
		if (start < 2)
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);
		}

		// 새 큐로 바꾼다
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = x;
}
template <class T>
void Queue<T>::Pop()
{// 큐의 front에서 원소 삭제
	if (IsEmpty()) throw "큐가 비어서 삭제 불가능";
	front = (front + 1) % capacity;
	queue[front].~T();   // T 소멸자
}