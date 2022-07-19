

// meaning of std::move(var) : I no longer need this var here. After move, var is still a valid var. 


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


// ===========================================
std::string getData(){return "babak";}


// ===========================================
void swap(auto& a, auto&b)
{
// variables are still valid after move and can be used later. 
auto temp = std::move(a); // a is valid after move
a = std::move(b); 
b = std::move(temp);
}


// 4 ===========================================
class customer
{
private: 
  std::string first; // first name
  std::string last;  // last name- should never be empty. This condition may cause problem after the introcduction of move semantic in c++11.
  int val;  // this item will not move by the std::move
public:
  customer(const std::string& f, const std::string& l, int v): first{f}, last{l}, val{v}
  {
    assert(!last.empty());
  }


  // disabling generated move operations- These deletes prevents the use of std::move for this class. 
  // Additionally, we if we declare/define these, we need to declare copy ctor, otherwise, we cannot use push_back (rule of 5).
  //customer(customer&&) = delete;
  //customer& operator = (customer&&) = delete;
  // enabling copying
  customer(const customer&) = default; // if we define this but not defining the move ctor, it acts as copy.
  customer & operator = (const customer &) = default;

  void setLast(const std::string& l)
  {
    last = l;
    assert(!last.empty());
  }

  void printCustomer(){std::cout<< " customer: " << first << " " << last << ", age: " << val << std::endl;}

};


// 5 ===========================================
//void func(type& var )  // accepts only lvalue: var 
//void func(const type& var )  // accepts lvalue and rvalue: var or move(var)
//void func(type&& var )  // accepts only rvalue: move(var) or objects with no name.
//void func(const type&& var )  // works fine, but kind of rediculus, const type& covers this
void insertTwice(std::vector<std::string>& myVec, const std::string& str )  // accepts lvalue and rvalue: str or move(str)
{
  myVec.push_back(str);
  myVec.push_back(str);
  std::cout << " no move\n";
}


void insertTwice(std::vector<std::string>& myVec, std::string&& str )  // accepts lvalue and rvalue: str or move(str)
{
  myVec.push_back(str);
  myVec.push_back( std::move(str));
  std::cout << " move\n";
}


// 7 ===========================================
// To merge the previous two functions, we can use the template/forward method, which accepts lvalue and rvalues.
template <typename T>
void insertTwice2(std::vector<std::string> &myVec, T&& str)
{
  myVec.push_back(str);
  myVec.push_back( std::forward<T>(str));
  std::cout << " forward\n";  
}


// ===========================================
int main()
{

std::cout << " starts here ... \n";


std::cout << " 1 =====================\n";
std::string str{getData()};
std::cout << " str: " << str << " size: " << str.size() << std::endl; // size: 5

std::vector<std::string> vec;

vec.push_back(str);
vec.push_back(std::move(str));

std::cout << " str: " << str << " size: " << str.size() << std::endl; // size: 0

std::cout << " vector " << std::endl;
for_each(vec.begin(), vec.end(), [](auto x){std::cout<<x<<" ";});
std::cout << std::endl; //prints:  babak babak

std::cout << " 2 =====================\n";
// move alone has no effects at all. 
str = getData();
std::cout << " str: " << str << " size: " << str.size() << std::endl; // size: 5
std::move(str);
std::cout << " str: " << str << " size: " << str.size() << std::endl; // size: 5
vec.push_back(str);
std::cout << " str: " << str << " size: " << str.size() << std::endl; // size: 5


std::cout << " 3 =====================\n";
std::string a= "babak";
std::string b= "shiva";
std::cout << " a: " << a << " b: " << b << std::endl;
swap(a,b);
std::cout << " a: " << a << " b: " << b << std::endl;

std::cout << " 4 =====================\n";
// The codes that were valid before C++11 (when move semantic is introduced), might not be valid after C++11

customer p1{"Babak", "Poursartip", 1981};
p1.printCustomer();
//customer p2{"Babak", "", 1980}; // returns runtime error.

customer p3=std::move(p1); // even though the p1 last is empty it does not through an error
p1.printCustomer(); // prints: , age 1981- not that move does not apply to the int, bcs it is on the heap. 
p3.printCustomer();


std::vector<customer> coll;
coll.push_back(p1);

std::cout << " 5 =====================\n";
std::vector<std::string> myVec;
std::string myString="Babak";

std::cout << " Here is the string: " << myString << std::endl;

insertTwice(myVec, myString); // this will call the "no-move" insertTwice
std::cout << " vector: \n";
for_each(myVec.begin(), myVec.end(),  []( auto x ){ std::cout << x << " ";   });
std::cout << "\n";


insertTwice(myVec, std::move(myString)); // this will call the "move" insertTwice, if "move" does not exist, it calls the "no-move" function;
std::cout << " vector: \n";
for_each(myVec.begin(), myVec.end(),  []( auto x ){ std::cout << x << " ";   });
std::cout << "\n";

std::cout << " Here is the string: " << myString << std::endl;

std::cout << " 6 =====================\n";
// not useful commands though. 
int ii;
std::string s;
std::move(s) = "hello";  // can we have  move on the left side? yes, like lvalue. This is not valid for integral types.
//std::move(ii) = 23; // using rvalue as lvalue.
//auto sp = &std::move(s);   // can we get the address of move? no, bcs move is an rvalue. error: taking the address of an rvalue.

std::cout << " 7 =====================\n";
// Here we can use lvalue and rvalue simultaneously in one function with forward. 
std::vector<std::string> myVec2;
std::string myString2="Babak";

std::cout << " Here is the string: " << myString2 << std::endl;

insertTwice2(myVec2, myString2); 
std::cout << " vector: \n";
for_each(myVec2.begin(), myVec2.end(),  []( auto x ){ std::cout << x << " ";   });
std::cout << "\n";
std::cout << " Here is the string: " << myString2 << std::endl;

insertTwice2(myVec2, std::move(myString2));
std::cout << " vector: \n";
for_each(myVec2.begin(), myVec2.end(),  []( auto x ){ std::cout << x << " ";   });
std::cout << "\n";

std::cout << " Here is the string: " << myString2 << std::endl;



// =========================================
std::cout << " done. \n";
return 0;
}



























































