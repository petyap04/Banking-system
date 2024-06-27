#pragma once
#include "../../Helpers/MyString.h"
#include "../../Users/h/Client.h"
#include "../../Helpers/Polymorphic_Ptr.hpp"
#include "../../Helpers/Vector.hpp" 

class DataOfClientInTheBank
{
private:
	struct Account {
		unsigned accountNumber = 0;
		double availableMoney = 0;
		Account() = default;
		Account(unsigned accountNumber, double availableMoney);
		void addMoney(double money);
	};
	const Client* client;
	Vector<Account> accounts;

public:
	DataOfClientInTheBank() = default;
	DataOfClientInTheBank(const Client* client);
	int hasAccountWithThatNumber(unsigned accountNumber)const;
	bool amITheUserYouAreSearchingFor(const MyString& firstName, const MyString& secondName)const;
	void listAllAccountAClientHasInTheBank()const;

	void openNewAccount(unsigned& lastAccountNumberGiven);
	void openNewAccount(unsigned accountNumber, unsigned money);
	void closeAccount(unsigned accountNumber);
	void addMoneyToAccount(double money, unsigned account);

	const Client* getClient()const;
	friend class DataOfClients;
	friend class System;
};

