#include "Database.h"
#include <iostream>
#include <fstream>
using namespace std;
Database::Database(){
  masterStudent = new BST<Student>();
  masterFaculty = new BST<Faculty>();
}
Database::~Database(){
  delete masterStudent;
  delete masterFaculty;
}

void Database::ReadInStudents(){
  //search for file "studentTable"
  //if exists, read in data
}
void Database::ReadInFaculty(){
  //search for file "facultyTable"
  //if exists, read in data
}
void Database::PrintStudents(){
  //Print all students and info in order of ID
}
void Database::PrintFaculty(){
  //print all faculty and their info
}
void Database::FindStudent(int id){
  //Print student info given their ID
}
void Database::FindFaculty(int id){
  //Print faculty info given their id
}
void Database::AddStudent(Student student){
  TreeNode<Student>* node = new TreeNode<Student>(student.studentId, student);
  masterStudent->insert(node);
  //adds a student to database
}
void Database::DeleteStudent(int id){
  //check if id exists in tree
  //if exists, deletes a student given the id
}
void Database::AddFaculty(Faculty faculty){
  TreeNode<Faculty>* node = new TreeNode<Faculty>(faculty.facultyId, faculty);
  masterFaculty->insert(node);

  //adds a faculty to database
}
void Database::DeleteFaculty(int id){
  //checks if id exists in tree
  //if exists, deletes a faculty given the id
}
void Database::ChangeAdvisor(int ids, int idf){
  //search for student of given id
  //if found, check if faculty id exists
  //if exists, add as setAdvisor

}
void Database::RemoveAdvisee(int ids, int idf){
  //checks if faculty if exists
  //if exists, checks if provided id exists in list
  //if exists, removes
}
void Database::RollBack(){
  //yahh it's rewind time

}
void Database::ExitProgram(){
  //exist
}
