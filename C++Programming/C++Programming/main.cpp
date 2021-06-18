#pragma once
#include <iostream>
#include "Chain.h"
#include "Tree.h"
#include "MaxHeap.h"
#include "BST.h"
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
	//chain->print();
	chain->Reverse();
	//chain->print();

	Tree<int>* tree=new Tree<int>();
	tree->Insert((const int&)1);
	tree->Insert((const int&)2);
	tree->Insert((const int&)3);
	tree->Insert((const int&)4);
	tree->Insert((const int&)5);
	//tree->Inorder();
	cout << endl;
	//tree->Preorder();
	cout << endl;
	//tree->Postorder();
	cout << endl;

	MaxHeap<int>* maxHeap = new MaxHeap<int>();
	maxHeap->Push((const int&)1);
	maxHeap->Push((const int&)2);
	maxHeap->Push((const int&)3);
	maxHeap->Push((const int&)4);
	maxHeap->Push((const int&)5);
	//maxHeap->print();
	maxHeap->Pop();
	maxHeap->Pop();
	maxHeap->Push((const int&)100);
	maxHeap->Push((const int&)1000);
	//maxHeap->print();

	BST<string, int>* bst = new BST<string, int>();
	bst->Insert(make_pair("a", 1));
	bst->Insert(make_pair("b", 2));
	bst->Insert(make_pair("c", 3));
	bst->Insert(make_pair("d", 4));
	bst->Insert(make_pair("e", 5));
	//cout << "key : "<<bst->Get((const string&)("a"))->first << " value : "<<bst->Get((const string &)("a"))->second<<endl;
	BSTNode<pair<string, int>>* bstNode = new BSTNode<pair<string, int>>(pair<string, int>("b", 2));
	//cout << "key : " << bst->Get((BSTNode<pair<string, int>>*)bstNode, (const string&)("b"))->first << " value : " << bst->Get((BSTNode<pair<string, int>>*)bstNode, (const string&)("b"))->second << endl;
	//cout << "key : " << bst->IterativeGet((const string&)("c"))->first << " value : " << bst->IterativeGet((const string&)("c"))->second << endl;
	//cout << "key : " << bst->RankGet(5)->first << " value : " << bst->RankGet(5)->second << endl;
	//void Split(const K & k, BST<K, E>&small, pair<K, E>*&mid, BST<K, E>&big);
	return 0;
}