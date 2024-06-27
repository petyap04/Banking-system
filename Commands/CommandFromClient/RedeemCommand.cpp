#include "RedeemCommand.h"

RedeemCommand::RedeemCommand(const MyString bank_name, unsigned accountNumber, const MyString code)
	                        :bank_name(bank_name),accountNumber(accountNumber),code(code){}

void RedeemCommand::execute()
{
	try {
		banking_system->useCheck(bank_name, accountNumber, code);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* RedeemCommand::clone() const
{
	return new RedeemCommand(*this);
}
