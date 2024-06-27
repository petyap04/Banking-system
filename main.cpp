#include <iostream>
#include "Commands/CommandFactory.h"

int main()
{
	System& banking_system = System::getInstance();
	MyString command;
	std::cin >> command;
	commandFactory(command);
	if (banking_system.someoneIsLogedIn()) {
		userFactory(banking_system.getCurrentUser())->execute();
	}
}
