#include <iostream>
#include "Chain.h"
#include "Tree.h"
#include "MaxHeap.h"
using namespace std;

int main(void) {
	Chain<int>* chain = new Chain<int>();

	Chain<int>* chain2 = new Chain<int>();
	chain->InsertBack((const int &)1);
	chain->InsertBack((const int &)2);
	chain->InsertBack((const int &)3);
	chain->InsertBack((const int &)4);
	chain->InsertBack((const int &)5);
	chain->Concatenate(*chain2);
	chain->print();
	chain->Reverse();
	chain->print();

	Tree<int>* tree=new Tree<int>();
	tree->Insert((const int&)1);
	tree->Insert((const int&)2);
	tree->Insert((const int&)3);
	tree->Insert((const int&)4);
	tree->Insert((const int&)5);
	tree->Inorder();
	cout << endl;
	tree->Preorder();
	cout << endl;
	tree->Postorder();
	cout << endl;

	MaxHeap<int>* maxHeap = new MaxHeap<int>();
	maxHeap->Push((const int&)1);
	maxHeap->Push((const int&)2);
	maxHeap->Push((const int&)3);
	maxHeap->Push((const int&)4);
	maxHeap->Push((const int&)5);
	maxHeap->print();
	maxHeap->Pop();
	maxHeap->Pop();
	maxHeap->Push((const int&)100);
	maxHeap->Push((const int&)1000);
	maxHeap->print();


	return 0;
}