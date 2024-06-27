#pragma once
#include "../CommandFromClient.h"
#include "../../Users/Tasks/h/Close_task.h"

class CloseAccountCommand: public CommandFromClient
{
private:
	MyString nameOfTheBank;
	unsigned accountNumber;
public:
	CloseAccountCommand(const MyString& nameOfTheBank, unsigned accountNumber);
	void execute()override;
	virtual Command* clone() const;
};

