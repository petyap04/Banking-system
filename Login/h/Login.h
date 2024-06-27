#pragma once
#include "../../Helpers/MyString.h"
#include "../../Users/h/User.h"
#include "../../Helpers/Polymorphic_Ptr.hpp"
#include "../../Helpers/Vector.hpp"
class Login {
private:
	User* currentUser = nullptr;
	Vector<Polymorphic_Ptr<User>> users;
	void registerUser(const MyString& fisrtName, const MyString& secondName, const MyString& password, const MyString& possition, unsigned id, unsigned age);
	void login(unsigned id, const MyString& password);
public:
	void signIn(unsigned id, const MyString& password);
	void signupUser(const MyString& firstName, const MyString& secondName, const MyString& password, const MyString& possition, unsigned id, unsigned age);
	User* getUser();
	Vector<Polymorphic_Ptr<User>> getUsers();
};

