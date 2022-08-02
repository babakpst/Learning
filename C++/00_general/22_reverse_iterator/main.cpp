
// Babak Poursartip
// July 31, 2022

// reverse_iterator


#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{

  std::cout << " starts here ... \n";

  std::vector<int> vec{1,2,3,4,5,6,7,8,9};
  
  std::cout << " vector: \n";
  for_each(vec.begin(), vec.end(), [](auto x){std::cout << x << " "; });
  std::cout << "\n";


  std::cout << "reverse vector: \n";
  for_each(vec.rbegin(), vec.rend(), [](auto x){std::cout << x << " "; });
  std::cout << "\n";

  std::cout << " some other formats ... \n";
  for (std::vector<int>::reverse_iterator end=vec.rbegin(); end!=vec.rend(); end++)
  {
    std::cout << *end << " ";
  }



  std::cout << " done. \n";
  return 0;
}
