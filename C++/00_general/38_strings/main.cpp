
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

std::string testchar(std::string str)
{
  cout << " in the func testchar \n";
  int size = str.size();
  char out[size];
  out[0] = 'a';
  out[2] = 'b';
  out[1] = 'c';
  out[3] = 'd';  
  out[4] = 'f';
  out[6] = 'g';
  return string(out);
}


//*
std::string test(std::string str)
{
  cout << " in the func test \n";
  int len = str.size();
  std::string out(len,'0'); // to initialize a string
  out[0] = 'b';
  out[2] = 'c';
  cout << out[0]<< std::endl;
  const char tt = out[0];
  bool tr = tt =='b';

  cout << (tt =='b') << " - " << (tt =='1') << std::endl;
  cout << (out[0]=='b') << " - " << ( out[0] =='1') << std::endl;  
  
  
  return out;
}
//*/



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

  // ========================================
  puts(" 6 ======================"); // string comparison
  string str10 = "Babak", str11 = "Shiva", str12 = "BABA";
  cout << " comparison: " << boolalpha <<(str10 < str11)  << " AND " << boolalpha <<(str10 < str12) << 	endl;


  // ========================================
  puts(" 7 ======================"); // string comparison
  int len = 12;
  string str13[len];
  str13[0] = 'b';
  cout << str13[0] << std::endl;
  cout << str10 << " " << str10[0] <<std::endl;
  string str14[1];
  //str14[0]=string( str10[0]);  
  //cout << str14 << std::endl;
  std::string str15="babak";

  cout << testchar(str15) << endl;
  string out = test(str15);
  
  cout << out << " size: " << out.size() << endl;

  puts(" \n ends");
  return 0;
}
