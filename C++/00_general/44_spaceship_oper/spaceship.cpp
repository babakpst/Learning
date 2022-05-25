
// spaceship operator: 3-way comparison operator
// May 23, 2022
// to compile/build:
// g++ -std=c++2a spaceship.cpp -o spaceship


#include <iostream>
#include <vector>
#include <algorithm>

struct test
{
int ivar; // , ivar2
float fvar;
double dvar;
//std::vector<double> vvar;
//bool operator<=>(const test& t) const =default; // the output of <=> is not bool
auto operator<=>(const test& t) const =default;

void printMe() const
{
std::cout << " ivar= " << ivar
          << " dvar= " << dvar
          << " fvar= " << fvar
          << std::endl;
}

};



template<typename T>
bool spaceship(T a, T b)
{
  auto ans = (a <=> b);
  //std::cout << ans << std::endl;   // error: ans is of type partial_ordering, not bool

  if (ans < 0)
    std::cout << " A<B \n";  
  else if (ans > 0)
    std::cout << " A>B \n";  
  else 
    std::cout << " A==B \n";  

return ans <0;
}


int main()
{

  std::cout << " starts ... \n";
  std::cout << " c++ version is: " << __cplusplus << std::endl; // this should be 

  spaceship<double>(1,1);
  spaceship<double>(1.1,1);
  spaceship<int>(1,2);
  spaceship<std::vector<double>>( std::vector<double>{1.1,2.1,3.1},  std::vector<double>{1.1,2.1,3.1});
  spaceship<std::vector<double>>( std::vector<double>{1.1,2.1,5.1},  std::vector<double>{1.1,2.1,3.1});

  spaceship<std::vector<double>>( std::vector<double>{1.1,2.1,3.1,4.2},  std::vector<double>{1.1,2.1,3.1});
  spaceship<std::vector<double>>( std::vector<double>{1.1,2.1,0.1,4.2},  std::vector<double>{1.1,2.1,3.1});
 
  std::cout << " class ...\n"; 
  test tvar1=test{1,2,3};
  test tvar2=test{1,2,3};
  test tvar3=test{4,2,3};
  test tvar4=test{2,2,3};  
  test tvar5=test{1,2,8};
  test tvar6=test{1,2,1};
  test tvar7=test{1,-1.2,1};
  test tvar8=test{1,-1.2,-1};


  tvar1.printMe();
  tvar2.printMe();
  
  spaceship<test>(tvar1,tvar2); 
  


  std::vector<test> tvec{tvar1, tvar2, tvar3, tvar4, tvar5, tvar6, tvar7, tvar8};
  std::cout << " before sorting \n";
  for_each(begin(tvec), end(tvec), [](const test& t){t.printMe();});


  // sorts the vector based on the order the objects are defined in the class. 
  sort(begin(tvec), end(tvec));
  std::cout << "\n after sorting \n";
  for_each(begin(tvec), end(tvec), [](const test& t){t.printMe();});
  
  std::cout << " done! \n";
  return 0;
}
