
#include <iostream>
#include <vector>
#include <algorithm>


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

// =============================================================
// =============================================================
// =============================================================
int main()
{

std::cout << " starts ... \n";


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


sort(begin(coll), end(coll), [](const Person p1, const Person p2){return p1.getName()>p2.getName();});
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

std::cout << "\n lessName \n";
sort(begin(coll3), end(coll3), lessName);
std::for_each (begin(coll3), end(coll3), [](Person3 temp){temp.printPerson();});

std::cout << "\n lessID \n";
sort(begin(coll3), end(coll3), lessID);
std::for_each (begin(coll3), end(coll3), [](Person3 temp){temp.printPerson();});

std::cout << " Done. \n";
return 0;
}



