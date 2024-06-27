#pragma once
#include "../CommandFromEmployee.h"
#include "../../Users/Tasks/h/Change_task.h"

class ValidateCommand : public CommandFromEmployee
{
private:
	unsigned ind;
	MyString oldBank = nullptr;
public:
	ValidateCommand(unsigned ind);
	void addOldBank(const MyString& oldBank);
	void execute()override;
	virtual Command* clone() const;
};

