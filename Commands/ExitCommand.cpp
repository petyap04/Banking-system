#include "ExitCommand.h"

void ExitCommand::execute()
{
	banking_system->exit();
}

Command* ExitCommand::clone() const
{
	return new ExitCommand(*this);
}
