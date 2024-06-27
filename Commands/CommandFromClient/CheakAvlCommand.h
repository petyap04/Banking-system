#pragma once
#include "../CommandFromClient.h"

class CheakAvlCommand : public CommandFromClient
{
	MyString nameOfTheBank;
	unsigned accountNumber;
public:
	CheakAvlCommand(const MyString& nameOfTheBank, unsigned accountNumber);
	void execute()override;
	virtual Command* clone() const;
};