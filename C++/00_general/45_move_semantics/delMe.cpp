

#include <iostream>

int main()
{

int *buffer;
int SIZE=20;
buffer = new int[SIZE]{};

buffer[0]=5;

std::cout << buffer[0] << std::endl;
std::cout << buffer[1] << std::endl;

return 0;
}
