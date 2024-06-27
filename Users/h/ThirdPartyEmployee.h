#pragma once
#include "User.h"
#include "../../Helpers/MyString.h"

class ThirdPartyEmployee : public User
{
public:
	ThirdPartyEmployee() = default;
	ThirdPartyEmployee(const MyString& firstName, const MyString& secondName,const MyString& password, unsigned IDNumber, unsigned age);
	/*friend std::istream& operator>>(std::istream& ifs, ThirdPartyEmployee* client);
	friend std::ostream& operator<<(std::ostream& ofs, const ThirdPartyEmployee* client);*/
	User* clone()const;
};

