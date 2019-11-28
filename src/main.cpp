
#include "Database.h"

#include <iostream>
using namespace std;

int main(){
  /**
  BST<int> *tree = new BST<int>();

  for(int i = 0; i < 5; ++i){
    int j;
    if(i%2 == 0){
      j = i + 5;
    }
    else{
      j = -i + 5;
    }
    int num = j;
    TreeNode<int>* node = new TreeNode<int>(j, num);
    tree->insert(node);
  }
  //tree->insert(9);
  //cout << "4" << endl;
  tree->deleteNode(5);
  tree->printTree();
 **/

  Database db;
  db.RunProgram();
  /**
  Student *hi = new Student(5217, "Ryan", "Sophomore", "Computer science", 3.0, 123);
  hi->PrintStudentData();
  hi->ResetAdvisor();
  hi->PrintStudentData();
  hi->setAdvisor(5432);
  hi->PrintStudentData();
  **/
  //cout << "5" << endl;

  //tree->insert(Student(1283, 2313, "Ryan", "sophomore", "cs", 3.376));
  //tree->insert(Student(3245, 3521, "Noah", "freshman", "games", 4.000));


  //delete tree;
}
