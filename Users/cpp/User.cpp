#include "../h/User.h"
#include <iostream>

User::User(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password):
    firstName(firstName),secondName(secondName), IDNumber(IDNumber), age(age),password(password){}

bool User::isThePasswordRight(const MyString& password) const
{
    return password == this->password;
}

const MyString& User::getFirstName() const
{
    return firstName;
}

const MyString& User::getSecondName() const
{
    return secondName;
}

bool User::amITheUserYouAreSearchingFor(const User* user) const
{
    return user->getFirstName() == this->firstName && user->getSecondName() == this->secondName;
}

bool User::amITheUserYouAreSearchingFor(const MyString& firstName, const MyString& secondName) const
{
    return firstName == this->firstName && secondName == this->secondName;
}

bool User::amITheUserYouAreSearchingFor(const MyString& firstName, const MyString& secondName, const MyString& password) const
{
    return firstName == this->firstName && secondName == this->secondName && password == this->password;
}

User::operator bool() const
{
    return strcmp("", this->firstName.getData()) != 0 &&
           strcmp("", this->secondName.getData()) != 0 &&
           strcmp("", this->password.getData()) != 0;
}

//std::istream& operator>>(std::istream& ifs, User* user)
//{
//    ifs >> user->firstName >> user->secondName >> user->IDNumber >> user->age >> user->password;
//    return ifs;
//}
//
//std::ostream& operator<<(std::ostream& ofs, const User* user)
//{
//    ofs << user->firstName << " " << user->secondName << " " << user->IDNumber << " " << user->age << " " << user->password;
//    return ofs;
//}

