#include "CheakAvlCommand.h"

CheakAvlCommand::CheakAvlCommand(const MyString& nameOfTheBank, unsigned accountNumber): nameOfTheBank(nameOfTheBank), accountNumber(accountNumber){}

void CheakAvlCommand::execute()
{
	try {
		int money = banking_system->check_avl(nameOfTheBank, accountNumber);
		std::cout << "Availabal money in this account: " << money << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* CheakAvlCommand::clone() const
{
	return new CheakAvlCommand(*this);
}
