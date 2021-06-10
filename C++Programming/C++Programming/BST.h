#pragma once
#include <iostream>
#include <utility>
using namespace std;
template <class T> class BSTNode;

template <class K, class E>
class BST {
public:
    BST();
    pair<K, E>* Get(const K& k);
    pair<K, E>* Get(BSTNode<pair<K, E>>* p, const K& k);
    pair<K, E>* IterativeGet(const K& k);
    pair<K, E>* RankGet(int r);
    void Insert(const pair<K, E>& thePair);
    void Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big);
private:
    BSTNode<pair<K, E>>* root;
};
template <class K, class E>
BST<K, E>::BST() {
    root = 0;
}
template <class K, class E>  // Driver
pair<K, E>* BST<K, E>::Get(const K& k)
{// Search the binary search tree (*this) for a pair with key k.
// If such a pair is found, return a pointer to this pair; otherwise, return 0.
    return Get(root, k);
}

template <class K, class E>
pair<K, E>* BST<K, E>::Get(BSTNode<pair<K, E>>* p, const K& k) {
    if (!p) return 0;
    if (k < p->data.first) return Get(p->leftChild, k);
    if (k > p->data.first) return Get(p->rightChild, k);
    return &p->data;
}
template <class K, class E>  // Iterative version
pair<K, E>* BST<K, E>::IterativeGet(const K& k)
{
    BSTNode<pair<K, E> >* currentNode = root;
    while (currentNode)
    {
        if (k < currentNode->data.first)
            currentNode = currentNode->leftChild;
        else if (k > currentNode->data.first)
            currentNode = currentNode->rightChild;
        else return &currentNode->data;
    }
    // no matching pair
    return 0;
}
template <class K, class E>  // search by rank
pair<K, E>* BST<K, E>::RankGet(int r)
{// Search the binary search tree for the rth smallest pair.
    BSTNode<pair<K, E> >* currentNode = root;
    while (currentNode)
        if (r < currentNode->leftSize) currentNode = currentNode->leftChild;
        else if (r > currentNode->leftSize)
        {
            r -= currentNode->leftSize;
            currentNode = currentNode->rightChild;
        }
        else return &currentNode->data;
    return 0;
}
template <class K, class E>
void BST<K, E>::Insert(const pair<K, E>& thePair)
{// Insert thePair into the binary search tree.
// search for thePair.first, pp is parent of p
    BSTNode<pair<K, E> >* p = root, * pp = 0;
    while (p) {
        pp = p;
        if (thePair.first < p->data.first) p = p->leftChild;
        else if (thePair.first > p->data.first) p = p->rightChild;
        else //  duplicate, update associated element
        {
            p->data.second = thePair.second; return;
        }
    }

    // perform insertion
    p = new BSTNode<pair<K, E>>(thePair);
    if (root)  // tree not empty
        if (thePair.first < pp->data.first) pp->leftChild = p;
        else pp->rightChild = p;
    else root = p;
}
template <class K, class E>
void BST<K, E>::Split(const K& k, BST<K, E>& small,
    pair<K, E>*& mid, BST<K, E>& big)
{// Split the binary search tree with respect to key k.
    if (!root) { small.root = big.root = 0; return; } // empty tree
    // create header nodes for small and big
    BSTNode<pair<K, E> >* sHead = new BSTNode<pair<K, E> >,
        * s = sHead,
        * bHead = new BSTNode<pair<K, E> >,
        * b = bHead,
        * currentNode = root;
    while (currentNode)
        if (k < currentNode->data.first) {// add to big
            b->leftChild = currentNode;
            b = currentNode; currentNode = currentNode->leftChild;
        }
        else if (k > currentNode->data.first) {// add to small
            s->rightChild = currentNode;
            s = currentNode; currentNode = currentNode->rightChild;
        }
        else {// split at currentNode
            s->rightChild = currentNode->leftChild;
            b->leftChild = currentNode->rightChild;
            small.root = sHead->rightChild; delete sHead;
            big.root = bHead->leftChild; delete bHead;
            mid = new pair<K, E>(currentNode->data.first,
                currentNode->data.second);
            delete currentNode;
            return;
        }
    // no pair with key k
    s->rightChild = b->leftChild = 0;
    small.root = sHead->rightChild; delete sHead;
    big.root = bHead->leftChild; delete bHead;
    mid = 0;
    return;
}
template <class T>
class BSTNode {
private:
    T data;
    BSTNode<T>* leftChild;
    BSTNode<T>* rightChild;
public:
    BSTNode(T data) {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
    template <class K, class E> friend class BST;
};
