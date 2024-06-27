#include "../h/DataOfClients.h"

int DataOfClients::indexClientWithThatName(const MyString& firstName, const MyString& secondName) const
{
	for (int i = 0; i < clients.getSize(); i++) {
		if (clients[i].amITheUserYouAreSearchingFor(firstName, secondName)) {
			return i;
		}
	}
	return -1;
}

const DataOfClientInTheBank DataOfClients::operator[](int ind) const
{
	if (ind < 0 || ind >= clients.getSize()) {
		throw std::exception("error");
	}
	return clients[ind];
}


DataOfClientInTheBank DataOfClients::operator[](int ind) 
{
	if (ind < 0 || ind >= clients.getSize()) {
		throw std::exception("error");
	}
	return clients[ind];
}

void DataOfClients::openAccount(const Client* client)
{
	int ind = indexClientWithThatName(client->getFirstName(), client->getSecondName());
	if (ind < 0) {
		addClient(client);
		ind = indexClientWithThatName(client->getFirstName(), client->getSecondName());
	}
	clients[ind].openNewAccount(lastAccountNumberGiven);
}

void DataOfClients::openAccount(const Client* client, unsigned accountNumber, unsigned money)
{
	int ind = indexClientWithThatName(client->getFirstName(), client->getSecondName());
	if (ind < 0) {
		addClient(client);
		ind = indexClientWithThatName(client->getFirstName(), client->getSecondName());
	}
	clients[ind].openNewAccount(accountNumber, money);
}

void DataOfClients::closeAccount(const Client* client, unsigned accountNumber)
{
	int ind = indexClientWithThatName(client->getFirstName(), client->getSecondName());
	if (ind < 0) {
		throw std::exception("You need to have an account to close it");
	}
	clients[ind].closeAccount(accountNumber);
}

void DataOfClients::addMoneyToAccount(unsigned ind, double money, unsigned account)
{
	clients[ind].addMoneyToAccount(money, account);
}

void DataOfClients::addClient(const Client* c)
{
	clients.pushBack(c);
}
