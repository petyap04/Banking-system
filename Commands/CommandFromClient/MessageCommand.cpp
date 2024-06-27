#include "MessageCommand.h"

void MessageCommand::execute()
{
	try {
		dynamic_cast<Client*>(banking_system->getCurrentUser())->messages();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* MessageCommand::clone() const
{
	return new MessageCommand(*this);
}
