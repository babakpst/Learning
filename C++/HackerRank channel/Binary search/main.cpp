

// Bindary search 
// Babak Poursartip

// Comments
/*
The array should already be sorted in ascending order.
*/


#include <iostream>
#include <ctime>
#include <cstdlib>

// binary search funciton 
int binarySearch(int array[], int size, int value){

  int low = 0;
  int high = size-1;

  int mid;


  while (low<=high){
  mid =(int)(low + high)/2;
    if (value == array[mid]){
      return mid;
    }else if (value > array[mid]){
      low = mid + 1;
    } else{
      high=mid-1;
    }
  }
return -1;
}

int main(){

std::cout << " This is the linear search algorithm ..." << "\n";

// Creating the array
int const sizeOfArray=100;

int array[sizeOfArray];

srand((unsigned)time(0));

for (int i=0; i<sizeOfArray; i++){ 
  //array[i]=(rand()%100)+1;
  array[i]=i;
  std::cout <<  " array "<<array[i] << "\n";
};

// sort 



int userValue;

std::cout << " Enter the value:" << "\n";
std::cin >> userValue;

int result = binarySearch(array, 100, userValue);


if (result >=0){
std::cout << " The number found at " << result << "\n";
} 
else
{
std::cout << " The number was not found " << "\n";
}

std::cout << "End of the code!" << "\n";

}