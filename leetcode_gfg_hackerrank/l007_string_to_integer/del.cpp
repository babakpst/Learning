// CPP code to demonstrate std::string::at

#include <iostream>
using namespace std;

// Driver code
int main()
{
  string str("Geeks ForGeeks");
  cout << str.at(5) << endl;
  // string str2 = str.at(5);
  const char* space = " ";
  char str2 = str[5];
  // if (str2 == *space)
  if (str2 == ' ')
    cout << " equal \n";
  else
    cout << " not equal \n";
  return 0;
}
