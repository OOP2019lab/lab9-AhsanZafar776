#include <iostream>
#include "Address.h"
#include "Project.h"

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
	char* emp_name; 
	Address emp_ad;
	Project ** emp_pro;
	int projects;
	//Add Data Members here
	
public:
	Employee(char* name, const Address&);
	//overloaded constructor
	Employee(const Employee&);
	//copy constructor
	friend ostream& operator<<(ostream& osObject, const Employee&);
	//overloaded insertion operator
	const Employee &   operator=(const Employee& other);
	//overloaded assignment operator

	void addProject(Project const * );
	void removeProject(Project const * ); 

	~Employee();

}; 
#endif