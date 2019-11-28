#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(){
  studentId = -1;
  advisorId = 0;
  name = "N/A";
  level = "N/A";
  major = "N/A";
  gpa = -1.0;
  hasAdvisor = false;
}
Student::Student(int id1, string name1, string level1, string major1, double gpa1, int adId){
  studentId = id1;
  name = name1;
  level = level1;
  major = major1;
  gpa = gpa1;
  advisorId = adId;
  if(advisorId != 0){
    hasAdvisor = true;
  }
  //hasAdvisor = false;
}

void Student::setAdvisor(int newId){
  gpa = newId;

  this->advisorId = newId;
  hasAdvisor = true;


}
void Student::ResetAdvisor(){
  advisorId = 0;
  hasAdvisor = false;
}

void Student::PrintStudentData(){
  cout << "Student ID: " << studentId << endl;
  cout << "   Name: " << name << "       Level:  " << level <<"       Major: "<< major << endl;
  cout << "   GPA: " << gpa << endl;
  if(!hasAdvisor){
    cout << "   Advisor ID: None assigned" << endl;
  }
  else{
    cout << "   Advisor ID: " << advisorId << endl;
  }

}

bool operator>(Student& s1, Student& s2){
  return (s1.studentId > s2.studentId);
}
bool operator<(Student& s1, Student& s2){
  return (s1.studentId < s2.studentId);
}
bool operator==(Student& s1, Student& s2){
  return (s1.studentId == s2.studentId);
}
bool operator!=(Student& s1, Student& s2){
  return (s1.studentId != s2.studentId);
}
