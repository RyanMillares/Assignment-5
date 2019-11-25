#include <iostream>
using namespace std;
class Student{
public:
  int studentId;
  int advisorId;
  string name;
  string level;
  string major;
  double gpa;

  Student();
  Student(int id1, string name1, string level1, string major1, double gpa1);
  void setAdvisor(int newId);
  void PrintStudentData();
};
