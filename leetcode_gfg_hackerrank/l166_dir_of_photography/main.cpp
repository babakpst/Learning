
/*
A photography set consists of N cells in a row, numbered from  1 to N in order, and can be represented by a string C of
length N. Each cell i is one of the following types (indicated by Ci, the ith character of C): If Ci = “P”, it is
allowed to contain a photographer If Ci = “A”, it is allowed to contain an actor If Ci = “B”, it is allowed to contain a
backdrop If Ci = “.”, it must be left empty

A photograph consists of a photographer, an actor, and a backdrop, such that each of them is placed in a valid cell, and
such that the actor is between the photographer and the backdrop. Such a photograph is considered artistic if the
distance between the photographer and the actor is between X and Y cells (inclusive), and the distance between the actor
and the backdrop is also between X and Y cells (inclusive). The distance between cells i and j is ∣i−j∣(the absolute
value of the difference between their indices).

Determine the number of different artistic photographs which could potentially be taken at the set. Two photographs are
considered different if they involve a different photographer cell, actor cell, and/or backdrop cell.

Constraints
1≤N≤200
1≤X≤Y≤N

Sample test case #1
N = 5
C = APABA
X = 1
Y = 2
Expected Return Value = 1

Sample test case #2
N = 5
C = APABA
X = 2
Y = 3
Expected Return Value = 0

Sample test case #3
N = 8
C = .PBAAP.B
X = 1
Y = 3
Expected Return Value = 3

Sample Explanation
In the first case, the absolute distances between photographer/actor and actor/backdrop must be between
1 and 2. The only possible photograph that can be taken is with the 3 middle cells, and it happens to be artistic.

In the second case, the only possible photograph is again taken with the 3 middle cells. However, as the distance
requirement is between 2 and 3, it is not possible to take an artistic photograph.

In the third case, there are 4 possible photographs, illustrated as follows:
.P.A...B
.P..A..B
..BA.P..
..B.AP..
All are artistic except the first, where the actor and backdrop exceed the maximum distance of 3.
*/

#include <iostream>
#include <string>

int getArtisticPhotographCount(int N, std::string C, int X, int Y)
{
  if (N < (2 * X + 1)) return 0;
  int num = 0;

  for (int i = 0; i < N; i++)
  {
    if (C[i] == 'P')
    {
      // check options on the left
      if (i >= (2 * X))
      {
        for (int j = i - Y; j <= i - X; j++)
        {
          if (C[j] == 'A')
          {
            for (int k = j - Y; k <= j - X; k++)
            {
              if (C[k] == 'B') num += 1;
            }
          }
        }
      }

      // check options on the right
      if (i <= N - 2 * X)
      {
        for (int j = i + X; j <= i + Y; j++)
        {
          if (C[j] == 'A')
          {
            for (int k = j + X; k <= j + Y; k++)
            {
              if (C[k] == 'B') num += 1;
            }
          }
        }
      }
    }
  }

  return num;
}

int main()
{
  std::cout << " starts... " << std::endl;

  // sample 1
  int N = 5;
  std::string C = "APABA";
  int X = 1;
  int Y = 2;
  int num = getArtisticPhotographCount(N, C, X, Y);
  std::cout << " num = " << num << std::endl;

  // sample 2
  N = 5;
  C = "APABA";
  X = 2;
  Y = 3;
  num = getArtisticPhotographCount(N, C, X, Y);
  std::cout << " num = " << num << std::endl;

  // sample 3
  N = 8;
  C = ".PBAAP.B";
  X = 1;
  Y = 3;
  num = getArtisticPhotographCount(N, C, X, Y);
  std::cout << " num = " << num << std::endl;

  std::cout << " end of the line." << std::endl;
  return 0;
}
