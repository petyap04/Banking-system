#include "../h/DataOfClientInTheBank.h"


const Client* DataOfClientInTheBank::getClient() const
{
	return client;
}

DataOfClientInTheBank::DataOfClientInTheBank(const Client* client) {
	this->client = client;
}

int DataOfClientInTheBank::hasAccountWithThatNumber(unsigned accountNumber) const
{
	for (int i = 0; i < accounts.getSize(); i++) {
		if (accountNumber == accounts[i].accountNumber) {
			return i;
		}
	}
	return -1;
}

bool DataOfClientInTheBank::amITheUserYouAreSearchingFor(const MyString& firstName, const MyString& secondName) const
{
	return client->amITheUserYouAreSearchingFor(firstName,secondName);
}

void DataOfClientInTheBank::listAllAccountAClientHasInTheBank() const
{
	for (int i = 0; i < accounts.getSize(); i++) {
		std::cout << accounts[i].accountNumber << std::endl;
	}
}

void DataOfClientInTheBank::openNewAccount(unsigned& lastAccountNumberGiven)
{
	Account newAccount(lastAccountNumberGiven,0);
	accounts.pushBack(newAccount);
	lastAccountNumberGiven++;
}

void DataOfClientInTheBank::openNewAccount(unsigned accountNumber, unsigned money)
{
	Account newAccount(accountNumber, money);
	accounts.pushBack(newAccount);
}

void DataOfClientInTheBank::closeAccount(unsigned accountNumber)
{
	int ind = hasAccountWithThatNumber(accountNumber);
	if (ind < 0) {
		throw std::exception("You cannot close an account that does not exist");
	}
	for (int i = ind; i < accounts.getSize() - 1; i++) {
		accounts[i] = accounts[i + 1];
	}
	accounts.popBack();
}

void DataOfClientInTheBank::addMoneyToAccount(double money, unsigned account)
{
	accounts[hasAccountWithThatNumber(account)].addMoney(money);
}

DataOfClientInTheBank::Account::Account(unsigned accountNumber, double availableMoney):accountNumber(accountNumber), availableMoney(availableMoney){}

void DataOfClientInTheBank::Account::addMoney(double money)
{
	this->availableMoney += money;
}
