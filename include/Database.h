#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;
class Database{
private:
  BST<Student>* masterStudent;
  BST<Faculty>* masterFaculty;
public:
  Database();
  ~Database();

  void ReadInStudents();
  void ReadInFaculty();

  void PrintStudents(TreeNode<Student>* node); //done
  void PrintFaculty(TreeNode<Faculty>* node); //done
  void FindStudent(int id);
  void FindFaculty(int id);
  void FindAdvisor(int id);
  void FindAdvisees(int id);
  void AddStudent(Student student);
  void DeleteStudent(int id);
  void AddFaculty(Faculty faculty);
  void DeleteFaculty(int id);
  void ChangeAdvisor(int ids, int idf);
  void RemoveAdvisee(int ids, int idf);
  void RollBack();
  void ExitProgram();

  void RunProgram();


};
