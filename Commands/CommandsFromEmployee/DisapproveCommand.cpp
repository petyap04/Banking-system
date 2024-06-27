#include "DisapproveCommand.h"

DisapproveCommand::DisapproveCommand(unsigned ind) : ind(ind) {}

void DisapproveCommand::execute()
{
	try {
		Message m;
		m.setMessage("The command was disapproved");
		dynamic_cast<Employee*>(banking_system->getCurrentUser())->getTask(ind)->sendMessageToClient(std::move(m));
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* DisapproveCommand::clone() const
{
	return new DisapproveCommand(*this);
}
