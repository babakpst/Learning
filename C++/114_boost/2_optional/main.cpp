
/*

Babak Poursartip
12/16/2020

Reference: Boost
PluralSight

Boost.optional: provides a construct that explicitly tells us that a value is optional and may be missing.

*/
#include <iostream>
#include <string>

#include <boost/optional.hpp>

class Address{
public:
  std::string adr;
  Address(std::string adr):adr(adr){}
};

class person{
public:
  std::string firstName, lastName;
  boost::optional<std::string> middleName;
  boost::optional<Address> address;
  
  person(std::string firstName, std::string lastName):firstName(firstName), lastName(lastName){}
};


int main(){

std::cout << " starts here ...\n";

person p("babak", "poursartip");

std::cout << p.firstName << " " << p.lastName << std::endl;

if (p.middleName)
std::cout << p.firstName << " " << *p.middleName << " " << p.lastName << std::endl;

p.middleName = "Shiva";
if (p.middleName)
std::cout << p.firstName << " " << *p.middleName << " " << p.lastName << std::endl;

p.address = Address("Morado Cv");

if (p.address)
std::cout << p.address->adr << std::endl;


std::cout << " finished.\n";

return 0;
}
