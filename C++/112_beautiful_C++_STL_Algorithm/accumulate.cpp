
/*

Babak Poursartip
11/19/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

accumulate: accumulates the objects in a container, using + operator. If + is overloaded, accumulate uses the overloaded function. 

- A lambda can be used, as a forth param in accumulate, to define how the function accumulates. The lambda takes two param and returns a param in a way that we want the accumulate works.
- Total does not have to be the same type as elements.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // required for accumulate

int main(){

std::cout << " starts here ...\n";

// accumulate: simple case ==============
std::vector<int> mV{1,2,3,4,5,6,8};

// the zero is for the initialization of total
int total = accumulate(begin(mV), end(mV), 0);
std::cout << " total: " << total << std::endl;

// accumulate: with lambda, even ==============
auto lf = [](int total, int j){
  if (j%2==0) return total+j; 
  return total;
};

int total2 = accumulate(begin(mV), end(mV), 0, lf);
std::cout << " total2: " << total2 << std::endl;

// accumulate: with lambda * ==============
auto lf2 = [](int total, int j){
  return total*j;
};

int total3 = accumulate(begin(mV), end(mV), 1, lf2);
std::cout << " total3: " << total3 << std::endl;

// accumulate: with string  ================
std::vector<std::string> w{"one", "two","three"};
auto all_words = accumulate(begin(w), end(w),std::string{});
std::cout << "words: " << all_words << std::endl;

// accumulate: with string and lambda  ================
auto lf3 = [](const std::string &total, const std::string &m){return total + " " + m;};
auto all_words2 = accumulate(begin(w), end(w),std::string{"words new: "}, lf3);
std::cout << all_words2 << std::endl;

// accumulate: with string and lambda and int  ================
auto lf4 = [](const std::string &total, int m){return total + " " + std::to_string(m);};
auto all_words3 = accumulate(begin(mV), end(mV),std::string{"words int: "}, lf4);
std::cout << all_words3 << std::endl;


std::cout << " finished.\n";

return 0;
}
