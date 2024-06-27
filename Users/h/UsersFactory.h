#pragma once
#include <iostream>
#include <fstream>
#include "../../Helpers/MyString.h"
enum class TypeOfUsers {
	Client,
	Employee,
	ThirdPartyEmployee
};

User* createUser(unsigned int number);
User* createUser(const char* firstName, const char* secondName, const char* nameOfPossition, unsigned IDNumber, unsigned age,
	const char* password, const char* nameOfTheBank);
User* createUser(const MyString& firstName, const MyString& secondName, const MyString& nameOfPossition, unsigned IDNumber, unsigned age,
	const MyString& password);
void serialise(std::ostream& ofs, const User* user);
void deserialization(std::istream& ifs, User* user);