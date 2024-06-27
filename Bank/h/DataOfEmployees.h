#pragma once
#include "../../Helpers/MyString.h"
#include "../../Helpers/Vector.hpp"
#include "DataOfEmployeeOfTheBank.h"

class DataOfEmployees
{
	Vector<DataOfEmployeeOfTheBank> employees;
public:
	int indexEmployeesWithThatName(const MyString& firstName, const MyString& secondName) const;
	void addEmployee(Employee* e);
	unsigned giveTaskToTheEmployeeWithTheLeastTasks(Task* task);//vrushta ind na taska
	friend class Bank;
};

