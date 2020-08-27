
// Babak Poursartip
// 08/27/2020

// String
// String: a group of characters

// C++ has a class named base_string
// std::string is a template from the base_string
// char is the underline data type of string


#include <iostream>


using namespace std;
using namespace std::string_literals;

// pass a string to a funciton
//void PrintString(std::string e){ // pass as a copy
void PrintString(const std::string &e){  
cout << " Print: " << e <<"\n";
}


int main() {
  puts(" starts \n");

  // ========================================
  puts(" 1 ======================");
  string str = "babak";
  cout << " Here is the string: " << str <<"\n";
  cout << " size of string: " << str.size() <<"\n";

 // ========================================
  puts(" 2 ======================");
  string str1 = "babak";
  string str2 = "shiva";
  str1+= str2;
  cout << " Here is the concatenate: " << str1 <<"\n";

  //string str3 = "babak" + "shiva"; This is an error bcs "babak"  and "shiva" are both const char, and there is no operator overload + for this
  str2+= "behnaz"; // This is ok! adding a pointer to a string. + is overloaded.
  cout << " Here is the concatenate: " << str2 <<"\n";

  string str4 = string("babak") + "shiva";
  cout << " Here is the concatenate: " << str4 <<"\n";

 // ========================================
  puts(" 3 ======================");
  cout << " .find: prints the index if finds the string: \n" 
       << str1 << " " << str1.find("ak") <<"\n";

  bool contains = str1.find("ak") != std::string::npos;

 // ========================================
  puts(" 4 ======================");
  PrintString(str1); 

// ========================================
  puts(" 5 ======================"); // lieteral
  std::string name = "babak"s + " poursartp";  // s allows for concatation
  cout << " literals: " << name <<"\n";

  puts(" \n ends");
  return 0;
}
