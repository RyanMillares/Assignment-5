#include <iostream>
using namespace std;
template <class T>
class TreeNode{
public:
  TreeNode<T>* right;
  TreeNode<T>* left;
  int key;
  T data;

  TreeNode();
  TreeNode(int key);
  TreeNode(int key, T data);
  ~TreeNode();


};
template <class T>
TreeNode<T>::TreeNode(){
  key = 0;
  right = NULL;
  left = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int key){
  this->key = key;
  right = NULL;
  left = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int key, T data){
  this.data = data;
  this.key = key;
  right = NULL;
  left = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete left;
  delete right;
}
