
#include <iostream>

/*
when a class has private destructur, only dynamic objects of that class can be created.
*/

class base
{
public:
friend void destructor(base *);


private:
~base()
{
std::cout << " dtor \n";
}

};

void destructor(base *ptr)
{
delete ptr;
}


int main()
{
std::cout << " starts ...\n";

//base obj; // compile error: std::cout << " starts .../n';

//fine. When something is created using dynamic memory allocation, it is programmer’s responsibility to delete it.
base *obj = new base;

//delete obj; // compile error: std::cout << " starts .../n';

destructor(obj);

std::cout << " ends \n";
return 0;
}
