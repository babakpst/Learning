
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
      int len = s.length();
      if (s.empty() || len == 0|| len == 1 || numRows == 1)
        return s;
      std::vector<std::string> temp(min(numRows,len),"");

      int pos = 0;
      int col = 0;
      int row = 0;
      while (pos<s.length())
      {
        std::cout << " col: " << col << " " << col%(numRows-1) << std::endl;
        int rem = col%(numRows-1);
        if (!(rem)) // major col
        {
          //std::cout << " major \n";
          temp[row] +=s.at(pos);
          pos++;
          row++;
        }
        else
        {
          //std::cout << " minor \n";
          if (row == numRows-1-rem)
          {
            temp[row] +=s.at(pos);
            pos++;
            row++;
          }
          else
          {
            //temp[row] +=" ";
            row++;
          }          
        }

        if (row == numRows)
        {
          col++;
          row = 0;      
        }
      //for_each(temp.begin(),temp.end(),[](auto x){std::cout << x << std::endl;});
      //std::cout << "====\n";
      }
      //std::cout << " final\n";
      //for_each(temp.begin(),temp.end(),[](auto x){std::cout << x << std::endl;});

      std::string ret;
        for (int row = 0; row< temp.size(); row++)
          ret +=temp[row];
          //ret +=temp[row]+"\n";
      return ret;  
    }
};

class Solution0 {
public:
    string convert(string s, int numRows) {
      int len = s.length();
      if (s.empty() || len == 0|| len == 1)
        return s;
      std::vector<std::string> temp(min(numRows,len),"");

      int pos = 0;
      int col = 0;
      int row = 0;
      while (pos<s.length())
      {
        //std::cout << " col: " << col << " " << col%(numRows-1) << std::endl;
        int rem = col%(numRows-1);
        if (!(rem)) // major col
        {
          //std::cout << " major \n";
          temp[row] +=s.at(pos);
          pos++;
          row++;
        }
        else
        {
          //std::cout << " minor \n";
          if (row == numRows-1-rem)
          {
            temp[row] +=s.at(pos);
            pos++;
            row++;
          }
          else
          {
            temp[row] +=" ";
            row++;
          }          
        }

        if (row == numRows)
        {
          col++;
          row = 0;      
        }
      //for_each(temp.begin(),temp.end(),[](auto x){std::cout << x << std::endl;});
      //std::cout << "====\n";
      }
      //std::cout << " final\n";
      //for_each(temp.begin(),temp.end(),[](auto x){std::cout << x << std::endl;});

      std::string ret;
        for (int row = 0; row< temp.size(); row++)
          ret +=temp[row]+"\n";
      return ret;  
    }
};

int main(int argc, char* argv[])
{
std::cout << " starts here ... \n";


Solution t;
std::cout << " answer: \n";
string out = t.convert(argv[1],atoi(argv[2]));
std::cout <<   out << std::endl;
std::cout <<   out.length() << std::endl;


//std::string m;
//std::cout << t.convert(m,5) << std::endl;

std::cout << " ends \n";
return 0;
}
