#include "CommandFactory.h"
#include <fstream>
#include "CommandFromClient/ChangeAccountCommand.h"
#include "CommandFromClient/CheakAvlCommand.h"
#include "CommandFromClient/CloseAccountCommand.h"
#include "CommandFromClient/ListCommand.h"
#include "CommandFromClient/MessageCommand.h"
#include "CommandFromClient/OpenAccountCommand.h"
#include "CommandFromClient/RedeemCommand.h"
#include "CommandFromClient/WhoAmICommand.h"


#include "CommandsFromEmployee/TaskCommand.h"
#include "CommandsFromEmployee/ViewCommand.h"
#include "CommandsFromEmployee/ApproveCommand.h"
#include "CommandsFromEmployee/DisapproveCommand.h"
#include "CommandsFromEmployee/ValidateCommand.h"

#include "ExitCommand.h"
#include "../Commands/CommandFromThirdPartyEmployee/SendCheckCommand.h"

#include "../Login/h/Login.h"
Command* commandFactory(const MyString& command)
{
	while (true) {
		if ("logIn" == command) {
			MyString password;
			unsigned id;
			std::cin >> password >> id;
			Login signIn;
			signIn.signIn(id, password);
			return nullptr;
		}

		else if ("signUp" == command) {
			MyString firstName, secondName, password, possition;
			unsigned int id, age;
			std::cin >> firstName >> secondName >> password >> possition >> id >> age;
			Login signUp;
			signUp.signupUser(firstName, secondName, password, possition, id, age);
			return nullptr;
		}
		else {
			std::cout << "Invalid command! Try again!";
		}
	}
	return nullptr;
}

Command* commandClientFactory() {
	while (true) {
		MyString command;
		std::cin >> command;
		if ("change account" == command) {
			MyString currBank, newBank;
			unsigned account;
			std::cin >> currBank >> newBank >> account;
			return new ChangeAccountCommand(currBank, newBank, account);
		}
		else if ("cheakAvl" == command) {
			MyString bank;
			unsigned account;
			std::cin >> bank >> account;
			return new CheakAvlCommand(bank, account);
		}
		else if ("open" == command) {
			MyString bank;
			std::cin >> bank;
			return new OpenAccountCommand(bank);
		}
		else if ("close" == command) {
			MyString bank;
			unsigned account;
			std::cin >> bank >> account;
			return new CloseAccountCommand(bank, account);
		}
		else if ("list" == command) {
			return new ListCommand();
		}
		else if ("massege" == command) {
			return new MessageCommand();
		}
		else if ("whoami" == command) {
			return new WhoAmICommand();
		}
		else if ("redeem" == command) {

		}
		else if ("exit" == command) {
			return new ExitCommand();
		}
		else {
			std::cout << "Invalid command! Try again!";
		}
	}
	return nullptr;
}

Command* userFactory(User* user) {
	if (Client* client = dynamic_cast<Client*>(user)) {
		return commandClientFactory();
	}
	else if (Employee* employee = dynamic_cast<Employee*>(user)) {
		return commandEmployeeFactory();
	}
	else if (ThirdPartyEmployee* employee = dynamic_cast<ThirdPartyEmployee*>(user)) {
		return commandThirdPartyEmployeeFactory();
	}
	else {
		return nullptr;
	}
	
}

Command* commandEmployeeFactory() {
	while (true) {
		MyString command;
		std::cin >> command;
		if ("task" == command) {
			return new TaskCommand();
		}
		else if ("view" == command) {
			std::cout << "Which task do you want to see:";
			unsigned ind;
			std::cin >> ind;
			return new ViewCommand(ind);
		}
		else if ("approve" == command) {
			std::cout << "Which task do you want to approve:";
			unsigned ind;
			std::cin >> ind;
			return new ApproveCommand(ind);
		}
		else if ("disapprove" == command) {
			std::cout << "Which task do you want to disapprove:";
			unsigned ind;
			std::cin >> ind;
			return new DisapproveCommand(ind);
		}
		else if ("validate" == command) {
			std::cout << "Which task do you want to validate:";
			unsigned ind;
			std::cin >> ind;
			return new ValidateCommand(ind);
		}
		else if ("exit" == command) {
			return new ExitCommand();
		}
		else {
			std::cout << "Invalid command! Try again!";
		}
	}
	return nullptr;
}

Command* commandThirdPartyEmployeeFactory() {
	while (true) {
		MyString command;
		std::cin >> command;
		if ("send check" == command) {
			double sum;
			MyString code;
			unsigned id;
			std::cin >> sum >> code >> id;
			return new SendCheckCommand(sum, code, id);
		}
		else if ("exit" == command) {
			return new ExitCommand();
		}
		else {
			std::cout << "Invalid command! Try again!";
		}
	}
	return nullptr;
}