#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty(){
  facultyId = -1;
  name = "N/A";
  level = "N/A";
  department = "N/A";
  adviseeList = new GenLinkedList<int>();
}
Faculty::Faculty(int id1, string name1, string level1, string department1){
  facultyId = id1;
  name = name1;
  level = level1;
  department = department1;
  adviseeList = new GenLinkedList<int>();
}
Faculty::~Faculty(){
  delete adviseeList;
}

void Faculty::addAdvisee(int newId){
  adviseeList->insertFront(newId);
}
