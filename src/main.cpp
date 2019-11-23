#include "BST.h"
#include "Student.h"
#include <iostream>
using namespace std;

int main(){
  //cout << "1" << endl;
  BST<int> *tree = new BST<int>();
  //cout << "2" << endl;
  tree->insert(5);
  tree->insert(4);
  //cout << "3" << endl;
  tree->insert(3);
  tree->insert(2);



  //tree->insert(6);

  tree->insert(1);
  //tree->insert(9);
  //cout << "4" << endl;

  tree->printTree();

  //cout << "5" << endl;

  //tree->insert(Student(1283, 2313, "Ryan", "sophomore", "cs", 3.376));
  //tree->insert(Student(3245, 3521, "Noah", "freshman", "games", 4.000));


  cout << "lol" << endl;
  //delete[] tree;
}
