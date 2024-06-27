#pragma once
#include "../CommandFromEmployee.h"

class TaskCommand: public CommandFromEmployee
{
public:
	void execute()override;
	virtual Command* clone() const;
};

