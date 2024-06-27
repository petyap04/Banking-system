#pragma once
#include "User.h"
#include "../Tasks/h/Task.h"
#include "../../Helpers/Polymorphic_Ptr.hpp"
#include "../../Helpers/Vector.hpp"

class Employee: public User
{
private:
	MyString nameOfTheBank;
	Vector<Polymorphic_Ptr<Task>> tasks;
public:
	Employee() = default;
	Employee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password, const char* nameOfTheBank);
	void addTask(Task* task);
	Task* getTask(unsigned ind);
	unsigned getCountOfTasks()const;
	void printTasks()const;
	void printTaskAtIndex(unsigned ind)const;
	void theTaskHasBeenDone(unsigned ind);

	//friend std::istream& operator>>(std::istream& ifs, Employee* employee);
	//friend std::ostream& operator<<(std::ostream& ofs, const Employee* employee);

	User* clone()const;
	friend class DataOfEmployeeOfTheBank;
};


