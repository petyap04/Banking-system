#include "../../Tasks/h/Close_task.h"

//std::istream& operator>>(std::istream& ifs, Close_task* task)
//{
//    operator>>(ifs, static_cast<Task*>(task));
//    ifs >> task->account;
//    return ifs;
//}
//
//std::ostream& operator<<(std::ostream& ofs, const Close_task* task)
//{
//    operator<<(ofs, static_cast<const Task*>(task));
//    ofs << task->account << " ";
//    return ofs;
//}

Close_task::Close_task(Client* client, unsigned account): Task(client), account(account) {}

void Close_task::printTask() const
{
    std::cout << client->getFirstName() << " " << client->getSecondName() << "wants to close account with number: " << account << std::endl;
}

unsigned Close_task::getAccount() const
{
    return account;
}

Task* Close_task::clone() const
{
    return new Close_task(*this);
}
