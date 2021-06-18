#pragma once
#include <iostream>
#include <utility>
using namespace std;
template <class T> class BSTNode;

template <class K, class E>
class BST {
public:
    BST();
    void Insert(const pair<K, E>& thePair);
    pair<K, E>* Get(const K& k);
    pair<K, E>* Get(BSTNode<pair<K, E>>* p, const K& k);
    pair<K, E>* IterativeGet(const K& k);
    pair<K, E>* RankGet(int r);
    int VisitCount(BSTNode<pair<K, E>>* currentNode, BSTNode<pair<K, E>>* settingNode);
    void PostOrderLeftSize(BSTNode<pair<K, E>>* settingNode);
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
    while (currentNode) {
        if (r < currentNode->getLeftSize()) currentNode = currentNode->leftChild;
        else if (r > currentNode->getLeftSize())
        {
            r -= currentNode->getLeftSize();
            currentNode = currentNode->rightChild;
        }
        else return &currentNode->data;
    }
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
    {
        if (thePair.first < pp->data.first)
        {
            pp->leftChild = p;
            PostOrderLeftSize(pp->leftChild);
        }
        else {
            pp->rightChild = p;
            PostOrderLeftSize(pp->rightChild);
        }
    }
    else
    {
        root = p;//이미 1로 세팅되어있기 때문에 별도로 안해도됨
    }
}
template <class K, class E>
void BST<K, E>::Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big)
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
template <class K, class E>
int BST<K, E>::VisitCount(BSTNode<pair<K, E>>* currentNode, BSTNode<pair<K, E>>* settingNode)
{// Workhorse.
    if (currentNode == settingNode)
        return -1;
    else
    {
        settingNode->setLeftSize();
        return 0;
    }
}
template <class K, class E>
void BST<K, E>::PostOrderLeftSize(BSTNode<pair<K, E>>* settingNode)
{// Workhorse.
    BSTNode<pair<K, E>>* currentNode = settingNode;
    if (currentNode) {
        PostOrderLeftSize(currentNode->leftChild);
        PostOrderLeftSize(currentNode->rightChild);
        int result = VisitCount(currentNode, settingNode);
        if (result == -1)
            return;
    }
    return;
}
template <class T>
class BSTNode {
private:
    int leftSize;//왼쪽 서브트리가 가진 원소수 +1이다
    T data;
    BSTNode<T>* leftChild;
    BSTNode<T>* rightChild;
public:
    BSTNode(T data) {
        this->leftSize = 1;//미리 1 더해뒀음
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
    int getLeftSize();
    void setLeftSize() { leftSize++; }
    template <class K, class E> friend class BST;
};

template <class T>
int BSTNode<T>::getLeftSize() {
    return this->leftSize;
}

