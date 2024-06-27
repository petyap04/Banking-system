#pragma once
#include "../CommandFromClient.h"
#include "../../Users/Tasks/h/Change_task.h"

class ChangeAccountCommand: public CommandFromClient
{
private:
	MyString currBank;
	MyString newBank;
	unsigned accountNumber;
public:
	ChangeAccountCommand(const MyString& currBank, const MyString& newBank, unsigned accountNumber);
	void execute()override;
	virtual Command* clone() const;
};
