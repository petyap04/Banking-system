#include "ListCommand.h"

void ListCommand::execute()
{
	try {
		Client* client = dynamic_cast<Client*>(banking_system->getCurrentUser());
		for (int i = 0; i < banking_system->getCountOfBanks(); i++) {
			banking_system->getBankOnIndex(i).listAllAccountAClientHasInTheBank(client);
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* ListCommand::clone() const
{
	return new ListCommand(*this);
}
