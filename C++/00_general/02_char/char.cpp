
// char is one byte of memory that can hold one character out of the ASCII code.

// char[] or char *: This is because arrays cannot be assigned values. Note, though, that each of
// its elements can be assigned a value individually. For example, this would be
// correct: myword[0] = 'B'; myword[1] = 'y'; myword[2] = 'e'; myword[3] = '\0';

// \0 this is the null termination char. This is how it knows this is the end of char.

// char *a = "babak" This is a fixed-size allocated memory, and you cannot chagne the size later.
// char is not a heap allocator.

// a string in "", eg. "babak", is a const char array.

// Only one pointer is required to refer to whole string. That shows this is
// memory efficient.

// in C++ they are constant array of char. Therefore use const keyword before
// char*.

// Once we allocate a char name, we cannot assign a string greater than its size

/*
Summary
char mystring[101] = "My sample string";
const char * constcharp = mystring; // (1)
char const * charconstp = mystring; // (2) the same as (1)
char * const charpconst = mystring; // (3)

constcharp++; // ok
charconstp++; // ok
charpconst++; // compile error

// we cannot change the content of a const char.
constcharp[3] = '\0'; // compile error
charconstp[3] = '\0'; // compile error
charpconst[3] = '\0'; // ok

// String literals
char * lcharp = "My string literal";
const char * lconstcharp = "My string literal";

lcharp[0] = 'X';      // Segmentation fault (crash) during run-time
lconstcharp[0] = 'X'; // compile error

// *not* a string literal
const char astr[101] = "My mutable string";
astr[0] = 'X';          // compile error
((char*)astr)[0] = 'X'; // ok


*/

// char
#include <iostream>
#include <string.h>

void txt(char *str) { std::cout << "cout inside: " << str << "\n"; }

int main() {

  puts(" starts here \n");

  puts("0============");
  char *c1 = new char;
  strcpy(c1, "babak");
  printf("c1: %s \n", c1);

  char c2[] = "shiva", c3[] = "shiva";
  printf("c2: %s \n", c2);

  std::cout << "cout c2: " << c2 << "\n";

  printf("c2 = c3: %d \n", c2 == c3);   //
  printf("c2 = c3: %d \n", *c2 == *c3); //

  //============================
  puts("1============");
  char *s = "babak";
  //*s = "B"; //error
  txt(s);

  std::cout << "cout s: " << s << "\n";
  std::cout << "cout *s: " << *s << "\n";
  std::cout << "cout *s: " << *(s + 1) << "\n";
  s = "B";
  std::cout << "cout s: " << s << "\n";
  txt(s);

  //============================
  puts("2============");
  puts(" for ");
  int i = 0;
  char ss[] = "hello";

  for (i = 0; ss[i]; ++i)
    std::cout << i << std::endl;

  i = 0;
  puts(" while ");
  while (ss[i++])
    std::cout << i << std::endl;

  //============================
  puts("3============");
  char *p = new char[1024]; // allocate memory so cin
  p = "haha";
  char q = *p;
  std::cout << "p = " << p << std::endl;
  std::cout << "*p = " << *p << std::endl;
  std::cout << "&q = " << &q << std::endl;
  std::cout << "q = " << q << std::endl;

  //============================
  puts("4============");
  char c4;
  c4 = 'a';
  // c4="ab"; // error
  std::cout << "cout c4: " << c4 << "\n";

  //============================
  puts("5============");
  const char *p1 = "12345";
  std::cout << " p " << p1 << "  " << *p1 << "\n";

  const char **q1 = &p1;
  *q1 = "abcde";

  const char *s1 = ++p1;
  p1 = "XYZWVU";
  std::cout << *++s1<< "\n";

  //=============================================================================
  puts("6=======");

  char myword[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  std::cout << " size my: " << sizeof(myword) << "\n";

  char p13;
  p13 = 'a'; // ok
  // p13="baba"; // error

  char p14[] = "123456";
  std::cout << " size P14: " << sizeof(p14) << "\n";
  char p15[7];
  p15[0] = '1';
  p15[1] = '2';
  p15[2] = '3';
  p15[3] = '4';
  p15[4] = '5';
  p15[5] = '6';
  std::cout << " size P14: " << sizeof(p14) << "\n";

  char *p14Size = "123";
  std::cout << " size: " << sizeof(p14Size) <<" " << sizeof(*p14Size) <<" " << strlen(p14Size)<<" "   << sizeof(char*) << "\n";

  const char *name10 = "bab\0ak";
  std::cout << " size: " << strlen(name10) << " " << name10 << "\n";

  //=============================================================================
  puts("7========");

  const char *p10 = "123456";
  char *p11 = "123456";
  std::cout << " P10: " << p10 << " " << p11 << "\n";
  std::cout << " P10: " << *p10 << " " << *p11 << " " << *(p11 + 1) << " "
            << *(p11 + 2) << "\n";
  std::cout << " size P10: " << sizeof(p10) << "\n";

  p10 = "Babak";
  p11 = "Babak";

  std::cout << " P10: " << p10 << " " << p11 << "\n";

  //=============================================================================
  puts("8========");
  const char *p100 = "12345";
  const char **q100 = &p100;
  *q100 = "abcde";
  const char *s100 = ++p100;
  p100 = "XYZWVU";
  std::cout << *++s100<<  "\n";

  //=============================================================================
  puts("9========");

  char name[7] = "123456";
  std::cout << " name: " << name <<  "\n";
  strcpy(name, "1234567"); // error: Once we allocate a char name, we cannot assign a string greater than its size
  std::cout << " name: " << name <<  "\n";

  // but this is fine with pointers
  char *name2 = "123456";

  std::cout << " name: " << name2 <<  "\n";
  name2 = "1234567";
  std::cout << " name: " << name2 <<  "\n";

 //=============================================================================
  puts("10========"); // other types of char
  const wchar_t* wname = L"babak";  // L converts const char * to wchar
  const char16_t* name16 = u"babak";
  const char32_t* name32 = U"babak";

  std::cout << " wide name: " << wname <<  "\n";
  std::cout << " char name: " << name16 <<  "\n";

//=============================================================================
  puts("11========"); // 
  const char * lines = "line1\n"
                       "line2\n"
                       "line3\n";

  std::cout << " lines: " << lines <<  "\n";

  puts(" end ");
  return 0;
}
