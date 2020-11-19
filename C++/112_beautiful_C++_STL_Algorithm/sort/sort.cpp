
/*

Babak Poursartip
11/18/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

topic: Sort

Remark: 
- Sorting is using < (less than operator), so, if we are sorting objects, we can overload < operator, to sort those objects.

- A more convenient way, instead of operator overload, is to use lambda with sort.

- stable sort: This is more expensive in terms of time and space in comparison to ordinary sort, but it cares about TIES. If there is a ties, stable_sort keeps the original order of the container.


- if a collection is sorted, to find and element, instead of the find command, we can usd upper_bound().
- upper_bound() is a standard library function in C++ defined in the header . It returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val.
  Syntax 1:
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val);
Syntax 2:
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);

*/
#include <iostream>
#include <vector>
#include <algorithm>

//#include <random>
//#include <cmath>

#include "employee.h"


int main(){

std::cout << " starts here ...\n";

std::vector<int> myV{4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
auto vec = myV;

std::cout << " here is my vec: \n";
for (auto c:vec) std::cout << c << " ";
std::cout << "\n\n";

// sorting 
sort(begin(vec), end(vec));
std::cout << " here is my vec 1 : \n";
for (auto c:vec) std::cout << c << " ";
std::cout << "\n\n";

// sorting with lambda - descending order
sort(begin(vec), end(vec),[](int a, int b){return a > b;});
std::cout << " here is my vec 2 : \n";
for (auto c:vec) std::cout << c << " ";
std::cout << "\n\n";

// sorting with lambda - ascending order
sort(begin(vec), end(vec),[](int a, int b){return a < b;});
std::cout << " here is my vec 3 : \n";
for (auto c:vec) std::cout << c << " ";
std::cout << "\n\n";


// sorting with lambda - abs value descending
sort(begin(vec), end(vec),[](int a, int b){return abs(a) > abs(b);});
std::cout << " here is my vec 4 : \n";
for (auto c:vec) std::cout << c << " ";
std::cout << "\n\n";


// sort by one field and then sort by another field.
std::vector<employee> staff{{"Poursartip","Babak",10}, {"Pejman","Babak",12},
                            {"PejmanA","Shiva",10}, {"Abbas","Ho",14},
                            {"Fathi","Arash",18}, {"Samii","Ali",9}};

std::cout << " Employee: \n";
for (auto c:staff) std::cout << "("<< c.getName() << "-" << c.getSalary() << ")**";
std::cout << "\n\n";


//sort(begin(staff), end(staff)); // error bcs < is not defined for employee.
// by salary - descending
sort(begin(staff), end(staff), [](employee a, employee b){return a.getSalary() < b.getSalary();});
std::cout << " Employee sorted by salary: \n";
for (auto c:staff) std::cout << "("<< c.getName() << "-" << c.getSalary() << ")**";
std::cout << "\n\n";

// by name - descending
sort(begin(staff), end(staff), [](employee a, employee b){return a.getName() < b.getName();});
std::cout << " Employee sorted by name: \n";
for (auto c:staff) std::cout << "("<< c.getName() << "-" << c.getSalary() << ")**";
std::cout << "\n\n";

// stable_sort, keeps people with the same salary in the alphabetic order, with the sort itself, similar slamaries may be switched.
//sort(begin(staff), end(staff), [](employee a, employee b){return a.getSalary() < b.getSalary();});
stable_sort(begin(staff), end(staff), [](employee a, employee b){return a.getSalary() < b.getSalary();});

std::cout << " Employee sorted by salary: \n";
for (auto c:staff) std::cout << "("<< c.getName() << "-" << c.getSalary() << ")**";
std::cout << "\n\n";


// is sorted ++++++++++++++++++++++
std::cout << " is it sorted: : " <<std::boolalpha << is_sorted(begin(vec), end(vec)) << std::endl;

std::cout << " is it sorted: : " <<std::boolalpha << is_sorted(begin(vec), end(vec), [](int a, int b){return abs(a)>abs(b);}) << std::endl;




// max and min element in a vector ++++++++++++++++++++++
int max = *(max_element(begin(myV),end(myV)));
int min = *(min_element(begin(myV),end(myV)));
std::cout << " min: " << min << " max: " << max << std::endl;
// or we can sort it and take the first and last element of the collection
sort(begin(vec),end(vec));
min = *(begin(vec));
max = *(end(vec)-1);
std::cout << " min: " << min << " max: " << max << std::endl;


// upper_bound: input should be sorted
int positive = *upper_bound(begin(vec), end(vec),0);

// sort the staff vector alphabetically
std::sort(begin(staff), end(staff),
	[](Employee e1, Employee e2) {return e1.getName() < e2.getName(); });

auto p = std::lower_bound(begin(staff), end(staff), "Gregory, Kate",
		[](Employee e1, std::string n) {return e1.getName() < n; });
int sal = p->getSalary();
std::cout << " salary: " << sal << std::endl;

std::cout << " finished.\n";

return 0;
}
