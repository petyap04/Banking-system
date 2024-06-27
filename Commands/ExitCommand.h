#pragma once
#include "Command.h"
class ExitCommand: public Command
{
public:
	void execute();
	Command* clone()const;
};

