
/*

Babak Poursartip
05/02/2020

Bo Qian- Advaced c++: const

*/

#include <iostream>

class Dog{
    int age;
    std::string name;
  public:
    Dog(){age=3; name="Dummy";}
    // const parameter
    //void setAge(int &a){age=a;a++;}
    void setAge(const int &a){age=a;}

    // const return value
    const std::string &getName(){return name;}

    // will be called if Dog is not a const, next one will be called if Dog is const.
    void printDogName() {std::cout<< name << "non-constant function" << std::endl;};

    // const function: this func does not change any member values of this class
    void printDogName() const{std::cout<< name << "constant function" << std::endl;};

    // next line is an error because a const function should not change any members.
    //void printDogName() const{std::cout<< name << "constant function" << std::endl;age++;};

    // error bcs getName is not a const.
    //void printDogName() const{std::cout<< getName() << "constant function" << std::endl;};
};


// =================================
int main(){

std::cout << "------ The code starts ------ \n\n";

Dog d;

int i = 9;
d.setAge(i);

std::cout<< i << std::endl;

const std::string  & n = d.getName();

std::cout<<n<<std::endl;

d.printDogName();


const Dog d2;
d2.printDogName();

std::cout<< " \n ---- Finished successfully ----- \n";

return 0;
}
