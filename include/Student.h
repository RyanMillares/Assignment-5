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
  bool hasAdvisor;

  Student();
  Student(int id1, string name1, string level1, string major1, double gpa1, int adId);

  void setAdvisor(int newId);
  void PrintStudentData();
  void ResetAdvisor();





};
  //overloaded ops
bool operator> (Student& s1, Student& s2);
bool operator< (Student& s1, Student& s2);
bool operator== (Student& s1, Student& s2);
bool operator!= (Student& s1, Student& s2);
