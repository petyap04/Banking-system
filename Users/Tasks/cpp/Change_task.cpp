#include "../../Tasks/h/Change_task.h"

//std::ostream& operator<<(std::ostream& ofs, const Change_task* task)
//{
//    operator<<(ofs, static_cast<const Task*>(task));
//    return ofs << task->account << " " << task->oldBank << " " << task->newBank << " " << task->hasBeenValidated << " ";
//}
//
//std::istream& operator>>(std::istream& ifs, Change_task* task)
//{
//    operator>>(ifs, static_cast<Task*>(task));
//    return ifs >> task->account >> task->oldBank >> task->newBank >> task->hasBeenValidated;
//}

Change_task::Change_task(Client* client, unsigned account, const MyString& oldBank, const MyString& newBank): 
             Task(client), account(account), oldBank(oldBank), newBank(newBank){}

bool Change_task::isTaskValid() const
{
    return true;
}

void Change_task::beenValidated()
{
    this->hasBeenValidated = true;
}

void Change_task::printTask() const
{
    std::cout << client->getFirstName() << " " << client->getSecondName() << "wants to change account with number: " << account;
    std::cout << " to " << newBank;
}

const MyString& Change_task::getOldBank() const
{
    return oldBank;
}

const MyString& Change_task::getNewBank() const
{
    return newBank;
}

unsigned Change_task::getAccount() const
{
    return account;
}


Task* Change_task::clone() const
{
    return new Change_task(*this);
}
