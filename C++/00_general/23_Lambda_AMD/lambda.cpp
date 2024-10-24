
// Babak Poursartip
// g++ lambda.cpp -o lambda

#include <iostream>
#include <vector>
#include <algorithm>
//#include <sstream>
#include <iterator>

// approach 1: using member function ==========================================
class Person
{
  private:
    std::string name;
    std::vector<double> values;
  public:
    Person(std::string name, std::vector<double> vec):name{name}, values{vec}{};

    bool operator<(const Person& p2) const
    {
    std::string newName=p2.getName();
    //if (name != newName)
      return (name < newName);
    }

    void setName(std::string newName){name=newName;}

    void setVector(std::vector<double> newVec){values=newVec;}

    std::string getName() const {return name;}
    //std::string getName() {return name;}

    void printPerson()
    {
      std::cout<< " name: " << name << std::endl << " vector: ";
      for_each(begin(values), end(values), [](double x){std::cout << x << " ";});
      std::cout << std::endl;
    }
};


// approach 2: using member function ==========================================
class Person2
{
  private:
    std::string name;
    std::vector<double> values;
  public:
    Person2(std::string name, std::vector<double> vec):name{name}, values{vec}{};

    void setName(std::string newName){name=newName;}

    void setVector(std::vector<double> newVec){values=newVec;}

    std::string getName() const {return name;}
    //std::string getName() {return name;}

    void printPerson()
    {
      std::cout<< " name: " << name << std::endl << " vector: ";
      for_each(begin(values), end(values), [](double x){std::cout << x << " ";});
      std::cout << std::endl;
    }

    friend bool operator<(const Person2& p1, const Person2& p2) noexcept;
};

bool operator<(const Person2& p1, const Person2& p2) noexcept
{
  return (p1.getName() < p2.getName());
}


// approach 3: having two functions to define the <. Good when you want to sort using different criterion =============
class Person3
{
  private:
    std::string name;
    int id;
  public:
    Person3(std::string name, int id):name{name}, id{id}{};

    void setName(std::string newName){name=newName;}

    void setID(int newId){id=newId;}

    std::string getName() const {return name;}
    int getId() const {return id;}

    void printPerson()
    {
      std::cout<< " name: " << name << " id: " << id << std::endl;
    }
};

bool lessName(const Person3& p1, const Person3& p2)
{
return p1.getName() < p2.getName();
}

bool lessID(const Person3& p1, const Person3& p2)
{
return p1.getId() < p2.getId();
}



// Lambda's can be passed around. ==============================
// This funciton returns a lambda
auto TaxFunction(const int& taxBracket)
{
double tax = taxBracket<10?0.2:0.25;
return [tax](const double& d){return d*(1+tax);};
}




