#include "BST.h"
#include "Student.h"
#include "Faculty.h"


using namespace std;
class Database{
public:
  BST<Student>* masterStudent;
  BST<Faculty>* masterFaculty;
  GenLinkedList<BST<Student>*>* masterStudentHistory;
  GenLinkedList<BST<Faculty>*>* masterFacultyHistory;
//i give up making stuff private honestly
  Database();
  ~Database();

  void ReadInStudents();
  void ReadInFaculty();
  void SaveTrees(BST<Student>* students, BST<Faculty>* faculties);
  void PrintStudents(TreeNode<Student>* node); //done, tested
  void PrintFaculty(TreeNode<Faculty>* node); //done, tested
  void FindStudent();//done, tested
  void FindFaculty();//done, tested
  void FindAdvisor();
  void FindAdvisees();
  void AddStudent(); //done, tested
  void AddFaculty(); //done, tested
  void DeleteStudent(); //done, not tested
  void DeleteFaculty(); //done, not tested
  void ChangeAdvisor();//done, not tested
  void RemoveAdvisee(); //done, not tested
  void RollBack(); //what the actual frick is this
  void ExitProgram(); //

  void RunProgram();
  void PrintMenu();

  //void NumberCheck()


};
