#pragma once
#include "../CommandFromEmployee.h"

class ViewCommand : public CommandFromEmployee
{
	unsigned taskID;
public:
	ViewCommand(unsigned taskID);
	void execute()override;
	virtual Command* clone() const;
};

