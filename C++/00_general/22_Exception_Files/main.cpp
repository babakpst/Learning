
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>

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
} catch(std::ifstream::failure &inputerr ){   // catch for opening the input file.
std::cout<<" Error while opening a file: "<< std::endl;
std::cout<<" The error message is: "<< inputerr.what() << std::endl;
}

// reading from the input file
int num;
std::vector<int> list;
InputFile >> num;
std::cout << " the num is: " << num << std::endl;
list.resize(num*2);
//std::ptrdiff_t index;
int index, index2;

/*
  for (std::vector<int>::iterator it=list.begin(); it!=list.end(); ++it){
    //std::cout << " reading.: " << it-list.begin() << "\n";
    index =it - list.begin();
    index2 = std::distance(list.begin(),it);
    std::cout << " reading: " << index << " " << index2 << "\n";
    //InputFile >> *it >> *(it+1);
    //std::cout << *it << " " << *(it+1) << "\n";
    InputFile >> *it;
    std::cout << *it << "\n";
  }
std::cout << "\n";
*/

  for (std::vector<int>::iterator it=list.begin(); it!=list.end(); it+=2){
    //std::cout << " reading.: " << it-list.begin() << "\n";
    index =it - list.begin();
    index2 = std::distance(list.begin(),it);
    std::cout << " reading: " << index << " " << index2 << "\n";
    InputFile >> *it >> *(it+1);
    std::cout << *it << " " << *(it+1) << "\n";
  }
std::cout << "\n";

// the vector
std::cout << "\n the input: \n";
  for (std::vector<int>::iterator it=list.begin(); it!=list.end(); ++it){
    //std::cout << " item no.: " << it-list.begin();
    std::cout << *it << " ";
    index =it - list.begin();
    if (index%2) std::cout << "\n";
  }


// create an output file
try{
  std::cout<<" Here is inside the Try for output "<< std::endl;
  OutputFile.open ("results.txt", std::ios::out );
  OutputFile << " This is the results file: " ;// >> std::endl;
  std::cout << " We just wrote something in the file." << std::endl;
}catch(std::ofstream::failure &writeerr){      // catch for the output file
  std::cout<<" Error while writing in the file: "<< std::endl;
  std::cout<<" The error message is: "<< writeerr.what() << std::endl;
}

return 0;
}




