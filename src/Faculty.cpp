#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty(){
  facultyId = -1;
  numOfAdvisees = 0;
  name = "N/A";
  level = "N/A";
  department = "N/A";
  adviseeList = NULL;
}
Faculty::Faculty(int id1, string name1, string level1, string department1){

  facultyId = id1;
  numOfAdvisees = 0;
  name = name1;
  level = level1;
  department = department1;

  adviseeList = new GenLinkedList<int>();

}
Faculty::~Faculty(){
  delete adviseeList;
  //removed to prevent invalid pointer error
  //jk it works now apparently
}

void Faculty::addAdvisee(int newId){
  adviseeList->insertFront(newId);
  numOfAdvisees++;
}

void Faculty::PrintFacultyData(){
  cout << "Faculty ID: " << facultyId << endl;
  //cout << "   " << name << ", "<< level << ", " << department << endl;
  cout << "   Name: " << name << endl;
  cout << "   Level: " << level << endl;
  cout << "   Department: " << department << endl;
  ListAdviseeIds();
}

void Faculty::deleteAdvisee(int id){
  if(adviseeList->IsInList(id)){
    cout << adviseeList->find(id) << endl;
    adviseeList->deletePos(adviseeList->find(id));
    numOfAdvisees--;
  }
  else{
    //cout << "This faculty has no advisee with ID " << id << endl;
  }
}
bool Faculty::CheckAdvisees(){
  //list all the advisees of list
  if(adviseeList->getSize() == 0){
    cout << "This faculty has no advisees." << endl;
    return false;
  }
  return true;
}
void Faculty::ListAdviseeIds(){
  if(CheckAdvisees()){
    cout <<    "Advisee IDs: " << endl;
    ListNode<int>* current = adviseeList->front;
    cout << "   | ";
    while(current != NULL){
      cout << current->data << " | ";
      current = current->next;

    }
    cout << endl;
  }
  else{
    //cout << "   This faculty has no advisees." << endl;
  }
}
bool operator>(Faculty& f1, Faculty& f2){
  return (f1.facultyId > f2.facultyId);
}
bool operator<(Faculty& f1, Faculty& f2){
  return (f1.facultyId < f2.facultyId);
}
bool operator==(Faculty& f1, Faculty& f2){
  return (f1.facultyId == f2.facultyId);
}
bool operator!=(Faculty& f1, Faculty& f2){
  return (f1.facultyId != f2.facultyId);
}
