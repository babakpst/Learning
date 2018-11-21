
// constructing vectors
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>


int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (5,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> thirdp (second.begin(),second.end()-1);  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third
  std::vector<int> vector5;



  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );


  // working on the first vector
  first.push_back(1);
  first.push_back(2);
  first.push_back(3);

  std::cout << " first vector:"  <<  std::endl;
  for (unsigned int ii=0; ii< first.size(); ii++)
  //std::cout << first.at(ii) << "  ";
  std::cout << first[ii] << "  ";
  std::cout << std::endl;



// working with second vector
  //for ( std::vector<int>::iterator iteration=second.begin(); iteration !=second.end(); iteration++)
  for (unsigned int it=0; it < second.size(); it++) std::cout << " second " << second[it] << std::endl;
  
std::cout << std::endl;
  //for ( std::vector<int>::iterator iteration=third.begin(); iteration !=third.end(); iteration++)
  for (unsigned int it = 0; it < third.size(); it++) std::cout << " third " << third[it] << std::endl;

std::cout << std::endl;
  for (unsigned int it = 0; it < thirdp.size(); it++) std::cout << " thirdp " << thirdp[it] << std::endl;

std::cout << std::endl;

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

//////////////////////////////////
  std::vector<int> ID;                                   // empty vector of ints
  int NEL = 15;
  ID.resize(NEL);
  for (int ii=0; ii< NEL; ii++) ID[ii] = ii+1;

  for (int ii=0; ii< NEL; ii++) std::cout << "ID["<<ii<<"]=" << ID[ii] << std::endl;


  int sizeOfVector = 10;
  
  vector5.resize(sizeOfVector);
    // filling the vector5
    //for (std::vector<int>::iterator iteration = vector5.begin(); iteration < vector5.end(); iteration++ )
    for (int iteration =0; iteration < sizeOfVector; iteration++ ) vector5[iteration] = 2 * iteration;
    
    // observing the vector5
    //for (std::vector<int>::iterator iteration = vector5.begin(); iteration < vector5.end(); iteration++ )
    for (int iteration=0; iteration < sizeOfVector; iteration++) std::cout << "vector5 " << vector5[iteration] << std::endl;

// operations on vectors

//int Sum_third = std::accumulate (begin(third), end(end),0.0);
//std::cout << " The summation of the third vector: " << Sum_third << '\n'; 







  return 0;
}
