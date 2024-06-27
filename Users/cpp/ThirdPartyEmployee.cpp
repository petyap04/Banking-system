#include "../h/ThirdPartyEmployee.h"

ThirdPartyEmployee::ThirdPartyEmployee(const MyString& firstName, const MyString& secondName,const MyString& password, unsigned IDNumber, unsigned age ) :
                                       User(firstName, secondName, IDNumber, age, password){}

User* ThirdPartyEmployee::clone() const
{
    return new ThirdPartyEmployee(*this);
}

//std::istream& operator>>(std::istream& ifs, ThirdPartyEmployee* client)
//{
//   operator>>(ifs, static_cast<User*>(client));
//   return ifs;
//}
//
//std::ostream& operator<<(std::ostream& ofs, const ThirdPartyEmployee* client)
//{
//    operator<<(ofs, static_cast<const User*>(client));
//    return ofs;
//}
