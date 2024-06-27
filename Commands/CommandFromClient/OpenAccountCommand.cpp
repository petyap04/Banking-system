#include "OpenAccountCommand.h"

OpenAccountCommand::OpenAccountCommand(const MyString& nameOfTheBank): nameOfTheBank(nameOfTheBank){}

void OpenAccountCommand::execute()
{
	try {
		int ind = banking_system->returnTheIndexOfTheBankWithThatName(nameOfTheBank);
		if (ind < 0) {
			throw std::exception("The bank you want to open account in does not exist");
		}
		Task* task = new Open_task(dynamic_cast<Client*>(banking_system->getCurrentUser()));
		unsigned indOfTask = banking_system->getBankOnIndex(ind).giveTaskToTheEmployeeWithTheLeastTasks(task);
		task->setInd(indOfTask);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* OpenAccountCommand::clone() const
{
	return new OpenAccountCommand(*this);
}
