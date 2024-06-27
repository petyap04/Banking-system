#pragma once
#include "Task.h"
#include <fstream>

class Change_task: public Task
{
	unsigned account;
	MyString oldBank;
	MyString newBank;
	bool hasBeenValidated = false;
public:
	Change_task() = default;
	Change_task(Client* client, unsigned account, const MyString& oldBank, const MyString& newBank);
	bool isTaskValid()const;
	void beenValidated();
	void printTask()const override;
	const MyString& getOldBank()const;
	const MyString& getNewBank()const;
	unsigned getAccount()const;

	/*friend std::ostream& operator<<(std::ostream& ofs, const Change_task* task);
	friend std::istream& operator>>(std::istream& ifs, Change_task* task);*/


	Task* clone()const;
	friend class ValidateCommand;
};

