#pragma once
#include "../CommandFromClient.h"
#include "../../Users/Tasks/h/Open_task.h"
class OpenAccountCommand : public CommandFromClient
{
private:
	MyString nameOfTheBank;
public:
	OpenAccountCommand(const MyString& nameOfTheBank);
	void execute()override;
	virtual Command* clone() const;
};

