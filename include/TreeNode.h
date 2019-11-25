#include <iostream>
using namespace std;
template <class T>
class TreeNode{
public:
  TreeNode<T>* right;
  TreeNode<T>* left;
  int key;
  T data;
  //changing to pointer to reference default constructors if needed

  TreeNode();
  TreeNode(int k);
  TreeNode(int k, T d);
  ~TreeNode();


};
template <class T>
TreeNode<T>::TreeNode(){
  key = 0;
  right = NULL;
  left = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k){
  key = k;
  right = NULL;
  left = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, T d){
  data = d;
  key = k;
  right = NULL;
  left = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete left;
  delete right;
  //delete data;
}
