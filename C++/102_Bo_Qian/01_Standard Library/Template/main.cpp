
#include <iostream>


/*
int square(int x){
    return x*x;
  }

double square(double x){
    return x*x;
  }
*/

template<typename T1>
T1 square(T1 x){return x*x;}


template<typename T1>
class BobVector{

  private:
    T1 arr[1000];
    int size;

  public:
    BobVector():size(0){}     // initialize the size equal to zero.
    
    void push(T1 x){
      arr[size] = x;
      size++;
    }

    T1 get(int i) const { return arr[i]; }
    int getSize() const {return size;}
    void print() const { 
      for (int i =0; i<size; i++){
        std::cout << arr[i] << std::endl;
      };
     }
};


template<typename T1>
BobVector<T1> operator*(const BobVector<T1>& rhs1, const BobVector<T1>& rhs2){
  BobVector<T1> res;
  for (int i = 0; i<rhs1.getSize(); i++){
    res.push(rhs1.get(i)*rhs2.get(i));
  }
  return res;
}


int main(){

  std::cout << " Square of a number: " << std::endl << std::endl;

  std::cout << square<int>(5) << std::endl;
  std::cout << square<double>(5.5) << std::endl;
  
  std::cout << square(5) << std::endl;
  std::cout << square(5.5) << std::endl;

  BobVector<int> vector1;
  vector1.push(2);
  vector1.push(5);
  vector1.push(8);
  vector1.push(9);

  vector1.print();
  
  std::cout << std::endl;

  // print the squared of the vector
  vector1 = square(vector1);
  vector1.print();
  
  // code bloat

  return 0;
}



