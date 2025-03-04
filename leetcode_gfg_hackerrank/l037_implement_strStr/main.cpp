
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
 public:
  int strStr(string haystack, string needle)
  {
    if (needle.empty()) return 0;

    int nsize = needle.size();
    int hsize = haystack.size();
    for (int i = 0; i < hsize; i++)
    {
      int j = 0, k = i;
      bool ret = true;
      while (j < nsize && k < hsize && needle[j] == haystack[k])
      {
        j++, k++;
      }
      if (j == nsize) return i;
    }
    return -1;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
  // std::string haystack = "hello",needle = "ll";
  // std::string haystack = "aaaaa", needle = "bba";
  // std::string haystack = "aaaaabbaaaa", needle = "bba";
  // std::string haystack = "aaaaabbaaaa", needle = "";
  std::string haystack = "abc", needle = "c";
  Solution t;
  int out = t.strStr(haystack, needle);
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
