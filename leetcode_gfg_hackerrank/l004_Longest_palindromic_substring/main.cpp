/*
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgxkzdbcjsjjovnhpnbkurxqfupiprpbiwqdnwaqvjbqoaqzkqgdxkfczdkznqxvupdmnyiidqpnbvgjraszbvvztpapxmomnghfaywkzlrupvjpcvascgvstqmvuveiiixjmdofdwyvhgkydrnfuojhzulhobyhtsxmcovwmamjwljioevhafdlpjpmqstguqhrhvsdvinphejfbdvrvabthpyyphyqharjvzriosrdnwmaxtgriivdqlmugtagvsoylqfwhjpmjxcysfujdvcqovxabjdbvyvembfpahvyoybdhweikcgnzrdqlzusgoobysfmlzifwjzlazuepimhbgkrfimmemhayxeqxynewcnynmgyjcwrpqnayvxoebgyjusppfpsfeonfwnbsdonucaipoafavmlrrlplnnbsaghbawooabsjndqnvruuwvllpvvhuepmqtprgktnwxmflmmbifbbsfthbeafseqrgwnwjxkkcqgbucwusjdipxuekanzwimuizqynaxrvicyzjhulqjshtsqswehnozehmbsdmacciflcgsrlyhjukpvosptmsjfteoimtewkrivdllqiotvtrubgkfcacvgqzxjmhmmqlikrtfrurltgtcreafcgisjpvasiwmhcofqkcteudgjoqqmtucnwcocsoiqtfuoazxdayricnmwcg

*/

#include <iostream>

using namespace std;

// dynamic programming: check around the center
class Solution
{
 public:
  string longestPalindrome(string s)
  {
    int len = s.length();
    if (len == 0 or len == 1) return s;

    int maxLength = 0;
    int start = 0;
    for (int center = 0; center < s.length(); center++)
    {
      int len1 = findPalindromeAroundCenter(s, center, center);      // odd string size, center is a char
      int len2 = findPalindromeAroundCenter(s, center, center + 1);  // even string size, center is btw two chars
      int length = len1 > len2 ? len1 : len2;
      if (length > maxLength)
      {
        maxLength = length;
        start = center - (length - 1) / 2;
        // std::cout << start << std::endl;
      }
    }

    return s.substr(start, maxLength);
  };

  int findPalindromeAroundCenter(string& s, int left, int right)
  {
    while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) left--, right++;
    return right - left - 1;
  }
};

// brute-force
class Solution0
{
 public:
  string longestPalindrome(string s)
  {
    int len = s.length();
    if (len == 0 or len == 1) return s;

    string ret = "";
    for (int stlen = len; stlen >= 1; stlen--)
    {
      int pos = 0;
      // std::cout << " here " << pos+stlen << len << std::endl;
      while (pos + stlen <= len)
      {
        // std::cout << s << "  substr " << pos << " " << pos+stlen << " " <<s.substr(pos,stlen) << std::endl;
        string test = s.substr(pos, stlen);
        // std::cout << " pos: " << pos << " stlen: " << stlen << " test: " << test << std::endl;
        if (isPalindromic(test))
        {
          ret = test;
          break;
        }
        pos++;
        // std::cout << " test: " << test << " ret: "<< ret  << std::endl;
      }
      if (ret != "") break;
      // std::cout << " === moving to the next length " << stlen  << std::endl;
    }

    return ret;
  };

  bool isPalindromic(string test)
  {
    bool ret = true;
    int len = test.length();
    // std::cout << " isPalindromic: " << test << std::endl;
    for (int i = 0; i < len / 2; i++)
    {
      // std::cout << "      pal i: " << i << " test: " << test << std::endl;
      if (test.at(i) != test.at(len - i - 1))
      {
        ret = false;
        break;
      }
    }

    return ret;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts here ... \n";

  Solution0 t;
  std::cout << t.longestPalindrome(argv[1]) << std::endl;

  Solution t2;
  std::cout << t2.longestPalindrome(argv[1]) << std::endl;

  std::cout << " ends \n";
  return 0;
}
