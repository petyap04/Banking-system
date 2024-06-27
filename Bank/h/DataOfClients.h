#pragma once
#include "DataOfClientInTheBank.h"

class DataOfClients
{
private:
	Vector<DataOfClientInTheBank> clients;
	unsigned lastAccountNumberGiven = 0;
public:
	const DataOfClientInTheBank operator[](int ind)const;
	DataOfClientInTheBank operator[](int ind);

	void openAccount(const Client* client);
	void openAccount(const Client* client, unsigned accountNumber, unsigned money);
	void closeAccount(const Client* client, unsigned accountNumber);
	void addMoneyToAccount(unsigned ind, double money, unsigned account);

	int indexClientWithThatName(const MyString& firstName, const MyString& secondName) const;
	void addClient(const Client* c);
	friend class Bank;
	friend class System;
};

