
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

// In C++, strings are constant array of char. Therefore use const keyword before
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

// ==================================================================================
void txt(char *str) { std::cout << "txt cout inside: " << str << "\n"; }
void txt2(char &str) { std::cout << "txt2 cout inside: " << str << "\n"; }


// ==================================================================================
// ==================================================================================
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


  char text[] = "this is a text";
  std::cout << "cout text: " << text << "\n";
  txt(text);

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
  // c4="ab"; // error invalid conversion from ‘const char*’ to ‘char’
  std::cout << "cout c4: " << c4 << "\n";

  //============================
  puts("5============");
  const char *p1 = "12345";
  std::cout << " p " << p1 << "  " << *p1 << "\n";

  const char **q1 = &p1;
  *q1 = "abcde";
  std::cout << " p " << p1 << "  " << *p1 << "\n";
  std::cout << " ++p " << (p1+1) << "  " << *(p1+1) << "\n";

  const char *s1 = (p1+1);
  std::cout << " s1 " << s1 << "  " << *s1 << "\n";  
  
  p1 = "XYZWVU"; // it does not change the content of the s1
  std::cout << " s: " << s1 << " p1: " << p1 << std::endl;
 
  std::cout << *++s1<< "\n";


  /*
  const char* p = “12345″ declares a pointer to a constant. So we can’t assign something else to *p, but we can assign new value to p.
  const char **q = &p; declares a pointer to a pointer. We can’t assign something else to **q, but we can assign new values to q and *q. *q = “abcde”; changes p to point to “abcde”. const char *s = ++p; assigns address of literal ”bcde” to s. Again *s can’t be assigned a new value, but s can be changed. statement printf(“%cn”, *++s) changes s to “cde” and first character at s is printed.
  
  const char* s = ++p;
  You are declaring a pointer s and pointing it at the second character within string literal "abcde". At this point, yes, p and s both point to the contents of the same string literal.

Doing

p = "XYZWVU";

however, does not alter the string literal pointed to by s. What this does is change what pointer p is pointing to. When you do this, pointer p and s are each pointing at different string literals.
  
  */


  //=============================================================================
  puts("6 sizeof =======");

  char myword[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  std::cout << " size my: " << sizeof(myword) << "\n";
  char myword2[] = {'H', 'e', 'l', 'l', 'o'};
  std::cout << " size my2: " << sizeof(myword2) << "\n";

  char p13;
  p13 = 'a'; // ok
  // p13="baba"; // error compilation error converting from const char * to char

  char p14[] = "123456";
  std::cout << " size P14: " << sizeof(p14) << " p14: " << p14 << "\n";
  char p15[7];
  p15[0] = '1';
  p15[1] = '2';
  p15[2] = '3';
  p15[3] = '4';
  p15[4] = '5';
  p15[5] = '6';
  std::cout << " size P15: " << sizeof(p15) << "\n";

  char *p14Size = "123";
  std::cout << " sizep14: " << sizeof(p14Size) <<" " << sizeof(*p14Size) <<" " << strlen(p14Size)<<" "   << sizeof(char*) << "\n";

  char *ch1 = "babak";
  std::cout << " size: " << sizeof(ch1) << "\n";

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


  //char name[7] = "1234567";// error initializer-string for array of chars is too long.
  char name[7] = "123456";
  std::cout << " name: " << name <<  "\n";
  strcpy(name, "1234567"); // error: Once we allocate a char name, we cannot assign a string greater than its size
  std::cout << " name: " << name <<  "\n";

  // but this is fine with pointers
  char *name2 = "123456";

  std::cout << " name: " << name2 <<  "\n";
  name2 = "1234567"; // a new location in the memory, name2 is pointing to a different address.
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
