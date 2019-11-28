#include "GenLinkedList.h"
using namespace std;
class Faculty{
public:
  int facultyId;
  int numOfAdvisees;
  string name;
  string level;
  string department;

  Faculty();
  Faculty(int id1, string name1, string level1, string department1);
  ~Faculty();

  void addAdvisee(int newId);
  void PrintFacultyData();
  bool CheckAdvisees();
  void deleteAdvisee(int id);
  void ListAdviseeIds();

  GenLinkedList<int>* adviseeList;
};
bool operator> (Faculty& f1, Faculty& f2);
bool operator< (Faculty& f1, Faculty& f2);
bool operator== (Faculty& f1, Faculty& f2);
bool operator!= (Faculty& f1, Faculty& f2);
