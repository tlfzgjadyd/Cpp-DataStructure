#pragma once
#include <iostream>
using namespace std;

template <class T>
class MaxHeap {
public:
    MaxHeap(int theCapacity = 10);
    void Push(const T& e);
    void Pop();
    bool IsEmpty();
    void ChangeSize1D(T* heap, int oldCapacity, int newCapacity);
    void print();
private:
    T* heap;                 //  element array
    int heapSize; // number of elements in heap
    int capacity; // size of the array heap
};
template <class T>
void MaxHeap<T>::print() {
    for (int i = 1; i <= heapSize; i++)//heap[0]은 쓰지 않는댔으므로
        cout << heap[i] << " ";
    cout << endl;
}
template <class T>
void MaxHeap<T>::ChangeSize1D(T* heap, int oldCapacity, int newCapacity) {
    MaxHeap<T>* tempMaxHeap = new MaxHeap<T>(newCapacity);
    for (int i = 1; i <= oldCapacity; i++)//heap[0]은 쓰지 않는댔으므로
    {
        tempMaxHeap->heap[i] = this->heap[i];
    }
    this->heap = tempMaxHeap->heap;
    this->heapSize = oldCapacity;
    this->capacity = newCapacity;
}
template <class T>
bool MaxHeap<T>::IsEmpty() {
    if (heapSize == 0)
        return true;
    else
        return false;
}
template <class T>
MaxHeap<T>::MaxHeap(int theCapacity)
{
    if (theCapacity < 1) throw "Capacity must be >= 1.";
    capacity = theCapacity;
    heapSize = 0;
    heap = new T[capacity + 1]; // heap[0] is not used
}
template <class T>
void MaxHeap<T>::Push(const T& e)
{// Insert e into the max heap.
    if (heapSize == capacity) {// double the capacity
        ChangeSize1D(heap, capacity, 2 * capacity);
        capacity *= 2;
    }
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < e)
    {// bubble up
        heap[currentNode] = heap[currentNode / 2];  // move parent down
        currentNode /= 2; // move to parent
    }
    heap[currentNode] = e;
}
template <class T>
void MaxHeap<T>::Pop()
{// Delete max element.
    if (IsEmpty()) throw "Heap is empty. Cannot delete.";
    heap[1].~T();   // delete max element

    // remove last element from heap
    T lastE = heap[heapSize--];

    // trickle down
    int currentNode = 1;   // root
    int child = 2; // a child of currentNode
    while (child <= heapSize)
    {
        // set child to larger child of currentNode
        if (child < heapSize && heap[child] < heap[child + 1]) child++;

        // can we put lastE in currentNode?
        if (lastE >= heap[child]) break;   // yes

        // no
        heap[currentNode] = heap[child];              // move child up
        currentNode = child; child *= 2;   // move down a level
    }
    heap[currentNode] = lastE;
}