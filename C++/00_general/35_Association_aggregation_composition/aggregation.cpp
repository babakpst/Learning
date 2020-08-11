
// Babak Poursartip
// The code is borrowed from
// https://stackoverflow.com/questions/885937/what-is-the-difference-between-association-aggregation-and-composition

#include <iostream>
#include <string>
using namespace std;

/********************** Teacher Class ******************/
class Teacher {
private:
  string m_strName;

public:
  Teacher(string strName);
  ~Teacher(void);
  string GetName();
};
Teacher::Teacher(string strName) : m_strName(strName) {
  cout << " Teacher :: Constructor --- Teacher Name :: " << m_strName << endl;
}
Teacher::~Teacher(void) {
  cout << " Teacher :: Destructor --- Teacher Name :: " << m_strName << endl;
}
string Teacher::GetName() { return m_strName; }

/********************** Department Class ******************/
class Department {
private:
  Teacher *m_pcTeacher;
  Teacher &m_refTeacher;

public:
  Department(Teacher *pcTeacher, Teacher &objTeacher);
  ~Department(void);
};
Department::Department(Teacher *pcTeacher, Teacher &objTeacher)
    : m_pcTeacher(pcTeacher), m_refTeacher(objTeacher) {
  cout << " Department :: Constructor " << endl;
}
Department::~Department(void) { cout << " Department :: Destructor " << endl; }

/********************** Main Function ******************/
int main() {
  freopen("aggregation.Log", "w", stdout);
  cout << "--------------- Start Of Program --------------------" << endl;
  {
    // Create a teacher outside the scope of the Department
    Teacher objTeacher("Reference Teacher");
    Teacher *pTeacher = new Teacher("Pointer Teacher"); // create a teacher
    {
      cout << "------------- Inside Block ------------------" << endl;
      // Create a department and use the constructor parameter to pass the
      // teacher to it.
      Department cDept(pTeacher, objTeacher);
      // Department Teacher Figure 2 : Aggregation
    } // cDept goes out of scope here and is destroyed
    cout << "------------- Out of Block ------------------" << endl;
    // pTeacher still exists here because cDept did not destroy it
    delete pTeacher;
  }
  cout << "--------------- End Of Program --------------------" << endl;
  fclose(stdout);
}