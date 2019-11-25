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
Student::Student(int id1, int id2, string name1, string level1, string major1, double gpa1){
  studentId = id1;
  advisorId = id2;
  name = name1;
  level = level1;
  major = major1;
  gpa = gpa1;
}

void Student::setAdvisor(int newId){
  advisorId = newId;
}

void Student::PrintStudentData(){
  cout << "Name: " << name << endl;


}