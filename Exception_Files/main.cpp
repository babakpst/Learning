
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

//=======================================
int main(){

std::ifstream InputFile;
InputFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

std::ofstream OutputFile;
OutputFile.exceptions (std::ofstream::failbit | std::ofstream::badbit);
//OutputFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

std::cout<< " OK, Lets get started:" << std::endl;

try{

std::cout<<" Here is inside the Try "<< std::endl;

InputFile.open  ("address.txt", std::ios::in );

OutputFile.open ("/zzzzf/results.txt", std::ios::out );

OutputFile << " This is the results file: " ;// >> std::endl;
std::cout << " We just wrote something in the file." << std::endl;

}
catch(std::ifstream::failure &inputerr ){   // here is the catch for opening the input file.
std::cout<<" Error while opening a file: "<< std::endl;
std::cout<<" The error message is: "<< inputerr.what() << std::endl;
}
catch(std::ofstream::failure &writeerr){      // here is the catch for 
std::cout<<" Error while writing in the file: "<< std::endl;
std::cout<<" The error message is: "<< writeerr.what() << std::endl;
}


return 0;
}