// =============================================================
// =============================================================
// =============================================================
int main()
{

std::cout << " starts ... \n";

std::cout << "\n\n"
          << "==================================================\n"
          << "===== topic 1: lambda vs func & friends  =========\n"
          << "==================================================\n";
// approach 1 ======================
std::cout << "\n\n approach 1 =========\n";
std::vector<Person> coll;

Person temp("babak",std::vector<double>{1.1,1.2});
//temp.name = "babak";
//temp.value = std::vector<double>{1.1,1.2};

coll.push_back(temp);

temp.setName("shiva");
temp.setVector(std::vector<double>{2.1,2.2,3.5});
coll.push_back(temp);


temp.setName("behnaz");
temp.setVector(std::vector<double>{2.1,2.2,3.5,5.5});
coll.push_back(temp);

temp.setName("hed");
temp.setVector(std::vector<double>{2.1,5.2});
coll.push_back(temp);

std::for_each (begin(coll), end(coll), [](Person temp){temp.printPerson();});


sort(begin(coll), end(coll));
// sorting based on the member function is inferior vs lambda function, bcs, - we need to also define <=, ==, - exception may happen, - implicit type conversion for the first operand
std::cout << " \n after sorting with member function: \n";
std::for_each (begin(coll), end(coll), [](Person temp){temp.printPerson();});


// using lambda:
// lambda, is a local function that does not need a name, can use reference, and auto
//sort(begin(coll), end(coll), [](const Person &p1, const Person &p2){return p1.getName()>p2.getName();});
sort(begin(coll), end(coll), [](const auto &p1, const auto &p2){return p1.getName()>p2.getName();});
std::cout << " \n after sorting with lambda: \n";
std::for_each (begin(coll), end(coll), [](Person temp){temp.printPerson();});


// approach 2 ==========================
std::cout << "\n\n approach 2  =========\n";

std::vector<Person2> coll2;

Person2 temp2("babak",std::vector<double>{1.1,1.2});
//temp.name = "babak";
//temp.value = std::vector<double>{1.1,1.2};

coll2.push_back(temp2);

temp2.setName("shiva");
temp2.setVector(std::vector<double>{2.1,2.2,3.5});
coll2.push_back(temp2);


temp2.setName("behnaz");
temp2.setVector(std::vector<double>{2.1,2.2,3.5,5.5});
coll2.push_back(temp2);

temp2.setName("hed");
temp2.setVector(std::vector<double>{2.1,5.2});
coll2.push_back(temp2);

std::for_each (begin(coll2), end(coll2), [](Person2 temp){temp.printPerson();});

sort(begin(coll2), end(coll2));
std::cout << " \n after sorting with member function: \n";
std::for_each (begin(coll2), end(coll2), [](Person2 temp){temp.printPerson();});


// approach 3 ==========================
std::cout << "\n\n approach 3  =========\n";
std::vector<Person3> coll3;

Person3 temp3("babak", 5);
//temp.name = "babak";
//temp.value = std::vector<double>{1.1,1.2};

coll3.push_back(temp3);

temp3.setName("shiva");
temp3.setID(1);
coll3.push_back(temp3);

temp3.setName("behnaz");
temp3.setID(10);
coll3.push_back(temp3);

temp3.setName("hed");
temp3.setID(7);
coll3.push_back(temp3);

std::for_each (begin(coll3), end(coll3), [](Person3 temp){temp.printPerson();});

// for the sort criterion, we can define a function or lambda
// drawbacks of functions: 1- you cannot define func inside a local scope, 2- func requires a good name, 3- we may change the func but not name (becomes ambiguous). But lambda, is a local function that does not need a name.
std::cout << "\n lessName \n";
sort(begin(coll3), end(coll3), lessName);
std::for_each (begin(coll3), end(coll3), [](Person3 temp){temp.printPerson();});

std::cout << "\n lessID \n";
sort(begin(coll3), end(coll3), lessID);
std::for_each (begin(coll3), end(coll3), [](Person3 temp){temp.printPerson();});


std::cout << "\n\n"
          << "==================================================\n"
          << "===== topic 2: using lambda multiple times  ======\n"
          << "==================================================\n";
// Lambda is a function object: only valid in this scope, because it is an object that can be used like a function.
// this is a named lambda (we can define a function instead), 
auto isOdd = [](auto &i){return i%2!=0;};

std::vector<int> vec1{4,2,3,-1,9,5,8,-6,10};


int num = std::count_if(begin(vec1), end(vec1), isOdd);
std::cout << " num. of odds: " << num << std::endl;

auto pos = std::find_if(begin(vec1), end(vec1), isOdd);
if (pos!=end(vec1))
  std::cout <<" first odd: " << *pos << " at " << std::distance(begin(vec1),pos) << std::endl;


// generic lambda function: valid for any type where + is defined
auto twice = [](const auto& x){return x+x;};

auto i = twice(3); // i is int
auto d = twice(1.7); // d is double
auto s = twice(std::string{"hi"}); // s is string
//auto t = twice("hi");  // ERROR: const char[3] + const char[3]

std::transform(begin(vec1), end(vec1), begin(vec1), twice);
std::for_each(begin(vec1), end(vec1), [](auto& i){std::cout<< i << " ";});
std::cout<< std::endl;

std::vector<std::string> vec2{"am", "Babak", "Shiva", "great", "work", "Money", "Austin"};
std::sort(begin(vec2), end(vec2));
std::for_each(begin(vec2), end(vec2), [](auto& i){std::cout<< i << " ";});
std::cout<< std::endl;

std::sort(begin(vec2), end(vec2),
          [](const std::string& s1, const std::string& s2)
          {
            return std::lexicographical_compare(s1.begin(), s1.end(),
                                                s2.begin(), s2.end(),
                                                [] (char c1, char c2) 
                                                   {
                                                     return std::toupper(c1) < std::toupper(c2);
                                                   });
          });

std::for_each(begin(vec2), end(vec2), [](auto& i){std::cout<< i << " ";});
std::cout<< std::endl;


std::cout << "\n\n"
          << "==================================================\n"
          << "===== topic 3: passing parameters to lambda ======\n"
          << "==================================================\n";

// capture behavior, lambda's can get parameters.
std::vector<int> vec3{1,2,8,52,62,12,45,85,12,5,3,7,35};

int max = 29;
//int nums = std::count_if(begin(vec3), end(vec3), [&max](int v){return v<max ;} );
int nums = std::count_if(begin(vec3), end(vec3), [&max](const auto& v){return v<max ;} );
std::cout << " element < " << max << ": " << nums << std::endl;


// Lambda's can be passed around.
const int bracket1=5, bracket2=15;
auto T1 = TaxFunction(bracket1);
auto T2 = TaxFunction(bracket2);

std::cout << T1(12) << std::endl;
std::cout << T2(12) << std::endl;


std::cout << "\n\n"
          << "==================================================\n"
          << "===== topic 4: return type of lambda =============\n"
          << "==================================================\n";

// If we have multiple returns in lambda, they should be of the same type, or we should explicitly define the return value.  
/*
auto ld1 = [](long val) {   // error: inconsistent types ‘long int’ and ‘int’ deduced for lambda return type
           if (val < 10) {
             return val;
             }
           return 10;
           };
*/

auto ld2 = [](long val) -> long {  
           if (val < 10) {
             return val;
             }
           return 10;
           };

// The return value is passed by value. If you want to return a reference with lambda use: ->type& (->auto&  or  -> decltype(v)&) 
long rv;
auto ld3 = [&rv](long val) -> long& {  
           if (val < 10) {
             rv = val;
             }
             else
             rv = 10;
           return rv;
           };

long myL1=12;
long myL2=8;

std::cout << ld3(myL1) << " " << ld3(myL2) << std::endl;

std::cout << "\n\n"
          << "==================================================\n"
          << "===== topic 5: stateless/stateful lambda =========\n"
          << "==================================================\n";
// Objects captured by value are read-only by default and their value cannot change. This behavior is need to make 
// lambda stateless (cannot change its behavior).  Otherwise, the function is stateful. "mutable" makes a lambda stateful.
//

// Note that prev has not been defined in the code. 
auto changed = [prev = 0](auto val) mutable // without mutable: error: assignment of read-only variable ‘prev’
{
  bool changed = prev!=val; 
  prev = val;
  return changed;
};

bool ch = changed(5); 
std::cout << std::boolalpha << ch << std::endl; // true
ch = changed(5); 
std::cout << std::boolalpha << ch << std::endl; // false

std::vector<int> vec4{7,42,42,0,3,3,7};

std::copy_if(vec4.begin(), vec4.end(), std::ostream_iterator<int>{std::cout, " "}, changed); // prints: 7, 42, 0, 3, 7
std::cout<< std::endl;

// changed is passed to the function by value, so even though the value of "prev" in the first changed is 7, in the following changed, it is 0. So it writes 7.
std::copy_if(vec4.begin(), vec4.end(), std::ostream_iterator<int>{std::cout, " "}, changed); // prints: 7, 42, 0, 3, 7
std::cout<< std::endl;

changed(7); // here the prev value is 7, so it does not print 7.
std::copy_if(vec4.begin(), vec4.end(), std::ostream_iterator<int>{std::cout, " "}, changed); // prints: 42, 0, 3, 7
std::cout<< std::endl;

std::cout << " Done. \n";
return 0;
}



