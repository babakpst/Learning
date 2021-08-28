
// constructing vectors
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

#include <algorithm>
#include <numeric>

void func_rawPtr(int * ptr, int n)
{

std::cout << " in the function \n";

for(int i = 0; i < n; ++i)
  std::cout << ptr[i] << " ";

std::cout << std::endl;

}

/* not working
void func_uniquePtr(std::unique_ptr<int> ptr, int n)
{

std::cout << " in the unique function \n";

for(int i = 0; i < n; ++i)
  std::cout << ptr{i} << " ";

std::cout << std::endl;

}
*/

// This code tests various options in the vector data structure (stl).

int main() {
  // constructors used in the same order as described above:
  std::vector<int> first;          // empty vector of ints
  std::vector<int> second(5, 100); // four ints with value 100
  std::vector<int> third(second.begin(),
                         second.end()); // iterating through second
  std::vector<int> thirdp(second.begin(),
                          second.end() - 1); // iterating through second
  std::vector<int> fourth(third);            // a copy of third



  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16, 2, 77, 29};
  std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

  // working on the first vector
  first.push_back(1);
  first.push_back(2);
  first.push_back(3);

  std::cout << " first vector:" << std::endl;
  for (unsigned int ii = 0; ii < first.size(); ii++)
    // std::cout << first.at(ii) << "  ";
    std::cout << first[ii] << "  ";
  std::cout << std::endl;

  // working with second vector
  // for ( std::vector<int>::iterator iteration=second.begin(); iteration
  // !=second.end(); iteration++)
  for (unsigned int it = 0; it < second.size(); it++)
    std::cout << " second " << second[it] << std::endl;

  std::cout << std::endl;
  // for ( std::vector<int>::iterator iteration=third.begin(); iteration
  // !=third.end(); iteration++)
  for (unsigned int it = 0; it < third.size(); it++)
    std::cout << " third " << third[it] << std::endl;

  std::cout << std::endl;
  for (unsigned int it = 0; it < thirdp.size(); it++)
    std::cout << " thirdp " << thirdp[it] << std::endl;

  std::cout << std::endl;

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  //////////////////////////////////
  std::vector<int> ID; // empty vector of ints
  int NEL = 15;
  ID.resize(NEL);
  for (int ii = 0; ii < NEL; ii++)
    ID[ii] = ii + 1;

  for (int ii = 0; ii < NEL; ii++)
    std::cout << "ID[" << ii << "]=" << ID[ii] << std::endl;

  // iterators
  // ======================================================================================
  std::cout << std::endl;
  std::cout << " working with the iterators: " << std::endl;

  int sizeOfVector = 10;
  std::vector<double> vector5;
  vector5.resize(sizeOfVector);
  double i = 0.1;
  // filling the vector5
  for (std::vector<double>::iterator it = vector5.begin(); it != vector5.end();++it) {
    i = i * 1.11 + i;
    *it = i;
    std::cout << "creating vector5 " << *it << std::endl;
  }

  // observing the vector5
  int index;
  for (std::vector<double>::iterator it = vector5.begin(); it < vector5.end();it++) {
    index = *it;
    std::cout << " Here is the vector at " << index << " value " << *it << std::endl;
  }

  // iterators + index + strided
  // ======================================================================================
  int sizeOfMe = 10;
  std::vector<double> list;
  list.resize(sizeOfMe);
  i = 0.1;
  int index1, index2;
  std::cout << "\n iterator ========================= \n";
  for (std::vector<double>::iterator it = list.begin(); it != list.end();it += 2) {
    i = i * 1.11 + i;
    *it = i;
    *(it + 1) = i;
    index1 = it - list.begin();
    index2 = std::distance(list.begin(), it);

    std::cout << "list item: " << index1 << " " << index2 << " " << *it << " "<< *(it + 1) << std::endl;
  }

  // bool vectors
  // ===================================================================================
  std::vector<bool>	 BoolVec(20);

  bool checkbool = false;
  bool checkbool2 = true;
  std::cout << " The bool variable: " << checkbool << std::endl;
  std::cout << " The bool variable: " << checkbool2 << std::endl;

  BoolVec[0] = false;
  BoolVec[1] = false;
  BoolVec[2] = true;

  for (std::vector<bool>::iterator itr = BoolVec.begin(); itr != BoolVec.end(); ++itr) {
    std::cout << " BoolVec " << *itr << std::endl;
  }

  std::vector<bool> BoolVec2(20, true);
  for (std::vector<bool>::iterator itr = BoolVec2.begin();itr != BoolVec2.end(); ++itr) {
    std::cout << " BoolVec2 " << *itr << std::endl;
  }

  // operations on vectors
  // int Sum_third = std::accumulate (begin(third), end(end),0.0);
  // std::cout << " The summation of the third vector: " << Sum_third << '\n';

  //=====================================================
  std::vector<int> heap;
  int capsize = 10;
  // heap = new std::vector<int>(capsize);
  heap.reserve(capsize);
  heap[0] = 1;

  std::cout << "data ==========\n";
  std::vector<int> myInt(10);
  iota(begin(myInt), end(myInt),1);
  
  for_each(begin(myInt), end(myInt), [](int e){std::cout << e << " ";});
  std::cout << std::endl;

  // passing std::vector to a raw pointer
  func_rawPtr(myInt.data(), 10);
  func_rawPtr(myInt.data()+4, 6);

  // passing std::vector to a unique pointer
  std::unique_ptr<int> myUPTR = std::unique_ptr<int>(myInt.data());
  //func_uniquePtr(myUPTR, 10);
  //func_uniquePtr(myInt.data()+4, 6);

  return 0;
}
