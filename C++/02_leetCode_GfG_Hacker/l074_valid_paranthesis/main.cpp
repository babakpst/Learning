
// babak poursartip
// Oct 1, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
      
      stack<char> mys;

      for (int i = 0; i<s.size(); i++)
      {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{')
          mys.push(s[i]);
        else if ( s[i]==')' )
        {
          if ( !mys.empty() && mys.top()=='(')
            mys.pop();
          else
            return false;
        }
        else if ( s[i]==']' )
        {
          if ( !mys.empty() && mys.top()=='[')
            mys.pop();
          else
            return false;
        }
        else if ( s[i]=='}' )
        {
          if ( !mys.empty() && mys.top()=='{')
            mys.pop();
          else
            return false;
        }
      }
      return mys.empty()? true:false;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

 
 
  Solution t;

  bool out = t.isValid(argv[1]);
  cout << " answer: " << boolalpha << out << endl;
  
  std::cout << " done \n";
  return 0;
}