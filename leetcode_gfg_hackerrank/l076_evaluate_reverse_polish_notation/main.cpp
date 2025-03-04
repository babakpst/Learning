
// babak poursartip
// Oct 6, 2022

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

// #include <cstdlib>
// #include <string>

using namespace std;

class Solution
{
 public:
  int evalRPN(vector<string>& tokens)
  {
    stack<long long int> mys;
    for (int i = 0; i < tokens.size(); i++)
    {
      // cout << tokens[i] << endl;
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
      {
        long long int i1 = mys.top();
        mys.pop();
        long long int i2 = mys.top();
        mys.pop();
        long long int res;
        if (tokens[i] == "+")
          res = (i2 + i1);
        else if (tokens[i] == "-")
          res = (i2 - i1);
        else if (tokens[i] == "*")
          res = (i2 * i1);
        else if (tokens[i] == "/")
          res = (i2 / i1);
        cout << res << endl;
        mys.push(res);
      }
      else
        mys.push(stoi(tokens[i]));
    }
    return mys.top();
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  vector<string> tokens{"-128", "-128", "*", "-128", "*", "-128", "*", "8", "*", "-1", "*"};

  // vector<string> tokens {"10"};

  Solution t;

  int out = t.evalRPN(tokens);
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
