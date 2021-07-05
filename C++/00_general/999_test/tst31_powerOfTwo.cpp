/*

AMD interview
Given a positive integer, write a function to find if it is a power of two or not.

*/

#include <iostream>
#include <cmath>
using std::cout;

// ==========
bool isPowerOfTwo3(int value)
{
int d = 2;
while(d<=value)
{
  if (d == value) return true;
  d*=2;
}
return false;
}

// ==========
bool isPowerOfTwo2(int value)
{
return (ceil(log2(value))==floor(log2(value)));
}
// ==========
bool isPowerOfTwo(int value)
{
if (value % 2 == 1) return false;

while (value>1)
{
if (value%2!=0)
  return false;
value /=2;
}

return true;
}

// ==========
int main()
{

cout << " starts \n";

int value = 123456;
cout << value << " " << isPowerOfTwo(value) << "\n";
value = 32;
cout << value << " " << isPowerOfTwo(value) << "\n";
value = 128;
cout << value << " " << isPowerOfTwo(value) << "\n";
value = 5879827;
cout << value << " " << isPowerOfTwo(value) << "\n";
cout << " algo 2\n";
value = 32;
cout << value << " " << isPowerOfTwo2(value) << "\n";
value = 123456;
cout << value << " " << isPowerOfTwo2(value) << "\n";

cout << " algo 3\n";
value = 32;
cout << value << " " << isPowerOfTwo3(value) << "\n";
value = 123456;
cout << value << " " << isPowerOfTwo3(value) << "\n";

cout << "\n ends here \n";
return 0;
}
