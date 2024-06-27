#pragma once
#include "../System.h"
class Command
{
protected:
	System* banking_system;
public:
	Command();
	virtual void execute() = 0;
	virtual Command* clone()const = 0;
	virtual ~Command() = default;
};

