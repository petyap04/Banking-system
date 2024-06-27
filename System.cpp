#include "System.h"
#include <iostream>

void System::create_bank(const MyString& nameOfTheBank)
{
	try {
		banks_container.pushBack(Bank(nameOfTheBank));
	}
	catch (...) {
		std::cout << "There has been a mistake! Try again!" << std::endl;
	}
}

unsigned System::check_avl(const MyString& bank_name, unsigned int account_number) const
{
	try {
		int indOfBank = returnTheIndexOfTheBankWithThatName(bank_name);
		if (indOfBank < 0) {
			throw std::exception("There is no bank with that name");
		}
		int indOfClient = banks_container[indOfBank].clientsOfBank.indexClientWithThatName(currentUser->getFirstName().getData(), currentUser->getSecondName().getData());
		if (indOfClient < 0) {
			throw std::exception("There is no user with that name in the bank");
		}
		int indOfAccount = banks_container[indOfBank].clientsOfBank[indOfClient].hasAccountWithThatNumber(account_number);
		if (indOfAccount < 0) {
			throw std::exception("The user does not have account with that number");
		}
		else {
			return banks_container[indOfBank].clientsOfBank[indOfClient].accounts[indOfAccount].availableMoney;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
}

int System::returnTheIndexOfTheBankWithThatName(const MyString& name) const
{
	for (int i = 0; i < banks_container.getSize(); i++) {
		if (banks_container[i].hasSameName(name)) {
			return i;
		}
	}
	return -1;
}

int System::returnTheIndexOfCurrentUserInABank(int indOfBank) const
{
	for (int i = 0; i < usersContainer.getSize(); i++) {
		if (usersContainer[i]->amITheUserYouAreSearchingFor(currentUser)) {
			return i;
		}
	}
	return -1;
}

Bank& System::getBankOnIndex(unsigned ind)
{
	return banks_container[ind];
}

User* System::getCurrentUser()
{
	return currentUser;
}

Bank& System::getBankWhereEmployeeIsWorking(const Employee* e) 
{
	for (int i = 0; i < banks_container.getSize(); i++) {
		int ind = banks_container[i].employeesOfBank.indexEmployeesWithThatName(e->getFirstName(), e->getSecondName());
		if (ind > 0) {
			return banks_container[i];
		}
	}
	throw std::exception("There is no employee with that name");
}

void System::addCheck(Check&& check)
{
	checks.pushBack(check);
}

int System::returnIndexOfCheck(const Check& check) const
{
	for (int i = 0; i < checks.getSize(); i++) {
		if (checks[i] == check) {
			return i;
		}
	}
	return -1;
}

void System::theCheckHasBeenUsed(const Check& check)
{
	int ind = returnIndexOfCheck(check);
	if (ind < 0) {
		throw std::exception("You cannot use a check that does not exist");
	}
	for (int i = ind; i < checks.getSize() - 1; i++) {
		checks[i] = checks[i + 1];
	}
	checks.popBack();
}

bool System::someoneIsLogedIn() const
{
	return currentUser;
}

void System::listAllAccountAClientHas(const Client* client) const
{
	for (int i = 0; i < banks_container.getSize(); i++) {
		banks_container[i].listAllAccountAClientHasInTheBank(client);
	}
}

void System::addUser(User*&& user)
{
	usersContainer.pushBack(user);
}

unsigned System::getCountOfBanks() const
{
	return banks_container.getSize();
}

void System::setCurrentUser(User* user)
{
	if (user) {
		currentUser = user;
	}
}

void System::openAccount(Client* client, unsigned ind)
{
	Bank& bank = getBankWhereEmployeeIsWorking(dynamic_cast<Employee*>(currentUser));
	bank.openAccount(dynamic_cast<Client*>(client));
	dynamic_cast<Employee*>(currentUser)->theTaskHasBeenDone(ind);
}

void System::closeAccount(Client* client, unsigned accountNumber, unsigned ind)
{
	Bank& bank = getBankWhereEmployeeIsWorking(dynamic_cast<Employee*>(currentUser));
	bank.closeAccount(dynamic_cast<Client*>(client), accountNumber);
	dynamic_cast<Employee*>(currentUser)->theTaskHasBeenDone(ind);
}

void System::changeAccount(Client* client, const MyString& oldBank, unsigned accountNumber, unsigned ind)
{
	unsigned money = check_avl(oldBank, accountNumber);
	Bank& bankEmplIsWorkingIn = getBankWhereEmployeeIsWorking(dynamic_cast<Employee*>(currentUser));
	bankEmplIsWorkingIn.openAccount(client, accountNumber, money);
	getBankOnIndex(returnTheIndexOfTheBankWithThatName(oldBank)).closeAccount(client, accountNumber);
	dynamic_cast<Employee*>(getCurrentUser())->theTaskHasBeenDone(ind);
}

void System::sendCheckToClient(double sum, const MyString code, unsigned Id)
{
	Check check(code, sum, Id);
	addCheck(std::move(check));
}

void System::useCheck(const MyString bank_name, unsigned accountNumber, const MyString code)
{
	Check check(code, currentUser->IDNumber);
	int ind = returnIndexOfCheck(check);
	if (ind < 0) {
		throw std::exception("This check does not exist");
	}
	int indOfBank = returnTheIndexOfTheBankWithThatName(bank_name);
	if (indOfBank < 0) {
		throw std::exception("This bank does noe exist");
	}
	banks_container[indOfBank].addMoneyToAccount(dynamic_cast<Client*>(currentUser), checks[ind].getMoney(), accountNumber);
}


void System::whoami() const
{
	///opravi
	try {
		if (currentUser) {
			throw std::exception("You need to be loged in the system to check your info");
		}
		else {
			std::cout << "First name: " << currentUser->getFirstName() << std::endl;
			std::cout << "Second name: " << currentUser->getSecondName() << std::endl;
			std::cout << "ID number: " << currentUser->IDNumber << std::endl;
			std::cout << "Age: " << currentUser->age << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void System::exit()
{
	try {
		if (currentUser) {
			throw std::exception("You need to be loged in the system to exit");
		}
		else {
			currentUser = nullptr;
			std::ofstream ofs("userDataBase.txt");
			if (!ofs.is_open()) {
				throw std::exception("Problem with openning of the file!");
			}
		/*	operator<<(ofs, usersContainer);
			operator<<(ofs, banks_container);*/
			ofs.close();
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

//std::istream& operator>>(std::istream& ifs, System system)
//{
//	return ifs >> system.usersContainer >> system.banks_container >> system.currentUser >> system.checks;
//}
//
//std::ostream& operator<<(std::ostream& ofs, const System system)
//{
//	return ofs << system.usersContainer <<" " << system.banks_container <<" " << system.currentUser <<" " << system.checks;
//}
