#pragma once
#include <iostream>
#include "../../Helpers/MyString.h"
class Check
{
private:
	MyString code;
	double money = 0;
	unsigned Id = 0;
	bool isValid(const MyString& code);
public:
	Check() = default;
	Check(const MyString& code, unsigned Id);
	Check(const MyString& code, double money, unsigned Id);
	const MyString& getCode()const;
	double getMoney()const;
	unsigned getId()const;
};

bool operator==(const Check& lhs, const Check& rhs);
bool operator!=(const Check& lhs, const Check& rhs);