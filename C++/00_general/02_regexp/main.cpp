#include <iostream>
#include <regex>

/*
To see different placeholders for regex:
https://www.softwaretestinghelp.com/regex-in-cpp/#:~:text=Regular%20Expression%20%28regex%29%20In%20C%2B%2B%201%20Range%20Specifications,matches%20an%20MS-DOS%20filename%20as%20shown%20below.%20


For example, we can specify a range of lowercase letters from a to z as follows:

[a-z]

This will match exactly one lowercase character.

The following criteria,

[A-Za-z0-9]

The above expression specifies the range containing one single uppercase character, one lowercase
character and a digit from 0 to 9.

The brackets ([]) in the above expressions have a special meaning i.e. they are used to specify the
range. If you want to include a bracket as part of an expression, then you will need to escape it.

So the following expression,

[\[0-9]

The above expression indicates an opening bracket and a digit in the range 0 to 9 as a regex.

But note that as we are programming in C++, we need to use the C++ specific escape sequence as
follows:

[\\[0-9]

An expression modifier can be “+” that suggests matching the occurrence of a pattern one or more
times or it can be “*” that suggests matching the occurrence of a pattern zero or more times.

[a-z]+ matches the strings like a, aaa, abcd, softwaretestinghelp, etc. Note that it will never
match a blank string.

The expression,

[a-z]* will match a blank string or any of the above strings.

If you want to specify a group of characters to match one or more times, then you can use the
parentheses as follows:

(Xyz)+

The above expression will match Xyz, XyzXyz, and XyzXyzXyz, etc.


\\d+ matches one integer or more??

*/

int main()
{
  // match the text
  std::regex str1("(test)(.*)");
  std::string str3 = "test takers";

  std::cout << std::boolalpha << std::regex_match(str3, str1) << std::endl;

  // search in a string
  std::string str2 = "This is a test.";
  std::smatch matched;

  std::cout << std::boolalpha << std::regex_search(str2, matched, str1) << std::endl;

  //
  std::cout << std::endl;
  std::string tst = "AB27x45x78x1";
  std::regex find("AB(\\d+)x(\\d+)x(\\d+)x(\\d+)");

  std::cout << " test: " << std::boolalpha << std::regex_search(tst, matched, find) << std::endl;
  std::cout << matched.size() << std::endl;

  for (auto matches : matched) std::cout << matches << std::endl;

  //
  std::cout << std::endl;
  std::regex items("[0-9]{1,2}");

  std::cout << " test2: " << std::boolalpha << std::regex_search(tst, matched, items) << std::endl;
  std::cout << matched.size() << std::endl;

  for (auto matches : matched) std::cout << matches << std::endl;

  // replace
  std::cout << std::endl;
  std::string rep = "BABAK Poursartip";
  std::regex change1("(BABAK)(.*)");
  std::regex change2("BABAK");

  std::string out = std::regex_replace(rep, change1, "Babak");
  std::cout << out << std::endl;

  out = std::regex_replace(rep, change2, "Babak");
  std::cout << out << std::endl;

  std::cout << " done \n";
  return 0;
}
