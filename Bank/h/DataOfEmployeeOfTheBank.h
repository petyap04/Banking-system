#pragma once
#include "../../Users/h/Employee.h"
class DataOfEmployeeOfTheBank
{
	Employee* employee;
public:
	DataOfEmployeeOfTheBank() = default;
	DataOfEmployeeOfTheBank(Employee* employee);
	const Employee* getEmployee()const;
	unsigned countOfTasks()const;
	void addTask(Task* task);
	friend class Employee;
};

