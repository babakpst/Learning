
/*

Babak Poursartip
12/30/2020

Reference: Boost
PluralSight

boost::any
- can contain values of any type,
- values are stored as they are,
- Can be used in collections.

prototype
boost::any<T>
T can be anything, but must be copy-constructable.

vector<any> y{42,"life"}

Query
empty()
type()

any_cast,

*/
#include <iostream>
#include <boost/any.hpp>
#include <vector>

int main(){

std::cout << " starts here ...\n";

boost::any w;
boost::any x{3.0};
std::vector<boost::any> a{12, "babak"};

//std::cout << a[0] << " " << a[1] << std::endl;

boost::any b = std::string("shiva");

if (!x.empty()) std::cout << x.type().name() << std::endl;

int first  = boost::any_cast<int>(a[0]);
std::cout << first << std::endl;

try{
int second  = boost::any_cast<int>(a[1]);
std::cout << second << std::endl;
}catch(const boost::bad_any_cast& e){
std::cout << "wrong type" << std::endl;
}


for (auto c: a) 
{
  int  *val = boost::any_cast<int>(&c);
  if (val != nullptr) 
  std::cout << *val << std::endl;
  
  const char **txt = boost::any_cast<const char*>(&c);
  if (txt!=nullptr) 
    std::cout << *txt << std::endl;
}

std::cout << " finished.\n";

return 0;
}
