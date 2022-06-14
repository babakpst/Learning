

// meaning of std::move(var) : I no longer need this var here. After move, var is still a valid var. 


#include <iostream>
#include <vector>
#include <algorithm>

std::string getData(){return "babak";}


void swap(auto& a, auto&b)
{
// variables are still valid after move and can be used later. 
auto temp = std::move(a);
a = std::move(b);
b = std::move(temp);
}



int main()
{

std::cout << " starts here ... \n";


std::cout << " 1 =====================\n";
std::string str{getData()};
std::cout << " str: " << str << " size: " << str.size() << std::endl;

std::vector<std::string> vec;

vec.push_back(str);
vec.push_back(std::move(str));

std::cout << " str: " << str << " size: " << str.size() << std::endl;

std::cout << " vector " << std::endl;
for_each(vec.begin(), vec.end(), [](auto x){std::cout<<x<<" ";});
std::cout << std::endl;

std::cout << " 2 =====================\n";
// move alone has no effects at all. 
str = getData();
std::cout << " str: " << str << " size: " << str.size() << std::endl;
std::move(str);
std::cout << " str: " << str << " size: " << str.size() << std::endl;
vec.push_back(str);
std::cout << " str: " << str << " size: " << str.size() << std::endl;


std::cout << " 3 =====================\n";

std::string a= "babak";
std::string b= "shiva";
std::cout << " a: " << a << " b: " << b << std::endl;
swap(a,b);
std::cout << " a: " << a << " b: " << b << std::endl;


std::cout << " done. \n";
return 0;
}



