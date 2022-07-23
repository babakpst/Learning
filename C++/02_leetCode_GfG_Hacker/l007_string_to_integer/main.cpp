// Jul 23, 2022

/*
String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 

Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

*/


#include <iostream>
#include <climits>

using namespace std;


class Solution {
public:
  int myAtoi(string s) {
    
    //cout << " string: '" << s << "'\n";
    if(s.length() == 0 || s.empty())
      return 0;

    int sign = 1;
    int ret = 0;
    int temp = -1;
    bool start = false;
    while(!s.empty())
    {
      //cout << " string: '" << s << "' return: " << ret << endl;      
      if (s[0]==' ')
      {
        if (start)
          break;
        s.erase(0,1);
        continue;
      }
      if (s[0]=='+' || s[0]=='-')
      {
        if (start)
          break;
        sign = s[0]=='-'? 1:-1;
        start = true;
        s.erase(0,1);
        continue;
      }

      /*
      if (s[0]=='0')
        temp = 0;        
      if (s[0]=='1')
        temp = 1;
      else if (s[0]=='2')
        temp = 2;
      else if (s[0]=='3')
        temp = 3;
      else if (s[0]=='4')
        temp = 4;
      else if (s[0]=='5')
        temp = 5;
      else if (s[0]=='6')
        temp = 6;
      else if (s[0]=='7')
        temp = 7;
      else if (s[0]=='8')
        temp = 8;
      else if (s[0]=='9')
        temp = 9;
      */
      //if (temp >= 0 )

      if (isdigit(s[0]) )
      {
        temp = s[0]-'0';
        start = true;
        temp *=sign;
        int mlimit = sign == 1? INT_MAX:INT_MIN;
        int limit = (mlimit-temp)/10;
        if (sign==1? ret<=limit:ret>=limit)
          ret = ret*10 + temp;
        else
          ret = mlimit;
        s.erase(0,1);
        temp =-1;
      }
      else 
        break;
    }    

    return ret;
  }
};




int main(int argc, char* argv[])
{

cout << " starts here ... \n";
cout << INT_MAX <<" " << INT_MIN << endl;

Solution t;
int out = t.myAtoi(argv[1]);
cout << " output: " << out  << endl;

std::cout << " done. \n";
return 0;
}







































































