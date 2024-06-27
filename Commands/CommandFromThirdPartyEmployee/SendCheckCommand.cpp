#include "SendCheckCommand.h"

SendCheckCommand::SendCheckCommand(double sum, const MyString code, unsigned Id):sum(sum), code(code), Id(Id){}

void SendCheckCommand::execute()
{
	try {
		banking_system->sendCheckToClient(sum, code, Id);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* SendCheckCommand::clone() const
{
	return new SendCheckCommand(*this);
}
