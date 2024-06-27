#include "../h/Login.h"
#include <fstream>
#include <sstream>
#include "../../System.h"
#include "../../Users/h/UsersFactory.h"
void Login::registerUser(const MyString& firstName, const MyString& secondName, const MyString& password, const MyString& possition, unsigned id, unsigned age)
{
	currentUser = createUser(firstName, secondName, possition, id, age, password);
	users.pushBack(currentUser);

	std::ofstream ofs("userDataBase.txt", std::ios::app);
	if (!ofs.is_open()) {
		std::cout << "Invalid file name" << std::endl;
		return;
	}
	ofs << currentUser << '\n';
	ofs.close();
}

void Login::login(unsigned id, const MyString& password)
{
	const char* filename = "userDataBase.txt";
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cout << "Invalid file name" << std::endl;
		return;
	}
	while (!ifs.eof()) {
		char buffer[1024];
		ifs.getline(buffer, 1024);
		std::stringstream strStream(buffer);
		MyString currentFirstName;
		MyString currentSecondName;
		MyString currentPassword;
		MyString nameOfPosition;
		unsigned currentId;
		unsigned age;
		// firstName secondName password egn age
		strStream >> currentFirstName >> currentSecondName >> currentPassword >>nameOfPosition >> currentId >> age;
		User* user = createUser(currentFirstName, currentSecondName, nameOfPosition, currentId, age, currentPassword);
		users.pushBack(user);
		if (currentId == id) {
			if (currentPassword == password) {
				currentUser = user;
			}
			else {
				throw std::exception("Invalid Password for id ");
			}
		}
	}
	if (!currentUser) {
		throw std::exception("");
	}
	System& system = System::getInstance();
	for (int i = 0; i < users.getSize(); i++) {
		system.addUser(users[i].get());
	}
	system.setCurrentUser(currentUser);
	
}

void Login::signIn(unsigned id, const MyString& password)
{
	try {
		login(id, password);
	}
	catch (...) {
		std::cout << "User not found try using command signUp" << std::endl;
	}
}

void Login::signupUser(const MyString& firstName, const MyString& secondName, const MyString& password, const MyString& possition,  unsigned id, unsigned age)
{
	try {
		login(id, password);
	}
	catch (...) {
		registerUser(firstName, secondName, password, possition, id, age);
		System& inst = System::getInstance();
		inst.addUser(std::move(currentUser));
	}
}

User* Login::getUser()
{
	return currentUser;
}

Vector<Polymorphic_Ptr<User>> Login::getUsers()
{
	return users;
}
