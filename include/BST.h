#include "TreeNode.h"
#include <iostream>
using namespace std;
template <class T>
class BST{
public:
  BST();
  ~BST();

  bool search(T value);
  void insert(T value);

  //delete placeholder


  //helper functions
  TreeNode<T>* root;
  int size;
  bool isEmpty();
  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  TreeNode<T>* getSuccessor(TreeNode<T> *d);
  bool deleteNode(int value);
  void printTree();
  void recPrint(TreeNode<T>* node);


};
template <class T>
BST<T>::BST(){
  root = NULL;
}
template <class T>
BST<T>::~BST(){
  delete root;

}
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
  cout << "The root is: " << root->key << endl;
  if(node == NULL){
    return;

  }
  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);


}

template <class T>
void BST<T>::printTree(){
  recPrint(root);
}

template <class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T> *current = root;
  if(root == NULL){
    return NULL;

  }
  while(current->right != NULL){
    current = current->right;//keep going to the right
  }
}

template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *current = root;
  if(root == NULL){
    return NULL;

  }
  while(current->left != NULL){
    current = current->left;//keep going to the right
  }
}

template <class T>
void BST<T>::insert(T value){
  TreeNode<T> *node = new TreeNode<T>(value);
  if(root == NULL){// empty tree
    root = node;
  }
  else{ //tree is not empty, let's find insertion point
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;
    while(true){
      parent = current;

      if(value < current->key){
        //we go left
        current = current->left;
        if(current == NULL){
          parent->left = node;
          break;
        }
        else{
          current = current->right;
          if(current == NULL){
            parent->right = node;
            break;
          }
        }
      }
    }
  }
}

template <class T>
bool BST<T>::search(T value){
  if(root == NULL){
    return false;
  }
  else{
    //if we make it this far than we know tree is not empty
    TreeNode<T> *current = root;
    while(current->key != value){
      if(value < current->key){
        current = current->left;
      }
      else{
        current = current->right;
      }
      if(current == NULL){ // value not in tree {
        return false;
      }
    }
    return true;
  }
}

template <class T>
bool BST<T>::deleteNode(int value){
  if(root == NULL){
    return false;

  }
  TreeNode<T> *parent = root;
  TreeNode<T> *current = root;
  bool isLeft = true;

  while(current->key != value){
    parent = current;
    if(value < current->key){
      isLeft = true;
      current = current->left;
    }
    else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){
      return false;
    }
    //if we make it hear, we found the node to delete
    if(current->left == NULL && current->right == NULL){
      //then node is leaf, no children
      if(current==NULL){
        root = NULL;
      }
      else if(isLeft){
        parent->left = NULL;

      }
      else{
        parent->right = NULL;
      }

    }
    else if(current->right == NULL){ //node to delete has 1 child, it's right no left
      if(current == root){
        root = current->right;
      }
      else if(isLeft){
        parent->left = current->right;
      }
      else{
        parent->right = current->right;
      }
    }
    else{
      //the node to be deleted has 2 children, at this state the cortisol increase exponentially
      TreeNode<T> *successor = getSuccessor(current);
      if(current == root){
        root = successor;

      }
      else if(isLeft){
        parent->left = successor;
      }
      else{
        parent->right = successor;
      }
      successor->left = current->left;
    }
    return true;
  }


}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){// d is node to delete
  TreeNode<T> *current = d->right;
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }
  //we made here, means we found getSuccessor
  if(successor != d->right){
    //sp->left =
  }
} // d is node to delete
