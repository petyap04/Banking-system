#include "../../Tasks/h/Task.h"


//std::istream& operator>>(std::istream& ifs, Task* task)
//{
//	unsigned number;
//	ifs >> task->indOfTask >> task->isApproved >> number;
//	if (number == 1) {
//		task->client = new Client();
//		return ifs >> task->client;
//	}
//	throw std::exception("Something went wrong with the file!");
//}
//
//std::ostream& operator<<(std::ostream& ofs, const Task* task)
//{
//	ofs << task->indOfTask << " " << task->isApproved << " " << 1 << " " << task->client;
//	return ofs;
//}

Task::Task(Client* client):client(client) {}

Task::Task(Client* client, unsigned indOfTask):client(client), indOfTask(indOfTask){}

void Task::sendMessageToClient(Message&& m)
{
	client->addMessage(std::move(m));
}

void Task::setApproval(bool ap)
{
	isApproved = ap;
}

void Task::setInd(unsigned ind)
{
	indOfTask = ind;
}

Client* Task::getClient() const
{
	return client;
}
