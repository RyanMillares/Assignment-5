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
  int size;
  bool isEmpty();
  TreeNode* getMin();
  TreeNode* getMax();
  void printTree();
  void recPrint(TreeNode *node);


};

BST::BST(){
  root = NULL
}

BST::~BST(){
  //lol

}
void BST::recPrint(TreeNode *node){
  if(node == NULL){
    return;

  }
  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);

}
void BST::printTree(){
  recPrint(root);
}
TreeNode* BST::getMax(){
  TreeNode *current = root;
  if(root == NULL){
    return NULL;

  }
  while(current->right != NULL){
    cureent = current->right;//keep going to the right
  }
}
TreeNode* BST::getMin(){
  TreeNode *current = root;
  if(root == NULL){
    return NULL;

  }
  while(current->left != NULL){
    cureent = current->left;//keep going to the right
  }
}

void BST::insert(T value){
  TreeNode *node = TreeNode(value);
  if(root == NULL){// empty tree
    root = node;
  }
  else{ //tree is not empty, let's find insertion point
    TreeNode *current = root;
    TreeNode *parent = NULL;
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

bool BST::search(T value){
  if(root == NULL){
    return false;
  }
  else{
    //if we make it this far than we know tree is not empty
    TreeNode *current = root;
    while(current->key != value){
      if(value < current->key){
        current = current->left;
      }
      else(
        current = current->right;
      )
      if(current == NULL){ // value not in tree {
        return false;
      }
    }
    return true;
  }
}

bool BST::deleteNode(int value){
  if(root == NULL){
    return false;

  }
  TreeNode *parent = root;
  TreeNode *current = root;
  bool isLeft = true;

  while(curent->key != value){
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
      else if(isLeft()){
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
      else if(isLeft()){
        parent->left = current->right;
      }
      else{
        parent->right = current->right;
      }
    }
    else{
      //the node to be deleted has 2 children, at this state the cortisol increase exponentially
      TreeNode *successor = getSuccessor(current);
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
TreeNode* BST::getSuccessor(TreeNode *d){// d is node to delete
  TreeNode *current = d->right;
  TreeNode *sp = d;
  TreeNode *successor = d;
  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }
  //we made here, means we found getSuccessor
  if(successor != d->right){
    sp->left =
  }
} // d is node to delete
