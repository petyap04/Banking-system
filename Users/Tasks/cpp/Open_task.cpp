#include "../../Tasks/h/Open_task.h"

Open_task::Open_task(Client* client):Task(client){}

//std::istream& operator>>(std::istream& ifs, Open_task* task)
//{
//   operator>>(ifs, static_cast<Task*>(task));
//   return ifs;
//}
//
//std::ostream& operator<<(std::ostream& ofs, const Open_task* task)
//{
//    operator<<(ofs, static_cast<const Task*>(task));
//    return ofs;
//}

void Open_task::printTask() const
{
    std::cout << client->getFirstName() << " " << client->getSecondName() << "wants to open account" << std::endl;
}


Task* Open_task::clone() const
{
    return new Open_task(*this);
}
