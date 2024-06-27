#include "ApproveCommand.h"

ApproveCommand::ApproveCommand(unsigned ind): ind(ind){}

void ApproveCommand::execute()
{
	try {
		Task* task = dynamic_cast<Employee*>(banking_system->getCurrentUser())->getTask(ind);
		Client* client = dynamic_cast<Employee*>(banking_system->getCurrentUser())->getTask(ind)->getClient();
		if (dynamic_cast<Open_task*>(task)) {
			banking_system->openAccount(client, ind);
		}
		else if (dynamic_cast<Close_task*>(task)) {
			banking_system->closeAccount(client,dynamic_cast<Close_task*>(task)->getAccount(), ind);
		}
		else if (dynamic_cast<Change_task*>(task)) {
			banking_system->changeAccount(client, dynamic_cast<Change_task*>(task)->getOldBank(), dynamic_cast<Change_task*>(task)->getAccount(), ind);
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* ApproveCommand::clone() const
{
	return new ApproveCommand(*this);
}
