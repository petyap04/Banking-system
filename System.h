#pragma once
#include <iostream>
#include <fstream>
#include "Bank/h/Bank.h"
#include "Helpers/Vector.hpp"
#include "Bank/h/Check.h"

class System
{
private:
	Vector<Polymorphic_Ptr<User>> usersContainer;
	Vector<Bank> banks_container;
	User* currentUser = nullptr;
	Vector<Check> checks;
	System() = default;
public:
	//static System& getInstance(std::ifstream& ifs, Vector<Polymorphic_Ptr<User>>&& users, User*&& curr) {
	//	static System system;
	//	system.usersContainer = users;
	//	system.currentUser = curr;
	//	ifs >> system.banks_container;
	//	return system;
	//}
	static System& getInstance() {
		static System system;
		return system;
	}
	void create_bank(const MyString& nameOfTheBank);

	unsigned check_avl(const MyString& bank_name, unsigned int account_number)const;

	int returnTheIndexOfTheBankWithThatName(const MyString& name)const;
	int returnTheIndexOfCurrentUserInABank(int indOfBank)const;
	Bank& getBankOnIndex(unsigned ind);
	User* getCurrentUser();
	Bank& getBankWhereEmployeeIsWorking(const Employee* e);
	void addCheck(Check&& check);
	int returnIndexOfCheck(const Check& check)const;
	void theCheckHasBeenUsed(const Check& check);
	bool someoneIsLogedIn()const;

	void listAllAccountAClientHas(const Client* client)const;
	void addUser(User*&& user);
	unsigned getCountOfBanks()const;
	void setCurrentUser(User* user);

	void openAccount(Client* client, unsigned ind);
	void closeAccount(Client* client, unsigned accountNumber, unsigned ind);
	void changeAccount(Client* client, const MyString& oldBank, unsigned accountNumber, unsigned ind);
	void sendCheckToClient(double sum, const MyString code, unsigned Id);
	void useCheck(const MyString bank_name, unsigned accountNumber, const MyString code);

	void whoami()const;
	void exit();

	//friend std::istream& operator>>(std::istream& ifs, System system);
	//friend std::ostream& operator<<(std::ostream& ofs, const System system);
};

