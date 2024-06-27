#pragma once
#include "Task.h"
#include <iostream>
#include <fstream>

class Open_task:public Task
{
public:
	Open_task() = default;
	Open_task(Client* client);
	/*friend std::istream& operator>>(std::istream& ifs, Open_task* task);
	friend std::ostream& operator<<(std::ostream& ofs, const Open_task* task);*/
	void printTask()const override;

	Task* clone()const;
};

