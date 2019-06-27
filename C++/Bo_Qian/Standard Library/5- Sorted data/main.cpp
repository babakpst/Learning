
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
// search elements
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

// search positions
// finds the first position where 9 could be inserted and still keep the sorting.
{
std:: vector<int>::iterator itr =  lower_bound(vec.begin(), vec.end(), 9);
std::cout << " lower bound of the vec:" << *itr << std::endl;
}

// finds the last position where 9 could be inserted and still keep the sorting.
{
std:: vector<int>::iterator itr =  upper_bound(vec.begin(), vec.end(), 9);
std::cout << " lower bound of the vec:" << *itr << std::endl;
}

//-------------------------------------------------------------
// Merge
// Both input vectors should be sorted already. Duplicates are kept.
std::vector<int> vector1= {8,9,9,10};
std::vector<int> vector2= {7,9,3};

std::sort(vector1.begin(), vector1.end());
std::sort(vector2.begin(), vector2.end());

std::vector<int> vector_out(7);

std::merge(vector1.begin(), vector1.end(),   // input range 1
          vector2.begin(), vector2.end(),    // input range 2
          vector_out.begin());               // the merged vector


  for (std::vector<int>:: iterator itr=vector_out.begin(); itr!=vector_out.end(); ++itr){
    std::cout << " merged vectors: " << *itr << std::endl;
  }


std::vector<int> vector3={1,2,3,5,1,2,3,4,5}; // both parts of vector is already sorted
std::inplace_merge(vector3.begin(), vector3.begin()+4, vector3.end());

for (std::vector<int>:: iterator itr=vector3.begin(); itr !=vector3.end(); ++itr ){
  std::cout << "inplace_merge: " << *itr << std::endl;
}


// 3- Set operations
std::cout << " Operators: " << std::endl << std::endl;

// both vectors should be sorted
std::vector<int> vector4 = {8,9,9,10};
std::vector<int> vector5 = {7,9,10};
std::vector<int> vector_out2(5);
std::vector<int> vector_out3(5);
std::vector<int> vector_out4(5);
std::vector<int> vector_out5(5);

std::set_union(vector4.begin(), vector4.end(), 
               vector5.begin(), vector5.end(),
               vector_out2.begin()); //if X is in both vector3 and 4, only one X is kept in vec_out


  for (std::vector<int>:: iterator itr = vector_out2.begin(); itr != vector_out2.end(); ++itr){
    std::cout << " Union: " << *itr << std::endl;
  }
std::cout << "End Union. " << std::endl << std::endl;

std::set_intersection(vector4.begin(), vector4.end(), 
               vector5.begin(), vector5.end(),
               vector_out3.begin()); //Only the items that are in both vecs are saved in vec_out


  for (std::vector<int>:: iterator itr = vector_out3.begin(); itr != vector_out3.end(); ++itr){
    std::cout << " intersection: " << *itr << std::endl;
  }

std::cout << "End intersection. " << std::endl << std::endl;

std::set_difference(vector4.begin(), vector4.end(), 
               vector5.begin(), vector5.end(),
               vector_out4.begin()); //Only  items that are in vec4 but not in vec5 are saved in vec_out


  for (std::vector<int>:: iterator itr = vector_out4.begin(); itr != vector_out4.end(); ++itr){
    std::cout << " difference: " << *itr << std::endl;
  }

std::cout << "End difference. " << std::endl << std::endl;

std::set_symmetric_difference(vector4.begin(), vector4.end(), 
               vector5.begin(), vector5.end(),
               vector_out5.begin()); //vec_out has items from either vec4 or 5, not from both.


  for (std::vector<int>:: iterator itr = vector_out5.begin(); itr != vector_out5.end(); ++itr){
    std::cout << " difference: " << *itr << std::endl;
  }


//  numeric Algorithms ------------------------------------------------------------------

int x = std::accumulate(vector1.begin(), vector1.end(), 10); // adding numbers
std::cout << " find the summation of all elements: "  << x << std::endl;

int y = std::accumulate(vector1.begin(), vector1.end(), 10, std::multiplies<int>());
std::cout << " find the product of all elements: "  << y << std::endl;


std::vector<int> vector6 = {1,2,3,4};
std::vector<int> vector7 = {1,2,3,4};

int z= std::inner_product(vector6.begin(), vector6.begin()+3,
                          vector6.end()-3, 10);

std::cout << " find the inner product: "  << z << std::endl;

int zz= std::inner_product(vector6.begin(), vector6.begin()+3,
                          vector6.end()-3, 10, std::multiplies<int>(), std::plus<int>());
///10 * (vec[0]+vec[4]) *  (vec[1]+vec[5]) * ...
std::cout << " find the inner product: "  << zz << std::endl;




// ---------------------------------------
std::cout << std:: endl << " end of the code! " << std::endl<< std:: endl ;
return 0; 
}
