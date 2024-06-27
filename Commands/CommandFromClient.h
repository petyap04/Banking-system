#pragma once
#include "Command.h"
#include "../System.h"
#include "../Helpers/MyString.h"

class CommandFromClient : public Command
{
public:
	virtual Command* clone() const = 0;
	virtual ~CommandFromClient() = default;
};

