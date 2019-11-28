#include "Database.h"
#include <iostream>
#include <fstream>
using namespace std;
Database::Database(){
  masterStudent = new BST<Student>();
  masterFaculty = new BST<Faculty>();
  masterFacultyHistory = new GenLinkedList<BST<Faculty>*>();
  masterStudentHistory = new GenLinkedList<BST<Student>*>();

}
Database::~Database(){
  delete masterStudent;
  delete masterFaculty;
  delete masterStudentHistory;
  delete masterFacultyHistory;
}

void Database::ReadInStudents(){
  ifstream StudentFile;
  //search for file "studentTable"
  //if exists, read in data
}
void Database::ReadInFaculty(){
  //search for file "facultyTable"
  //if exists, read in data
}
void Database::SaveTrees(BST<Student>* students, BST<Faculty>* faculties){
  masterStudentHistory->insertFront(students);
  cout << "hi" << endl;
  if(masterStudentHistory->getSize() > 5){
    masterStudentHistory->removeBack();
  }
  /** dont we all love pointerssss
  if(masterStudentHistory->front->data->root != NULL){
    cout << masterStudentHistory->front->data->root->data->studentId<< endl;
  }
  **/
  masterFacultyHistory->insertFront(faculties);
  if(masterFacultyHistory->getSize() > 5){
    masterFacultyHistory->removeBack();
  }
}

//must take in root to work
void Database::PrintStudents(TreeNode<Student>* node){
  //TreeNode<Student>* node = masterStudent->root;
  if(node != NULL){//tree exists
    //recursively print through the tree
    if(node->left != NULL){
      PrintStudents(node->left);
    }
    node->data->PrintStudentData();
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
      PrintFaculty(node->left);

    }
    node->data->PrintFacultyData();
    if(node->right != NULL){
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
      masterStudent->search(id)->PrintStudentData();
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
      masterFaculty->search(id)->PrintFacultyData();
    }
    else{
      cout << "Faculty with ID " << id << " not found in database." << endl;
    }

  }
}
void Database::AddStudent(){

  int idS, idF;
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
      if(idS < 0){
        cout << "Please only provide positive int for ID." << endl;
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else{
        cin.clear();
        cin.ignore(10000,'\n');
        break;
      }


    }
  }
  //https://stackoverflow.com/questions/9469264/c-cin-only-reads-the-first-word
    cout << "Name: ";
    getline(cin, nameS);

    cout << "Level: ";

    getline(cin, levelS);
    cout << "Major: ";

    getline(cin, major);
    while(true){
      cout << "GPA: ";
      cin >> gpa;
      if(cin.fail()){
        cout << "Please only put int value." << endl;
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else{
        if(idS < 0){
          cout << "Please only provide positive value for GPA." << endl;
          cin.clear();
          cin.ignore(10000,'\n');
        }
        else{
          cin.clear();
          cin.ignore(10000,'\n');
          break;
        }
      }
    }
      cout << "If no assigned advisor, put 0" << endl;
      cout << "Advisor\'s ID: ";
      cin >> idF;
      if(!masterFaculty->IsPresent(idF)){
        cout << "No faculty has that ID, student added without advisor." << endl;
        idF = 0;
      }

    Student* studentinfo = new Student(idS, nameS, levelS, major, gpa, idF);
  TreeNode<Student>* studentnode = new TreeNode<Student>(idS, studentinfo);
  masterStudent->insert(studentnode);
  if(masterFaculty->IsPresent(idF)){
    masterFaculty->search(idF)->adviseeList->insertFront(idF);
  }
  cout << "Student added." << endl;
  //delete studentnode;

  cin.clear();
  cin.ignore(10000,'\n');
  //adds a student to database
}

