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
    //cout << "-----------------------------" << endl;
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
  //masterFaculty->printTree();

  if(node != NULL){//tree exists
    //recursively print through the tree
    if(node->left != NULL){
      cout << "left"<< endl;
      PrintFaculty(node->left);

    }
    node->data.PrintFacultyData();
    if(node->right != NULL){
      cout << "right" << endl;
      PrintFaculty(node->right);

    }
  }
  else{
    cout << "There are no faculty in Faculty Database." << endl;
  }
  //print all faculty and their info

}
void Database::FindStudent(){
  int id;
  while(true){
    cout << "Please provide existing student ID" << endl;
    cout << "ID: ";
    cin >> id;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
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
void Database::FindFaculty(){
  //Print faculty info given their id
  int id;
  while(true){
    cout << "Please provide faculty ID" << endl;
    cout << "ID: ";
    cin >> id;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
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
void Database::AddStudent(){
  int idS;
  string nameS, levelS, major;
  double gpa;
  while(true){
    cout << "ID: ";
    cin >> idS;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      cin.clear();
      cin.ignore(10000,'\n');
      break;
    }
  }
  //https://stackoverflow.com/questions/9469264/c-cin-only-reads-the-first-word
    cout << "Name: ";
    getline(cin, nameS);

    cout << "Level: ";

    getline(cin, levelS);
    cout << "Major: ";

    getline(cin, major);
    cout << "GPA: ";
    cin >> gpa;

  TreeNode<Student>* studentnode = new TreeNode<Student>(idS, Student(idS, nameS, levelS, major, gpa));
  masterStudent->insert(studentnode);
  cout << "Student added." << endl;
  //delete studentnode;

  cin.clear();
  cin.ignore(10000,'\n');
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

void Database::AddFaculty(){
  int idF;
  string nameF, levelF, department;
  while(true){
    cout << "ID: ";
    cin >> idF;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      cin.clear();
      cin.ignore(10000,'\n');
      break;
    }
  }
  cout << "Name: ";
  getline(cin, nameF);

  cout << "Level: ";

  getline(cin, levelF);
  cout << "Department: ";

  getline(cin, department);


  TreeNode<Faculty>* facultynode = new TreeNode<Faculty>(idF, Faculty(idF, nameF, levelF, department));
  masterFaculty->insert(facultynode);
  //delete facultynode;


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

void Database::FindAdvisor(int ids){
  //check if student id exists
  //if exists, return advisor info
  if(masterStudent->IsPresent(ids)){
    if(masterStudent->search(ids).advisorId != -1){
      masterFaculty->search(masterStudent->search(ids).advisorId).PrintFacultyData();

    }
  }
}
void Database::FindAdvisees(int idf){
  Faculty fac;
  //check if teacher id exsits
  //if so, return all them
  if(masterFaculty->IsPresent(idf)){
    fac = masterFaculty->search(idf);
    if(fac.CheckAdvisees()){
      cout << "Advisees: " << fac.numOfAdvisees << endl;
      ListNode<int>* current = fac.adviseeList->front;
      for(int i = 0; i < fac.numOfAdvisees; ++i){
        cout << "   " << i << ") ";
        masterStudent->search(current->data).PrintStudentData();
      }

    }

      //masterStudent->search(masterFaculty->search(idf).advisorId).PrintFacultyData();
      //note to self, add function in faculty.cpp to print all advisees

  }

}

void Database::RollBack(){
  //yahh it's rewind time

}
void Database::ExitProgram(){
  //exist
  //I MEAN EXIT WTF
}

void Database::PrintMenu(){
  cout << "What will it be?\n" << endl;
  cout << "1 - Print all students" << endl;
  cout << "2 - Print all faculty members" << endl;
  cout << "3 - Add a student" << endl;
  cout << "4 - Add a faculty member" << endl;
}
void Database::RunProgram(){
  //will have like all the sh**
  //check for studentTable and facultyTable
  //read in files if existing
  int idS, idF;
  int choice;
  string nameS, levelS;
  string nameF, levelF;
  string major;
  string department;
  double gpa;


  while(choice != 14){
    PrintMenu();
    while(true){
      cin >> choice;
      if(cin.fail()){
        cout << "Please only put int value." << endl;
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else{
        break;
      }
    }
    switch(choice){
      case 1:
        PrintStudents(masterStudent->root);
      break;
      case 2:
        PrintFaculty(masterFaculty->root);
      break;
      case 3:
        cout << "---Adding Student---\nPlease provide following info." << endl;
        AddStudent();
      break;
      case 4:
        cout << "---Adding Faculty---\nPlease provide following info." << endl;
        AddFaculty();

      break;
      case 5:

      break;
      case 6:
      break;
      case 7:
      break;
      case 8:
      break;
      case 9:
      break;
      case 10:
      break;
      case 11:
      break;
      case 12:
      break;
      case 13:
      break;
      default:
      break;

    }



  }
}
/** NUMBER ERROR HANDLER reference
while(true){
  cout << "ID: ";
  cin >> id;
  if(cin.fail()){
    cout << "Please only put int value." << endl;
    cin.clear();
    cin.ignore(10000,'\n');
  }
  else{
    break;
  }
}
**/
