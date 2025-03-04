
// Babak Poursartip
// 10/13/2020

// reverse the words in a string, in place
#include <algorithm>  // for reverse func
#include <iostream>

using std::cout;
using std::endl;
using std::reverse;
using std::string;

void reverseWords(string &s)
{
  // step 1: reverse each word, in place
  int startOfWord = 0;
  for (int endOfWord = 0; endOfWord < s.length(); ++endOfWord)
  {
    if (s[endOfWord] == ' ')
    {
      reverse(s.begin() + startOfWord, s.begin() + endOfWord);
      startOfWord = endOfWord + 1;
    }
  }
  // reverse the last word
  reverse(s.begin() + startOfWord, s.end());

  // step 2: reverse the entire string
  reverse(s.begin(), s.end());
}

int main()
{
  // string s = "Babak is great and awesome. Yes, it is working";
  string s{"      hello    world      "};

  cout << s << endl;
  reverseWords(s);
  cout << s << endl;
}
