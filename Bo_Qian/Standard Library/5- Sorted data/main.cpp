
/*

Developer: Babak Poursartip

This code is based on the Bo Qian c++ Standard Library playlist. 
This section is: STL Algorithms #4 Sorted Data Algorithms and numeric Algorithms.

Date: 4/15/2019

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(){

std::cout << std:: endl  << " This is the sorted algorithm: " << std::endl << std:: endl ;

// 1- binary search -------------------------------------------------------------------------------
std::vector<int> vec={8, 9,9,9,45,87,90};

std::cout << " vector: " << std::endl<< std:: endl ;
for (std::vector<int>::iterator itr=vec.begin(); itr!=vec.end(); ++itr){
  std::cout << *itr << std::endl;
}

{
bool found = std::binary_search(vec.begin(), vec.end(), 9);
std::cout << " the data is found? " << found << std::endl;
}
{
bool found = std::binary_search(vec.begin(), vec.end(), 10);
std::cout << " the data is found? " << found << std::endl;
}

// found -----
std::vector<int> vec2={6, 45, 87};
{
// returns true if all elements of vec2 are in vec.
bool found = includes(vec.begin(), vec.end(), vec2.begin(), vec2.end());  
std::cout << " includes? " << found << std::endl;
}



// ---------------------------------------
std::cout << std:: endl << " end of the code! " << std::endl<< std:: endl ;
return 0; 

}