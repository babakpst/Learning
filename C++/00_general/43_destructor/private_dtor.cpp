
#include <iostream>

/*
If the destructor is private, object instantiation is not possible (class obj; compile error). Only dynamic objects of that class can be created (class *obj=new class;). Thus, it can only create it on the heap.
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

//base obj; // compile error, since it cannot 

//fine. When something is created using dynamic memory allocation, it is programmer’s responsibility to delete it.
base *obj = new base;

//delete obj; // compile error

destructor(obj);

std::cout << " ends \n";
return 0;
}