void Database::DeleteStudent(){

  //check if id exists in tree
  //if exists, deletes a student given the id
  int id;
  while(true){
    cout << "Please provide ID of student to be deleted" << endl;
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
  if(masterStudent->IsPresent(id)){
    if(masterStudent->search(id)->hasAdvisor){
      masterFaculty->search(masterStudent->search(id)->advisorId)->deleteAdvisee(id);
    }
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

  Faculty* facinfo = new Faculty(idF, nameF, levelF, department);
  TreeNode<Faculty>* facultynode = new TreeNode<Faculty>(idF, facinfo);
  masterFaculty->insert(facultynode);
  //delete facultynode;


  //adds a faculty to database
}

void Database::DeleteFaculty(){

  //checks if id exists in tree
  //if exists, deletes a faculty given the id
  int id;
  while(true){
    cout << "Please provide ID of faculty to be deleted" << endl;
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
  if(masterFaculty->IsPresent(id)){
    for(int i = 0; i < masterFaculty->search(id)->numOfAdvisees; ++i){
      masterStudent->search(masterFaculty->search(id)->adviseeList->removeFront())->ResetAdvisor();
    }

    masterFaculty->deleteNode(id);
  }
  else{
      cout << "Faculty with ID " << id << " not found in database." << endl;
  }
}
void Database::ChangeAdvisor(){

  int ids, idf;
  while(true){
    cout << "Please provide student ID" << endl;
    cout << "ID: ";
    cin >> ids;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
    while(true){
      cout << "Please provide faculty ID of new advisor" << endl;
      cout << "ID: ";
      cin >> idf;
      if(cin.fail()){
        cout << "Please only put int value." << endl;
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else{
        break;
      }
    }
  //search for student of given id
  //if found, check if faculty id exists
  //if exists, add as setAdvisor
  if(masterStudent->IsPresent(ids)){
    if(masterFaculty->IsPresent(idf)){
      //code
      masterStudent->search(ids)->setAdvisor(idf);
      masterFaculty->search(idf)->addAdvisee(ids);
      cout << masterStudent->search(ids)->name << "\'s advisor changed to " << masterFaculty->search(idf)->name << endl;
    }
    else{
      cout << "Invalid faculty ID provided." << endl;
    }
  }
  else{
    cout << "Invalid student ID provided." << endl;
  }

}
void Database::RemoveAdvisee(){

  //checks if faculty if exists
  //if exists, checks if provided id exists in list
  //if exists, removes
  int ids, idf;
  while(true){
    cout << "Faculty ID: ";
    cin >> idf;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
  while(true){
    cout << "Advisee student ID: ";
    cin >> ids;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
  if(masterStudent->IsPresent(ids)){
    if(masterFaculty->IsPresent(idf)){
      masterFaculty->search(idf)->deleteAdvisee(ids);
      masterStudent->search(ids)->ResetAdvisor();
    }
    else{
      cout << "Invalid faculty ID provided." << endl;
    }
  }
  else{
    cout << "Invalid student ID provided." << endl;
  }
}

void Database::FindAdvisor(){
  //check if student id exists
  //if exists, return advisor info
  int ids;
  while(true){
    cout << "ID: ";
    cin >> ids;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
  if(masterStudent->IsPresent(ids)){
    if(masterStudent->search(ids)->advisorId != 0){
      masterFaculty->search(masterStudent->search(ids)->advisorId)->PrintFacultyData();

    }
    else{
      cout << "This student has no assigned advisor."<< endl;
    }
  }
  else{
    cout << "No student exists with the provided student ID." << endl;
  }

}
void Database::FindAdvisees(){
  int idf;
  while(true){
    cout << "Faculty ID: ";
    cin >> idf;
    if(cin.fail()){
      cout << "Please only put int value." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
  Faculty *fac;
  //check if teacher id exsits
  //if so, return all them
  if(masterFaculty->IsPresent(idf)){
    fac = masterFaculty->search(idf);
    if(fac->CheckAdvisees()){
      cout << "Advisees: " << fac->numOfAdvisees << endl;
      ListNode<int>* current = fac->adviseeList->front;
      for(int i = 0; i < fac->numOfAdvisees; ++i){
        cout << "   " << i + 1 << ") ";
        masterStudent->search(current->data)->PrintStudentData();
      }
    }
      //masterStudent->search(masterFaculty->search(idf).advisorId).PrintFacultyData();
      //note to self, add function in faculty.cpp to print all advisees

  }

}

void Database::RollBack(){
  //yahh it's rewind time
  cout << "roll" << endl;
  cout << "There were " << masterStudentHistory->front->data->size << " students" << endl;
  if(masterFacultyHistory->getSize() > 0){
    masterFaculty = masterFacultyHistory->removeFront();
    masterFaculty = masterFacultyHistory->removeFront();

  }
  if(masterStudentHistory->getSize() > 0){
    masterStudent = masterStudentHistory->removeFront();
    masterStudent = masterStudentHistory->removeFront();

  }

}
void Database::ExitProgram(){
  //exist
  //I MEAN EXIT WTF
  cout << "Exiting database, deleting all your data." << endl;
  exit(0);
}

void Database::PrintMenu(){
  cout << "What will it be?\n" << endl;
  cout << "1 - Print all students" << endl;
  cout << "2 - Print all faculty members" << endl;
  cout << "3 - Add a student" << endl;
  cout << "4 - Add a faculty member" << endl;
  cout << "5 - Retrieve student info" << endl;
  cout << "6 - Retrieve faculty info" << endl;
  cout << "7 - Delete a student" << endl;
  cout << "8 - Delete a faculty member" << endl;
  cout << "9 - Change a student\'s advisor" << endl;
  cout << "10 - List ID and info of student\'s advisor" << endl;
  cout << "11 - List info of all a faculty\'s advisees" << endl;
  cout << "12 - Remove an advisee from a faculty\'s advisee list" << endl;
  cout << "13 - Rollback" << endl;
  cout << "14 - I accidentally rollbacked" << endl;
  cout << "15 - Exit" << endl;

}
void Database::RunProgram(){
  //will have like all the sh**
  //check for studentTable and facultyTable
  //read in files if existing

  int choice;

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
        SaveTrees(masterStudent, masterFaculty);
        cout << "---Adding Student---\nPlease provide following info." << endl;
        AddStudent();
      break;
      case 4:
        SaveTrees(masterStudent, masterFaculty);
        cout << "---Adding Faculty---\nPlease provide following info." << endl;
        AddFaculty();
      break;
      case 5:
        cout << "---Finding Student---\nPlease provide following info." << endl;
        FindStudent();
      break;
      case 6:
        cout << "---Finding Faculty---\nPlease provide following info." << endl;
        FindFaculty();
      break;
      case 7:
        SaveTrees(masterStudent, masterFaculty);
        cout << "---Deleting Student---\nPlease provide following info." << endl;
        DeleteStudent();
      break;
      case 8:
        SaveTrees(masterStudent, masterFaculty);
        cout << "---Deleting Faculty---\nPlease provide following info." << endl;
        DeleteFaculty();
      break;
      case 9:
        SaveTrees(masterStudent, masterFaculty);
        cout << "---Changing advisor---\nPlease provide following info" << endl;
        ChangeAdvisor();
      break;
      case 10:
        cout << "---Listing Advisor Info---\nPlease provide following info." << endl;
        FindAdvisor();
      break;
      case 11:
        cout << "---Listing all Advisee Info---\nPlease provide following info." << endl;
        FindAdvisees();
      break;
      case 12:
        SaveTrees(masterStudent, masterFaculty);
        cout << "---Removing an Advisee---\nPlease provide following info." << endl;
        RemoveAdvisee();
      break;
      case 13:
        cout << "---Rollback---" << endl;
        RollBack();
      break;
      case 14:
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
