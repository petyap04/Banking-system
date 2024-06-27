#pragma once
#include "../CommandFromEmployee.h"
class WhoAmICommand: public CommandFromEmployee
{
public:
	void execute();
	Command* clone()const;
};

