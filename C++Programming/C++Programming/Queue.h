#pragma once
#include <algorithm>
using namespace std;
template <class T>
class Queue
{
private:
	T* queue;           //ť ���� �迭
	int front;          //front���� ����Ű��
	int rear;           //rear���� ����Ű��
	int capacity;       //ť �迭�� �뷮
public:
	Queue(int queueCapacity = 10);
	// ���� �뷮 queueCapacity�� ť ����

	bool IsEmpty() const;
	// ���� ���� 0���� �˻�

	T& Front() const;
	// front�� ���Ҹ� �����ش�

	T& Rear() const;
	// rear�� ���Ҹ� �����ش�

	void Push(const T& item);
	// rear�� ���� �߰�

	void Pop();
	// front�� ���� ����
};
template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1) throw "ť �뷮�� 0���� Ŀ���Ѵ�";
	queue = new T[capacity];
	front = rear = 0;
}
template <class T>
inline bool Queue<T>::IsEmpty() const { return front == rear; }

template <class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty()) throw "ť�� ����־ front���� ���� ����";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty()) throw "ť�� ����־ rear���� ���� ����";
	return queue[rear];
}
template <class T>
void Queue<T>::Push(const T& x)
{// rear�� ���� �߰�
	if ((rear + 1) % capacity == front)
	{// ť�� ���� ��� �뷮�� 2��� �ø���
		T* newQueue = new T[2 * capacity];

		// ť���� �� ť�� �����Ѵ�
		int start = (front + 1) % capacity;
		if (start < 2)
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);
		}

		// �� ť�� �ٲ۴�
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
{// ť�� front���� ���� ����
	if (IsEmpty()) throw "ť�� �� ���� �Ұ���";
	front = (front + 1) % capacity;
	queue[front].~T();   // T �Ҹ���
}