#include "../h/Employee.h"

Employee::Employee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password, const char* nameOfTheBank) :
                   User(firstName, secondName, IDNumber, age, password), nameOfTheBank(nameOfTheBank) {}

void Employee::addTask(Task* task)
{
    tasks.pushBack(task);
}

Task* Employee::getTask(unsigned ind)
{
    return tasks[ind].get();
}

User* Employee::clone() const
{
    return new Employee(*this);
}

unsigned Employee::getCountOfTasks() const
{
    return tasks.getSize();
}

void Employee::printTasks() const
{
    for (int i = 0; i < tasks.getSize(); i++) {
        tasks[i].get()->printTask();
    }
}

void Employee::printTaskAtIndex(unsigned ind) const
{
    if (ind < tasks.getSize()) {
        tasks[ind].get()->printTask();
    }
    throw std::out_of_range("The index is out of range!");
}

void Employee::theTaskHasBeenDone(unsigned ind)
{
    for (int i = ind; i < tasks.getSize() - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    tasks.popBack();
}

//std::istream& operator>>(std::istream& ifs, Employee* employee)
//{
//    operator>>(ifs, static_cast<User*>(employee));
//    ifs >> employee->nameOfTheBank;
//    ifs >> employee->tasks;
//    return ifs;
//}
//
//std::ostream& operator<<(std::ostream& ofs, const Employee* employee)
//{
//    operator<<(ofs, static_cast<const User*>(employee));
//    ofs << employee->nameOfTheBank;
//    ofs << employee->tasks;
//    return ofs;
//}
