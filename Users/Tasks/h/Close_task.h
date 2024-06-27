#pragma once
#include "Task.h"
#include <iostream>
#include <fstream>

class Close_task:public Task
{
private:
	unsigned account;
public:
	Close_task() = default;
	Close_task(Client* client, unsigned account);
	//friend std::istream& operator>>(std::istream& ifs, Close_task* task);
	//friend std::ostream& operator<<(std::ostream& ofs, const Close_task* task);
	void printTask()const override;
	unsigned getAccount()const;
	Task* clone()const;
};

