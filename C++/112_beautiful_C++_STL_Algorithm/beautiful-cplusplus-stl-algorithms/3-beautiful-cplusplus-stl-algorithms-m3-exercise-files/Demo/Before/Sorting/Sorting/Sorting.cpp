// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <cmath> // for abs
#include "Employee.h"
#include <random>
 
using namespace std;

int main()
{
	vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
	auto v2 = v;
	sort(begin(v2), end(v2));
	sort(begin(v2), end(v2), 
		[](int elem1, int elem2) {return elem1 > elem2; });
	sort(begin(v2), end(v2), 
		[](int elem1, int elem2) {return abs(elem1) > abs(elem2); });

	std::vector<Employee> staff{
		{ "Kate", "Gregory", 1000 },
		{ "Obvious", "Artificial", 2000 },
		{ "Fake", "Name", 1000 },
		{ "Alan", "Turing", 2000 },
		{ "Grace", "Hopper", 2000 },
		{ "Anita", "Borg", 2000 }
	};

	//std::sort(begin(staff), end(staff)); //- only works if operator< defined for Employee

	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });
	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });

	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });
	std::stable_sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });

	auto sorted = is_sorted(begin(v2), end(v2));
	sorted = is_sorted(begin(v2), end(v2),[](int elem1, int elem2) {return abs(elem1) > abs(elem2); });

	int high = *(max_element(begin(v), end(v)));
	int low = *(min_element(begin(v), end(v)));
	sort(begin(v2), end(v2));
	low = *begin(v2);
	high = *(end(v2)-1);
	int positive = *upper_bound(begin(v2), end(v2), 0);

	std::sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });

	auto p = std::lower_bound(begin(staff), end(staff), "Gregory, Kate",
			[](Employee e1, std::string n) {return e1.getSortingName() < n; });
	int sal = p->getSalary();

	random_device randomdevice;
	mt19937 generator(randomdevice());
	
	shuffle(begin(v2), end(v2), generator);

	partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2));

	int breakpoint = *is_sorted_until(begin(v2), end(v2));

	vector<int> v3(3);
	partial_sort_copy(begin(v), end(v), begin(v3), end(v3));

	v2 = {1,5,4,2,9,7,3,8,2};
	int i = *(begin(v2) + 4);
	nth_element(begin(v2), begin(v2)+4, end(v2));
	i = *(begin(v2) + 4);


	return 0;
}

