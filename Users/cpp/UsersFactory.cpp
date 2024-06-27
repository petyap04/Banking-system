#include <iostream>
#include "../h/Client.h"
#include "../h/Employee.h"
#include "../h/ThirdPartyEmployee.h"

User* createUser(unsigned int number) {
	switch (number)
	{
	case 0:return new Client();
	case 1:return new Employee();
	case 2:return new ThirdPartyEmployee();
	}
	return new Client();
}

User* createUser(const MyString& firstName, const MyString& secondName, const MyString& nameOfPossition, unsigned IDNumber, unsigned age,
	const MyString& password) {
	if (nameOfPossition == "Client") {
		return new Client(firstName, secondName, IDNumber, age, password);
	}
	else if (nameOfPossition == "ThirdPartyEmployee") {
		return new ThirdPartyEmployee(firstName, secondName, password, IDNumber, age);
	}
	else {
		throw std::exception("There is no possition with that name!");
	}
}

//void serialise(std::ostream& ofs, const User* user)
//{
//	if (Client* client = dynamic_cast<Client*>(const_cast<User*>(user))) {
//		ofs << 1 << " ";
//		operator<<(ofs, static_cast<Client*>(const_cast<User*>(user)));
//	}
//	else if (Employee* empl = dynamic_cast<Employee*>(const_cast<User*>(user))) {
//		ofs << 2 << " ";
//		operator<<(ofs, static_cast<Employee*>(const_cast<User*>(user)));
//	}
//	else if (ThirdPartyEmployee* tpe = dynamic_cast<ThirdPartyEmployee*>(const_cast<User*>(user))) {
//		ofs << 3 << " ";
//		operator<<(ofs, static_cast<ThirdPartyEmployee*>(const_cast<User*>(user)));
//	}
//}
//
//void deserialization(std::istream& ifs, User* user)
//{
//	int number;
//	ifs >> number;
//	ifs.ignore();
//	if (number == 1) {
//		user = new Client();
//		ifs >> user;
//	}
//	else if (number == 2) {
//		user = new Employee();
//		ifs >> user;
//	}
//	else if (number == 3) {
//		user = new ThirdPartyEmployee();
//		ifs >> user;
//	}
//}

User* createUser(const char* firstName, const char* secondName, const char* nameOfPossition, unsigned IDNumber, unsigned age,
	const char* password, const char* nameOfTheBank) {
	if (strcmp(nameOfPossition, "Employee") == 0) {
		return new Employee(firstName, secondName, IDNumber, age, password, nameOfTheBank);
	}
	else {
		throw std::exception("There is no possition with that name!");
	}
}
