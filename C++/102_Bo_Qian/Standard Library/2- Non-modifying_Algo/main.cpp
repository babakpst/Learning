

/*

based on Bo Qian, c++ standard library- non-modifying algorithms
Babak Poursartip
02/11/2019

*/

#include <iostream>
#include <vector>
#include <algorithm>    // std::count


int main(){


std::cout << std::endl <<" Non-modifying algorithms ..." << std::endl <<std::endl;


std::vector<int> vec= { 9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7} ;

// count
int numCount = count(vec.begin(), vec.end(), 69);
std::cout << " number of elements equal to 69: " << numCount << std::endl;
numCount = count(vec.begin()+2, vec.end()-1, 69);
std::cout << " number of elements equal to 69: " << numCount << std::endl;

// count if
numCount = count_if(vec.begin(), vec.end(), [](int x){return x==69;});
std::cout << std::endl << " number of elements in the vec that are equal to 69: " << numCount << std::endl;

int numless  = count_if(vec.begin(), vec.end(), [](int x){ return x<10;}); // this is a lambda fn
std::cout << " number of elements less than 69: " << numless << std::endl;

// max element
std::vector<int>::iterator itr = max_element(vec.begin(), vec.end() );
std::cout << std::endl  << " max element in the vec: " << *itr << std::endl;

// generalized form of the max_element operation, we can define our own definition
std::vector<int>::iterator itr2 = max_element(vec.begin(), vec.end(), [](int x, int y){return (x%10)<(y%10);} );
std::cout << std::endl  << " max element in the vec-remainder: " << *itr2 << std::endl;


// min_element
std::vector<int> :: iterator itr3 = min_element(vec.begin(), vec.end());
std::cout << std::endl << " min element in the vec: " << *itr3 << std::endl;

// minmax element
std::pair<std::vector<int>:: iterator, std::vector<int>:: iterator> pair_of_itr;
pair_of_itr =  minmax_element(vec.begin(), vec.end());

std::cout << std::endl << " min max results- min part: " << *pair_of_itr.first << " max part: " << *pair_of_itr.second <<std::endl;

// linear search for the case that data is not sorted
// returns the first item that matches the condtion
std::vector<int> :: iterator itr4;
itr4 = find(vec.begin(), vec.end(), 55);
std::cout << std::endl << " find resutls 55:" << * itr4 << std::endl;  // not the best example

std::vector<int>:: iterator itr5;
itr5 = find_if(vec.begin(), vec.end(), [](int x){return x > 80;});
std::cout << std::endl << " find if example greater than 80: " << *itr5 << std::endl;


std::vector<int>:: iterator itr6;
itr6 = find_if_not(vec.begin(), vec.end(), [](int x){return x > 80;});
std::cout << std::endl << " find if example greater than 80: " << *itr6 << std::endl;

// search
std::vector<int>::iterator itr7;
itr7 = search_n(vec.begin(), vec.end(), 2, 69);
std::cout<< std::endl << " search option: " << *itr7 << std::endl;


// all of
bool checkif;
checkif = all_of(vec.begin(), vec.end(), [](int x){return x>80 ;});
std::cout << std::endl << " all of command " << checkif << std::endl;

checkif = any_of(vec.begin(), vec.end(), [](int x){return x>80 ;});
std::cout << std::endl << " all of command " << checkif << std::endl;

checkif = none_of(vec.begin(), vec.end(), [](int x){return x>80 ;});
std::cout << std::endl << " all of command " << checkif << std::endl;

//many other functions

//------------------------------------------
std::cout << std::endl << " end of the code! " << std::endl;

return 0;
}