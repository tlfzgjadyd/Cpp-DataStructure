#pragma once
template <class T> class Tree; // forward declaration

template <class T>
class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
};
template <class T>
class Tree {
public:
    // Tree operations
    void Insert();
    void Insert(TreeNode<T>* currentNode, T value);
    void Inorder();
    void Inorder(TreeNode<T>* currentNode);
    void Preorder();
    void Preorder(TreeNode<T>* currentNode);
    void Postorder();
    void Postorder(TreeNode<T>* currentNode);

    .
private:
    TreeNode<T>* root;
};
template <class T>
void Tree<T>::Insert()
{
    Insert(root, root->value);
}
template <class T>
void Tree<T>::Insert(TreeNode<T>* currentNode, T value)
{
    TreeNode<T> tempNode = new TreeNode(value);
    if (currentNode->data > value)
    {
        if (currentNode->leftChild == NULL)//자식이 없으면 그자리에 삽입
            currentNode->leftChild = tempNode;
        else
            Insert(currentNode->leftChild, value);//currentNode의 왼쪽으로 이동해서 다시 확인
    }
    else
    {
        if (currentNode->rightChild == NULL)//자식이 없으면 그자리에 삽입
            currentNode->rightChild = tempNode;
        else
            Insert(currentNode->rightChild, value);//currentNode의 오른쪽으로 이동해서 다시 확인
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