  
#include "Resource.h"

int Resource::objectcount = 0;

Resource::Resource()
{	
std::cout << "create\n";
objectcount++;}

Resource::Resource(const Resource & r){	
std::cout << "copy\n";
  i = r.i;
	objectcount++;
}

Resource & Resource::operator=(const Resource & r)
{
std::cout << "assign\n";
	i = r.i;
	return *this;
}


Resource::~Resource(){
std::cout << "delete\n";
	objectcount--;
}
