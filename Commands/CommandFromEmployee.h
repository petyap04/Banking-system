#pragma once
#include "Command.h"
#include "../Users/Tasks/h/Open_task.h"
#include "../Users/Tasks/h/Close_task.h"
#include "../Users/Tasks/h/Change_task.h"

class CommandFromEmployee: public Command
{
public:
	virtual Command* clone() const = 0;
	virtual ~CommandFromEmployee() = default;
};

