#include <bits/stdc++.h>

#include <stack>

using namespace std;

// Add any helper functions you may need here

bool isBalanced(string s)
{
  stack<char> st;
  for (auto x : s)
  {
    if (x == '{' || x == '(' || x == '[')
    {
      st.push(x);
    }
    else
    {
      auto tmp = st.top();
      char tmp2;
      if (tmp == '(')
        tmp2 = ')';
      else if (tmp == '[')
        tmp2 = ']';
      else if (tmp == '{')
        tmp2 = '}';

      if (x == tmp2)
        st.pop();
      else
        return false;
    }
  }
  return st.empty();
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) { cout << "[\"" << str << "\"]"; }

int test_case_number = 1;

void check(bool expected, bool output)
{
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result)
  {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else
  {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl;
  }
  test_case_number++;
}

int main()
{
  string s_1 = "{[(])}";
  bool expected_1 = false;
  bool output_1 = isBalanced(s_1);
  check(expected_1, output_1);

  string s_2 = "{{[[(())]]}}";
  bool expected_2 = true;
  bool output_2 = isBalanced(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
}
