
/*

Babak Poursartip
01/16/2021

Reference: Boost
PluralSight

String operations


*/
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include <boost/token_functions.hpp>
#include <boost/token_iterator.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>

void tokenize() {
  std::cout << "\n1 ========\n";
  std::string s = "This is a string that I generated.!";
  boost::tokenizer<> t(s); // tokenizes the string with the default separator.

  for (std::string part : t) {
    std::cout << "<" << part << ">" << std::endl;
  }

  // ============================
  std::cout << "\n2 ========\n";
  boost::char_separator<char> sep("o", " ", boost::keep_empty_tokens);
  std::string s2 = "Here is another sentence that I want to scrutinize here to "
                   "see how tokenizer is working!";
  boost::tokenizer<boost::char_separator<char>> t2(
      s, sep); // tokenizes the string with the default separator.

  for (std::string part : t2) {
    std::cout << "<" << part << ">" << std::endl;
  }

  // ============================
  std::cout << "\n3 ========\n";
  int offsets[] = {2, 4, 2}; // split in 2, 4, and 2 characters.
  boost::offset_separator os(offsets, offsets + 3);

  auto start =
      boost::make_token_iterator<std::string>(s2.begin(), s2.end(), os);
  auto end = boost::make_token_iterator<std::string>(s2.end(), s2.end(), os);

  for (; start != end; ++start) {
    std::cout << *start << std::endl;
  }
}

// =======================
// =======================
// converts string to numerical values
void lexical_cast() {
  std::cout << "\n 4 ========\n";
  std::string s0 = "2.1";
  double d = boost::lexical_cast<double>(s0);
  std::string s1 = "2451";
  int m = boost::lexical_cast<int>(s1);
  std::cout << d << ", " << m << std::endl;

  // boost::lexical_cast<int>("babak"); // throws an exception, by itself
  try {
    boost::lexical_cast<int>("babak"); // throws an exception, by itself
  } catch (const boost::bad_lexical_cast &e) {
    std::cout << e.what() << std::endl;
  }
}

// =======================
// =======================
void boost_algorithm() {

  std::cout << "\n 5 =============\n";
  std::string test = " hello, Babak.   You    are awesome\r\n";
  // trim the end of the sentence.
  boost::trim(test);

  std::cout << "<" << test << ">" << std::endl;

  boost::algorithm::trim_all(test); // removes double spaces.
  std::cout << "<" << test << ">" << std::endl;

  // turn to upper case
  boost::to_upper(test);
  std::cout << "<" << test << ">" << std::endl;
  // turn to upper case
  boost::to_lower(test);
  std::cout << "<" << test << ">" << std::endl;
}

// =======================
// =======================
int main() {

  std::cout << " starts here ...\n";
  tokenize();

  // lexical cast demo
  lexical_cast();

  boost_algorithm();

  std::cout << " finished.\n";

  return 0;
}
