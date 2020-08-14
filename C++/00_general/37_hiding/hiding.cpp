#include <iostream>

int main(){


  std::cout<<"code starts... \n";

  int a=0;
  std::cout<<"a1: "<<a<<"\n";
    {
      a = 1;
      int a;
      a = 2;
      std::cout << "a2: " << a << "\n";

      {
        a = 3;
        std::cout << "a2 again: " << a << "\n";
      }

    }

      std::cout << "a1 again: " << a << "\n";
    

  std::cout << " code ends. \n";
  return 0;
}

