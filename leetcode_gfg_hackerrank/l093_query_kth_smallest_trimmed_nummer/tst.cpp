#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  string st = "987654310";
  for_each(st.rbegin(), st.rbegin() + 3, [](auto x) { cout << x << " "; });
  cout << endl;

  return 0;
}
