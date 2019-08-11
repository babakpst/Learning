

// Lineaer search 
// Babak Poursartip

// Comments
/*
This is code is based on the following youtube clip: https://www.youtube.com/watch?v=FYX_yG-9CxE
There is no precondition in the array itself.
Compares each element in sequence.
Worst case we have to search all the elements in the array. 
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

int LinearSearch (int array[], int size, int value){

  for (int i = 0; i< size; i++){
    if (array[i]==value) {
      return i;
    }

  }

  return -1;
}


int main(){

std::cout << " This is the linear search algorithm..." << "\n";

// Creating the array
int const sizeOfArray=100;

int array[sizeOfArray];

std::srand((unsigned)time(0));

for (int i=0; i<sizeOfArray; i++){ 
  array[i]=(rand()%100)+1;
  std::cout <<  " array "<< i << " : "<< array[i] << "\n";
};

int userValue;

std::cout << " Enter a number: " << "\n";
std::cin  >> userValue;

int result = LinearSearch(array, sizeOfArray, userValue);

if (result >=0) {
  std::cout << " The number found at " << result << "\n";
}
else{
  std::cout << " The number was not found in the array " <<  "\n";
}

std::cout << "End of the code!" << "\n";

}