#include "ValidateCommand.h"

ValidateCommand::ValidateCommand(unsigned ind): CommandFromEmployee(), ind(ind){}

void ValidateCommand::addOldBank(const MyString& oldBank)
{
	this->oldBank = oldBank;
}

void ValidateCommand::execute()
{
	try {
		Task* task = dynamic_cast<Employee*>(banking_system->getCurrentUser())->getTask(ind);
		if (dynamic_cast<Change_task*>(task)) {
			throw std::exception("You can only validate change_tasks!");
		}
		bool isValid = dynamic_cast<Change_task*>(task)->isTaskValid();
		dynamic_cast<Change_task*>(task)->beenValidated();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* ValidateCommand::clone() const
{
	return new ValidateCommand(*this);
}
