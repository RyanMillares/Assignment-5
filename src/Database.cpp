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
//must take in root to work
void Database::PrintStudents(TreeNode<Student>* node){
  //TreeNode<Student>* node = masterStudent->root;
  if(node != NULL){//tree exists
    //recursively print through the tree
    if(node->left != NULL){
      PrintStudents(node->left);
    }
    node->data.PrintStudentData();
    if(node->right != NULL){
      PrintStudents(node->right);
    }
  }
  else{
    cout << "There are no students in Student Database." << endl;
  }
  //Print all students and info in order of ID

}
void Database::PrintFaculty(TreeNode<Faculty>* node){
  if(node != NULL){//tree exists
    //recursively print through the tree
    if(node->left != NULL){
      PrintFaculty(node->left);
    }
    node->data.PrintFacultyData();
    if(node->right != NULL){
      PrintFaculty(node->right);
    }
  }
  else{
    cout << "There are no faculty in Faculty Database." << endl;
  }
  //print all faculty and their info
}
void Database::FindStudent(int id){

  //Print student info given their ID
  if(masterStudent->size == 0){
    cout << "Student Database is empty" << endl;
  }
  else{
    if(masterStudent->IsPresent(id)){
      masterStudent->search(id).PrintStudentData();
    }
    else{
      cout << "Student with ID " << id << " not found in database." << endl;
    }

  }
}
void Database::FindFaculty(int id){
  //Print faculty info given their id
  if(masterFaculty->size == 0){
    cout << "Faculty Database is empty" << endl;
  }
  else{
    if(masterFaculty->IsPresent(id)){
      masterFaculty->search(id).PrintFacultyData();
    }
    else{
      cout << "Faculty with ID " << id << " not found in database." << endl;
    }

  }
}
void Database::AddStudent(Student student){
  TreeNode<Student>* node = new TreeNode<Student>(student.studentId, student);
  masterStudent->insert(node);
  //adds a student to database
}
void Database::DeleteStudent(int id){
  //check if id exists in tree
  //if exists, deletes a student given the id
  if(masterStudent->IsPresent(id)){
    masterStudent->deleteNode(id);
  }
  else{
      cout << "Student with ID " << id << " not found in database." << endl;
  }
}
void Database::AddFaculty(Faculty faculty){
  TreeNode<Faculty>* node = new TreeNode<Faculty>(faculty.facultyId, faculty);
  masterFaculty->insert(node);

  //adds a faculty to database
}
void Database::DeleteFaculty(int id){
  //checks if id exists in tree
  //if exists, deletes a faculty given the id
  if(masterFaculty->IsPresent(id)){
    masterFaculty->deleteNode(id);
  }
  else{
      cout << "Faculty with ID " << id << " not found in database." << endl;
  }
}
void Database::ChangeAdvisor(int ids, int idf){
  //search for student of given id
  //if found, check if faculty id exists
  //if exists, add as setAdvisor
  if(masterStudent->IsPresent(ids)){
    if(masterFaculty->IsPresent(idf)){
      //code
      masterStudent->search(ids).setAdvisor(idf);
      masterFaculty->search(idf).addAdvisee(ids);
      cout << masterStudent->search(ids).name << "\'s advisor changed to " << masterFaculty->search(idf).name << endl;
    }
    else{
      cout << "Invalid faculty ID provided." << endl;
    }
  }
  else{
    cout << "Invalid student ID provided." << endl;
  }

}
void Database::RemoveAdvisee(int ids, int idf){
  //checks if faculty if exists
  //if exists, checks if provided id exists in list
  //if exists, removes
  if(masterStudent->IsPresent(ids)){
    if(masterFaculty->IsPresent(idf)){
      masterFaculty->search(idf).deleteAdvisee(ids);
    }
    else{
      cout << "Invalid faculty ID provided." << endl;
    }
  }
  else{
    cout << "Invalid student ID provided." << endl;
  }
}
void Database::RollBack(){
  //yahh it's rewind time

}
void Database::ExitProgram(){
  //exist
}


void RunProgram(){
  //will have like all the sh**
}
