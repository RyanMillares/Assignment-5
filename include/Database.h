#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;
class Database{
private:
  BST<Student>* StudentTree;
  BST<Faculty>* FacultyTree;
public:
  Database();
  ~Database();


};
