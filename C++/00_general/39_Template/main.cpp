
//


#include <iostream>

using namespace std;


// ==================================
template<typename T1>
class calc_cls{
  private:
    T1 var1, results;
  public:
    calc_cls(T1);
    T1 square_func();
};

template<typename T1>
calc_cls<T1>::calc_cls(T1 var1):var1(var1){
  cout<< " Yes, we are inside the constructor!" << endl;
  cout<< " The value of the variable is: " << var1 << endl;
}

template<typename T1>
T1 calc_cls<T1>::square_func(){ 
  results= var1*var1;
  return results;
}
// ==================================

// ========================================
// class ==================================
template<typename T=int, typename K=double> 
class myClass{
private:
  T ivar;
  K dvar;
public:
  myClass(T ivar, K dvar):ivar(ivar),dvar(dvar){ 
    cout << " constructor \n"; 
    cout << "ivar: " << ivar << " dvar: " << dvar << endl;
  }
};


//=======================================
// Function =============================
template<typename T>
T sum(const T &a, const T &b){return (a+b);}

//non-type template
template<int incl>
int sum2(const int &a, const int &b){return (a+b+incl);}

template<typename T, int incl>
T sum3(const T &a, const T &b){return (a+b+incl);}


//=======================================
//=======================================
int main(){

cout<< " OK, Lets get started:" << endl;

cout << "\n1-----------------\n";
calc_cls<double> object1(3.1);
cout << " The suqare of the number is: " << object1.square_func() << endl;

calc_cls<int> object2(3);
cout << " The suqare of the number is: " << object2.square_func()  << endl;

calc_cls<int> object3(3.1);
cout << " The suqare of the number is: " << object3.square_func()  << endl;


cout << "\n2-----------------\n";
myClass<int,double> o1(5,5.1);
myClass<> o2(5,5.1); // this <> should be here, otherwise it is an error.
myClass<int> o3(5.1,5.1); // assume this for the first typename t

cout << "\n3-----------------\n";
cout << sum(5,6) << endl;
//cout << sum(5.1,6) << endl; // error, it cannot take the type
cout << sum<int>(5,6) << endl;
cout << sum<int>(5.1,6) << endl; // ok

cout << sum2<6>(5,6) << endl; // ok
//cout << sum2<6.5>(5,6) << endl; // error, this is not an int.

cout << sum3<int, 6>(5,6) << endl; // ok
cout << sum3<int, 6>(5.5,6) << endl; // ok


cout << "-----------------\n";
return 0;
}



