#pragma once
#include "User.h"
#include "../../Helpers/MyString.h"
#include "../../Helpers/Vector.hpp"
#include "Message.h"
#include <fstream>

class Client: public User
{
private:
	Vector<Message> container_messages;
public:
	Client() = default;
	Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password);
	void messages()const;

	void addMessage(Message&& message);
	User* clone()const;

	/*friend std::istream& operator>>(std::istream& ifs, Client* user);
	friend std::ostream& operator<<(std::ostream& ofs, const Client* user);*/
};

