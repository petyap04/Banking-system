#include "CloseAccountCommand.h"

CloseAccountCommand::CloseAccountCommand(const MyString& nameOfTheBank, unsigned accountNumber):nameOfTheBank(), accountNumber(accountNumber){}

void CloseAccountCommand::execute()
{
	try {
		int ind = banking_system->returnTheIndexOfTheBankWithThatName(nameOfTheBank);
		if (ind < 0) {
			throw std::exception("The bank you want to close account in does not exist");
		}
		Task* task = new Close_task(dynamic_cast<Client*>(banking_system->getCurrentUser()), accountNumber);
		banking_system->getBankOnIndex(ind).giveTaskToTheEmployeeWithTheLeastTasks(task);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* CloseAccountCommand::clone() const
{
	return new CloseAccountCommand(*this);
}
