#include "ChangeAccountCommand.h"

ChangeAccountCommand::ChangeAccountCommand(const MyString& currBank, const MyString& newBank, unsigned accountNumber)
	                 : currBank(currBank), newBank(newBank), accountNumber(accountNumber){}

void ChangeAccountCommand::execute()
{
	try {
		int ind1 = banking_system->returnTheIndexOfTheBankWithThatName(currBank);
		if (ind1 < 0) {
			throw std::exception("The bank you want to close account in does not exist");
		}
		int ind2 = banking_system->returnTheIndexOfTheBankWithThatName(newBank);
		if (ind2 < 0) {
			throw std::exception("The bank you want to open account in does not exist");
		}
		Task* task = new Change_task(dynamic_cast<Client*>(banking_system->getCurrentUser()), accountNumber, currBank, newBank);
		banking_system->getBankOnIndex(ind2).giveTaskToTheEmployeeWithTheLeastTasks(task);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* ChangeAccountCommand::clone() const
{
	return new ChangeAccountCommand(*this);
}
