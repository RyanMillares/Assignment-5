
#include <iostream>
using namespace std;

class TreeNode{
public:
   TreeNode();
   TreeNode(int k);
   ~TreeNode();

   int key;
   TreeNode *left;
   TreeNode *right;
};

TreeNode::TreeNode(){
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(int k){
  key = k;
  left = NULL;
  right = NULL;
}

TreeNode::~TreeNode(){
  delete left;
  delete right;

}
