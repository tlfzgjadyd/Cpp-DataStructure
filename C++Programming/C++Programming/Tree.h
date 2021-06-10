#pragma once
#include <iostream>
using namespace std;
template <class T> class Tree; // forward declaration

template <class T>
class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
public:
    TreeNode(T data) { this->data = data; 
                       this->leftChild = NULL; 
                       this->rightChild = NULL; }
};
template <class T>
class Tree {
public:
    // Tree operations
    void Insert(const T& e);
    void Insert(TreeNode<T>* currentNode, const T& e);
    void Inorder();
    void Inorder(TreeNode<T>* currentNode);
    void Preorder();
    void Preorder(TreeNode<T>* currentNode);
    void Postorder();
    void Postorder(TreeNode<T>* currentNode);
    void Visit(TreeNode<T>* currentNode);
private:
    TreeNode<T>* root;
};
template <class T>
void Tree<T>::Visit(TreeNode<T>* currentNode) {
    cout << currentNode->data << " ";
}
template <class T>
void Tree<T>::Insert(const T& e)
{
    Insert(root, e);
}
template <class T>
void Tree<T>::Insert(TreeNode<T>* currentNode, const T& e)
{
    TreeNode<T>* tempNode = new TreeNode<T>(e);
    if (currentNode == 0)
    {
        root = tempNode;
    }
    else if (currentNode->data > e)
    {
        if (currentNode->leftChild == NULL)//�ڽ��� ������ ���ڸ��� ����
            currentNode->leftChild = tempNode;
        else
            Insert(currentNode->leftChild, e);//currentNode�� �������� �̵��ؼ� �ٽ� Ȯ��
    }
    else
    {
        if (currentNode->rightChild == NULL)//�ڽ��� ������ ���ڸ��� ����
            currentNode->rightChild = tempNode;
        else
            Insert(currentNode->rightChild, e);//currentNode�� ���������� �̵��ؼ� �ٽ� Ȯ��
    }

}
 template <class T>
 void Tree<T>::Inorder()
 {// Driver calls workhorse for traversal of entire tree.  The driver is
 // declared as a public member function of Tree.
     Inorder(root);
 }

 template <class T>
 void Tree<T>::Inorder(TreeNode<T> *currentNode)
 {// Workhorse traverses the subtree rooted at currentNode.
 // The workhorse is declared as a private member function of Tree.
   if (currentNode) {
     Inorder(currentNode->leftChild);
     Visit(currentNode);
     Inorder(currentNode->rightChild);
   }
 }
 template <class T>
 void Tree<T>::Preorder()
 {// Driver.
     Preorder(root);
 }

 template <class T>
 void Tree<T>::Preorder(TreeNode<T>* currentNode)
 {// Workhorse.
     if (currentNode) {
         Visit(currentNode);
         Preorder(currentNode->leftChild);
         Preorder(currentNode->rightChild);
     }
 }
 template <class T>
 void Tree<T>::Postorder()
 {// Driver.
     Postorder(root);
 }

 template <class T>
 void Tree<T>::Postorder(TreeNode<T>* currentNode)
 {// Workhorse.
     if (currentNode) {
         Postorder(currentNode->leftChild);
         Postorder(currentNode->rightChild);
         Visit(currentNode);
     }
 }