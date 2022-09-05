
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class Solution0 {
public:
    string reverseWords(string s) {
 
      int size = s.size();
      bool check = true;
     
      // removing extra spaces
      for(int i = 0; i<size; i++)
      {
        int j = i;
        while(s[j] ==' ' && j<size) 
        {
          j++;
        }
        int dist = j-i;
        if (i == 0 || dist>1){
        if (!(i==0||j==size) && dist>1) {dist--;}
        for (;j<size; j++)
        {
          s[j-dist] = s[j];          
        }
        size-=dist;
        }
      }
      
      for(int i = 0; i<size/2; i++)
      {
        swap(s[i], s[size-i-1]);
      }

      int j = 0;
      for(int i = 0; i<size; i++)
      {
        if (s[i]==' ' || i == size-1)
        {
          int k = (i == size-1)?i:i-1;
          int mm = ((i+j+1)/2);
          for (;j<mm; j++,k--){
            swap(s[j],s[k]);
          }

          j = i+1;
        }
      }
      
      return s.substr(0,size);
    }
};

class Solution {
public:
    string reverseWords(string s) {
      // reverse the string
      reverse(begin(s), end(s));
      cout << s << endl;

      int size = s.size();
      int idx = 0;

      for (int start = 0; start < size; ++start) {
        cout << " start: " << start << endl;
        if (s[start] != ' ') {
          // go to the beginning of the word
          if (idx != 0) s[idx++] = ' ';

          // go to the end of the word
          int end = start;
          while (end < size && s[end] != ' ') s[idx++] = s[end++];

          // reverse the word
          reverse(s.begin() + idx - (end - start), s.begin() + idx);

          // move to the next word
          start = end;
        }
        cout << s << endl;
      }
      s.erase(s.begin() + idx, s.end());

      return s;
    }
}; 

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // std::string s{"the sky is blue"};
  // std::string s{"th"};
  std::string s{"        hello    world      "};
  // std::string s{"Je suis tres content"};

  Solution t;
  string out = t.reverseWords(s);
  cout << " answer: -" << out << "-" << endl;
  std::cout << " done \n";
  return 0;
}


