#include "GenLinkedList.h"
using namespace std;
class Faculty{
public:
  int facultyId;
  string name;
  string level;
  string department;

  Faculty();
  Faculty(int id1, string name1, string level1, string department1);
  ~Faculty();

  void addAdvisee(int newId);
  void PrintFacultyData();
  void deleteAdvisee(int id);

private:

  GenLinkedList<int>* adviseeList;
};
