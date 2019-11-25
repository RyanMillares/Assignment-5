#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(){
  studentId = -1;
  advisorId = -1;
  name = "N/A";
  level = "N/A";
  major = "N/A";
  gpa = -1.0;
}
Student::Student(int id1, string name1, string level1, string major1, double gpa1){
  studentId = id1;

  name = name1;
  level = level1;
  major = major1;
  gpa = gpa1;
}

void Student::setAdvisor(int newId){
  advisorId = newId;
}

void Student::PrintStudentData(){
  cout << "Student ID: " << studentId << endl;
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gpa << endl;
  if(advisorId == -1){
    cout << "Advisor ID: None assigned" << endl;
  }
  else{
    cout << "Advisor ID: " << advisorId << endl;
  }



}
