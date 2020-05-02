
/*
Babak Poursartip

Modifying algorithms:
Algorithms that change the value of an object: copy, move, transform, swap, fill, replace, remove

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(){

  std::cout << " Code starts here: " << std::endl;

  std::vector<int> vec={9, 60, 70, 8, 45, 87, 90};
  std::vector<int> vec2={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  std::vector<int> vec3;

  std::vector<int> :: iterator itr, itr2;
  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pair_of_itr;


  // copy ---------------------------------------------------
  copy(vec.begin(), vec.end(),   // source
       vec2.begin() );           // destination


  std::cout << " print the vec, copy: " << std::endl;
    for (std::vector<int>:: iterator itr=vec.begin(); itr!=vec.end(); ++itr ){
      std::cout<< *itr << " ";
    }
  std::cout << std::endl;

    for (std::vector<int>:: iterator itr=vec2.begin(); itr!=vec2.end(); ++itr ){
      std::cout<< *itr << " ";
    }
  std::cout << std::endl;

  vec3 = vec;

    for (std::vector<int>:: iterator itr=vec3.begin(); itr!=vec3.end(); ++itr ){
      std::cout<< *itr << " ";
    }
  std::cout << std::endl;

  
  
  copy_if(vec.begin(), vec.end(),  // source
          vec2.begin(),            // destination
          [](int x){return x>80;}  );                     // condition

  std::cout << " copy_if: " << std::endl;
    for (std::vector<int>:: iterator itr=vec2.begin(); itr!=vec2.end(); ++itr ){
      std::cout<< *itr << " ";
    }
  std::cout << std::endl;


  vec2={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};;;
  // copies n element from a vector to another
  copy_n(vec.begin(), 4,  // source
        vec2.begin());

  std::cout << " copy_n: " << std::endl;
    for (std::vector<int>:: iterator itr=vec2.begin(); itr!=vec2.end(); ++itr ){
      std::cout<< *itr << " ";
    }
  std::cout << std::endl;


  vec2={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};;;
  // copy backward, from the the other side of the vector
  copy_backward(vec.begin(), vec.end(),  // source
        vec2.end()-1);                   // destination, careful

  std::cout << " copy_backward: " << std::endl;
    for (std::vector<int>:: iterator itr=vec2.begin(); itr!=vec2.end(); ++itr ){
      std::cout<< *itr << " ";
    }
  std::cout << std::endl;




  std::cout << std::endl <<  " end of the code! " << std::endl;
  return 0;
}