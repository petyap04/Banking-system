#include "../h/DataOfEmployeeOfTheBank.h"

DataOfEmployeeOfTheBank::DataOfEmployeeOfTheBank(Employee* employee) 
{
	this->employee = employee;
}

const Employee* DataOfEmployeeOfTheBank::getEmployee() const
{
	return employee;
}

unsigned DataOfEmployeeOfTheBank::countOfTasks() const
{
	return employee->getCountOfTasks();
}

void DataOfEmployeeOfTheBank::addTask(Task* task)
{
	employee->addTask(task);
}
