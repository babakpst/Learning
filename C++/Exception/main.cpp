
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


//=======================================
int main(){

std::ifstream InputFile;

std::cout<< " OK, Lets get started:" << std::endl;

try{

std::cout<<" Here is inside the Try "<< std::endl;

InputFile.open ("address.txt", std::ios::in );

//throw 20;
std::cout<<" Here is inside the Try, but after throw "<< std::endl;

}
catch(int pp){
std::cout<<" Here is inside the catch"<< std::endl;
std::cout<<" The number is "<< pp<< std::endl;
}
catch(...){ 
std::cout<<" Cannot find the input file"<< std::endl;
}


return 0;
}



