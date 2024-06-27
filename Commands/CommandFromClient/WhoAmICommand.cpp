#include "WhoAmICommand.h"

void WhoAmICommand::execute()
{
	banking_system->whoami();
}

Command* WhoAmICommand::clone() const
{
	return new WhoAmICommand(*this);
}
