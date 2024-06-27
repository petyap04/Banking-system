#pragma once
#include "../CommandFromEmployee.h"
class RedeemCommand: public CommandFromEmployee
{
	MyString bank_name;
	unsigned accountNumber; 
	MyString code;
public:
	RedeemCommand(const MyString bank_name, unsigned accountNumber, const MyString code);
	void execute();
	Command* clone()const;
};

