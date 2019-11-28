#include "TreeNode.h"
#include <iostream>
using namespace std;
template <class T>
class BST{
public:
  BST();
  ~BST();

  T* search(int k);
  bool IsPresent(int k);
  void insert(TreeNode<T>* node);

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
  int getSize();
  void DeleteRoot();


};
template <class T>
BST<T>::BST(){
  root = NULL;
  size = 0;
}
template <class T>
BST<T>::~BST(){
  delete root;

}
template <class T>
int BST<T>::getSize(){
  return size;
}
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
  //cout << "The root is: " << root->key << endl;
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
  return current;
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
  return current;
}

template <class T>
void BST<T>::insert(TreeNode<T>* node){
  //TreeNode<T> *node = new TreeNode<T>(value);
  //just create the node outside the tree itself
  //note - delete instantiated nodes
  if(root == NULL){// empty tree
    root = node;
  }
  else{ //tree is not empty, let's find insertion point
    TreeNode<T> *current = root;
    TreeNode<T> *parent;
    while(true){
      parent = current;
      if(node->key < current->key){
        //we go left
        current = current->left;
        if(current == NULL){
          parent->left = node;
          break;
        }
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
  size++;
}

template <class T>
bool BST<T>::IsPresent(int k){
  if(root == NULL){
    return false;
  }
  else{
    //if we make it this far than we know tree is not empty
    TreeNode<T> *current = root;
    while(current->key != k){
      if(k < current->key){
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
T* BST<T>::search(int k){
  T useless;
  if(IsPresent(k)){
    TreeNode<T> *node = root;
    while(node->key != k){
      //go left if key is less than current node
      if(k < node->key){
        node = node->left;
      }
      else{ //this means it is more than current node key
        node = node->right;
      }
    }
    //reach here when node is found
    return node->data;
  }
  else{
    cout << "Search failed." << endl;
    return NULL;
  }
}
template <class T>
bool BST<T>::deleteNode(int value){

  if(root == NULL){
    return false;

  }
  TreeNode<T> *parent = root;
  TreeNode<T> *current = root;
  TreeNode<T> *theRoot;
  TreeNode<T> *hold;
  bool isDone = false;
  bool isLeft = true;

  while(current->key != value){
    cout << "is run" << endl;
    parent = current;
    if(value < current->key){ //is to  the left
      isLeft = true;
      current = current->left;
    }
    else if(value > current->key){ //is to the right
      isLeft = false;
      current = current->right;
    }

    if(current == NULL){
      return false;
    }
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
    else if(current->left == NULL){ //node to delete has 1 child, it's right no left
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
    else if(current->right == NULL){ //node to delete has 1 child, it's left no right
      if(current == root){
        root = current->left;
      }
      else if(isLeft){
        parent->left = current->left;
      }
      else{
        parent->right = current->left;
      }
    }
    else if(current == root){

      DeleteRoot();

    }
    else{
      cout << "is root" << endl;
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
    size--;
    return true;




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

    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
} // d is node to delete

template <class T>
//take the root
void BST<T>::DeleteRoot(){

  TreeNode<T>* current = root;
  TreeNode<T>* child;
  TreeNode<T>* hold;
  TreeNode<T>* hold1;
  //case 1: tree of one
  cout << size << endl;
  if(size == 1){
    cout << "test" << endl;
    current = NULL;
    root = NULL;
  }
  //case 2: only left subtree
  else if(current->left != NULL && current->right == NULL){
    root = current->left;
    current = NULL;
  }
    //case 3: only right subtree
  else if(current->left == NULL && current->right != NULL){
    root = current->right;
    current = NULL;
  }
  //case 4: left and right
  else if(current->left != NULL && current->right != NULL){
    cout << "has both" << endl;
    child = current->right;
    if(child->left == NULL){ //right subtree has only right subtree
      root = child;
      root->left = current->left;
      current = NULL;
    }
    else{ //right subtree has left AND right
      while(child->left != NULL){
        //go until child is next one
        hold = child;
        child = child->left;
      }
      if(child->right == NULL){ //is a leaf node
        //we can swappy swap
        hold = child;
        child = NULL;
        hold->right = current->right;
        hold->left = current->left;
        root = hold;
        hold = NULL;
        current = NULL;

      }
      else{ //it has a right node
        hold1 = child;
        child = child->right;
        hold1->right = current->right;
        hold1->left = current->left;
        root = hold1;
        current = NULL;
        //this was painful and im leaving this comment here so you know it was

      }
    }

  }
}
