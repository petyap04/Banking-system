#pragma once
#include <iostream>
#include <fstream>
#include "../../h/Client.h"
#include "../../h/Message.h"

class Task
{
protected:
	unsigned indOfTask;
	bool isApproved = false;
	Client* client;
public:
	Task() = default;
	Task(Client* client);
	Task(Client* client, unsigned indOfTask);
	/*friend std::istream& operator>>(std::istream& ifs, Task* task);
	friend std::ostream& operator<<(std::ostream& ofs, const Task* task);*/
	virtual void printTask()const = 0;
	void sendMessageToClient(Message&& m);
	void setApproval(bool ap);
	void setInd(unsigned ind);
	Client* getClient()const;

	virtual Task* clone()const = 0;
	virtual ~Task() = default;
};

