

#include <iostream>

#pragma once

class employee{

private:
  std::string firstname;
  std::string lastname;
  int salary;

public:
  employee(std::string lastname, std::string firstname, int salary):
           firstname(firstname), lastname(lastname), salary(salary){}
  
  int getSalary(){ return salary;}
  std::string getName(){return lastname + ", " + firstname;}
  
};
