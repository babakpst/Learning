#pragma once
#include <string>

class Employee
{
public:
	Employee(std::string first, std::string last, int sal) :
		firstname(first), lastname(last), salary(sal) {}

	int getSalary() { return salary; }
	std::string getSortingName() { return lastname + ", " + firstname; }

private:
	std::string firstname;
	std::string lastname;
	int salary;

};

