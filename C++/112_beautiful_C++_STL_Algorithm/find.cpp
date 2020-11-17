

/*

Babak Poursartip
11/17/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

Count

*/


#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

  std::cout << " starts here ...\n";
	
	std::vector<int> v{4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
	std::string s{ "Hello, I am Babak, working in Ansys." };

	//find the first zero in the collection
  const int target = 0;
	auto result = find(begin(v), end(v), target);
	int weLookedFor = *result;
  std::cout << "find results: " << weLookedFor << std::endl;
	
	// find the first 2 after that zero:
	// the starting index is not the first element of the vector
  const int target2 = 2;
	result = find(result, end(v), target2); 
	if (result != end(v))
	{
		weLookedFor = *result;
	}

	//find the first a
	auto letter = find(begin(s), end(s), 'a');
	char a = *letter;
  std::cout << "find results: " << a << std::endl;

	//find first odd value
	result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	weLookedFor = *result;


	//find first even value
	result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	weLookedFor = *result;
  std::cout << "find results: " << weLookedFor << std::endl;


  // find using a range
	std::vector<int> primes{2,3,5,7,11,13};
	result = find_first_of(begin(v), end(v), begin(primes), end(primes));
	weLookedFor = *result;
  std::cout << "find the first prime in a vec: " << weLookedFor << std::endl;

  // find a sequence in a vector
	std::vector<int> subsequence{2, 4};
	result = search(begin(v), end(v), begin(subsequence), end(subsequence));
	weLookedFor = *result;
	result++; result++;
	int six = *result;
  std::cout << "sequence: " << six << std::endl;

  // find a sequence in a string in a string
	std::string am = "am";
	letter = search(begin(s), end(s), begin(am), end(am));
	a = *letter;
  std::cout << "find results: " << a << std::endl;

  // find a sequence from the end
	result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
	result++; result++;
	if (result != end(v))
	{
		weLookedFor = *result;
	}

  // search if it find consecutive matches: searches for 2 consecutive 4
	result = search_n(begin(v), end(v), 2, 4);
	result--;
	int two = *result;
  std::cout << "consecutive: " << two << std::endl;


  // finds two similar elements in the vector, in this case 6
	result = adjacent_find(begin(v), end(v));
	six = *result;
  std::cout << "adjacent: " << six << std::endl;
	result++;
	six = *result;
  std::cout << "adjacent: " << six << std::endl;

  std::cout << " finished.\n";
  return 0;
}

