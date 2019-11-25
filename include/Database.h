#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;
class Database{
public:
  BST<Student>* masterStudent;
  BST<Faculty>* masterFaculty;
//i give up making stuff private honestly
  Database();
  ~Database();

  void ReadInStudents();
  void ReadInFaculty();

  void PrintStudents(TreeNode<Student>* node); //done, tested
  void PrintFaculty(TreeNode<Faculty>* node); //done, tested
  void FindStudent(int id);//done, not tested
  void FindFaculty(int id);//done, not tested
  void FindAdvisor(int ids);
  void FindAdvisees(int idf);
  void AddStudent(Student student); //done, tested
  void DeleteStudent(int id); //done, not tested
  void AddFaculty(Faculty faculty); //done, tested
  void DeleteFaculty(int id); //done, not tested
  void ChangeAdvisor(int ids, int idf);//done, not tested
  void RemoveAdvisee(int ids, int idf); //done, not tested
  void RollBack(); //what the actual frick is this
  void ExitProgram(); //

  void RunProgram();

  //void NumberCheck()


};
