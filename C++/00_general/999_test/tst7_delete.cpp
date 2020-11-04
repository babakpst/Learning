
// delete

#include <iostream>

int main(){
std::cout << " starts \n";
char *str = new char[20];

// delete str[];    // no
// delete str[20];  // no
// delete *str;     // no
//delete char* str;
delete[] str;

std::cout << " done \n";
return 0;
}
