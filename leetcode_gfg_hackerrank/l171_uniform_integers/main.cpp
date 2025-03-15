
/*

A positive integer is considered uniform if all of its digits are equal. For example, 222 is uniform, while 223 is not.
Given two positive integers A and B, determine the number of uniform integers between A and B, inclusive.

Please take care to write a solution which runs within the time limit.
Constraints
1≤A≤B≤10^12

Sample test case #1
A = 75
B = 300
Expected Return Value = 5

Sample test case #2
A = 1
B = 9
Expected Return Value = 9

Sample test case #3
A = 999999999999
B = 999999999999
Expected Return Value = 1


Sample Explanation
In the first case, the uniform integers between 75 and 300 are 77, 88, 99, 111, and 222.

In the second case, all 9 single-digit integers between 1 and 9 (inclusive) are uniform.

In the third case, the single integer under consideration (999,999999,999,999,999) is uniform.
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int getUniformIntegerCountInInterval2(long long A, long long B)
{
  long long tmp;
  // is A uniform

  int digitA;
  int orderA = 0;
  tmp = A;
  while (tmp > 0)
  {
    digitA = tmp % 10;
    orderA++;
    tmp /= 10;
  }

  int unA = 0;
  for (int i = 0; i < orderA; i++) unA += digitA * (pow(10, i));

  // is B uniform
  int digitB = 0;
  int orderB = 0;
  tmp = B;
  while (tmp > 0)
  {
    digitB = tmp % 10;
    orderB++;
    tmp /= 10;
  }

  int unB = 0;
  for (int i = 0; i < orderB; i++) unB += digitB * (pow(10, i));
  //========================
  cout << " digitA: " << digitA << " orderA: " << orderA << " unA: " << unA << " digitB: " << digitB
       << " orderB: " << orderB << " unB: " << unB << endl;

  int numUniforms = 0;
  numUniforms += (A <= unA && unA <= B) ? 1 : 0;
  numUniforms += (B >= unB) ? 1 : 0;
  if (A == B && A == unA) numUniforms--;
  if (orderA == orderB)
    numUniforms += (digitB - digitA - 1 > 0) ? digitB - digitA - 1 : 0;
  else
  {
    numUniforms += 9 * (orderB - orderA - 1);
    numUniforms += 9 - digitA;
    numUniforms += digitB - 1;
  }

  return numUniforms;
}

//=======================
int getUniformIntegerCountInInterval(long long A, long long B)
{
  int tmp = A;
  int orderA = 0;
  while (tmp > 0)
  {
    orderA++;
    tmp /= 10;
  }

  tmp = B;
  int orderB = 0;
  while (tmp > 0)
  {
    orderB++;
    tmp /= 10;
  }

  int unB = 0;
  for (int i = 0; i < orderB; i++) unB += pow(10, i);

  int unA = 0;
  for (int i = 0; i < orderA; i++) unA += pow(10, i);

  cout << " orderA: " << orderA << " unA: " << unA << " orderB: " << orderB << " unB: " << unB << endl;

  int nUniformA = 9 * (orderA - 1) + (A - 1) / unA;
  int nUniformB = 9 * (orderB - 1) + B / unB;
  return nUniformB - nUniformA;
}

int main()
{
  cout << " starts: " << endl;

  //  long long A = 75;
  //  long long B = 300;

  // long long A = 1;
  // long long B = 9;

  long long A = 1;
  long long B = 9;

  cin >> A >> B;
  //  long long A = 999;
  //  long long B = 999;

  //    long long A = 99;
  //    long long B = 1000;

  int out = getUniformIntegerCountInInterval(A, B);

  cout << " output: " << out << endl;

  return 0;
}
