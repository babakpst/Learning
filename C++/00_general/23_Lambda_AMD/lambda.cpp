
#include <iostream>
#include <vector>
#include <algorithm>


class Person
{
  private:
    std::string name;
    std::vector<double> values;
  public:
    Person(std::string name, std::vector<double> vec):name{name}, values{vec}{};

    bool operator<(const Person& p2) const
    {
      return this->name<p2.getName();
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


int main()
{

std::cout << " starts ... \n";

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
std::cout << " \n after sorting: \n";
std::for_each (begin(coll), end(coll), [](Person temp){temp.printPerson();});


sort(begin(coll), end(coll), [](const Person p1, const Person p2){return p1.getName()>p2.getName();});
std::cout << " \n after sorting: \n";
std::for_each (begin(coll), end(coll), [](Person temp){temp.printPerson();});


std::cout << " Done. \n";
return 0;
}
