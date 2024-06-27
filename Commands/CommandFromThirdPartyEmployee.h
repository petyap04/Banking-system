#pragma once
#include "Command.h"
class CommandFromThirdPartyEmployee:public Command
{
public:
	virtual Command* clone() const = 0;
	virtual ~CommandFromThirdPartyEmployee() = default;
};

