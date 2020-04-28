
// constructing vectors
#include <iostream>


int main ()
{
int vector[100];

for(unsigned int i=0; i<100; i++)
{
vector[i] = 2* i;
};

for(unsigned int i=0; i<100; i++)
{
//std::cout << "here it is: " << vector[i] << std::endl;
//std::cout << "here it is: " << vector[i]; // << "\n";
std::cout << "here it is: " << vector[i] << "\n";
};


  return 0;
}
