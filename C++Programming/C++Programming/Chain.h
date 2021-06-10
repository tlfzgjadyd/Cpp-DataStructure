#pragma once
#include <iostream>
using namespace std;
template <class T> class Chain; // forward declaration

template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T>* link;
public:
	ChainNode(T data) { this->data = data; link = 0; }
};

template <class T>
class Chain {
public:
	Chain() { first = 0; last = first; }; // constructor initializing first to 0
	// Chain manipulation operations
	void InsertBack(const T& e);
	void Concatenate(Chain<T>& b);
	void Reverse();
	void print();

private:
	ChainNode<T>* first;
	ChainNode<T>* last;
};
template <class T>
void Chain<T>::print()
{
	ChainNode<T>* current = first;
		while (current) {
			cout << current->data << " ";
			current = current->link;  // current moves to next node
		}
	cout << endl;
}
template <class T>
void Chain<T>::InsertBack(const T& e)
{
	if (first) {// nonempty chain
		last->link = new ChainNode<T>(e);
		last = last->link;
	}
	else first = last = new ChainNode<T>(e);
}
template <class T>
void Chain<T>::Concatenate(Chain<T>& b)
{// b is concatenated to the end of *this.
	if (first) { last->link = b.first; last = b.last; }
	else { first = b.first; last = b.last; }
	b.first = b.last = 0;
}
template <class T>
void Chain<T>::Reverse()
{// A chain is reversed so that (a sub 1 , ... , a sub n) becomes (a sub n ,  ... ,a sub 1).
	ChainNode<T>* current = first,
		* previous = 0;  // previous trails current
	while (current) {
		ChainNode<T>* r = previous;
		previous = current;               // r trails previous
		current = current->link;  // current moves to next node
		previous->link = r;  // link previous to preceding node
	}
	first = previous;
}
