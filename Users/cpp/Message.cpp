#include "../h/Message.h"

void Message::setMessage(const MyString& text){
	this->text = text;
}

const MyString& Message::getMessage() const
{
	return text;
}

//std::ostream& operator<<(std::ostream& ofs, const Message* message)
//{
//	return ofs;
//}
//
//std::istream& operator>>(std::istream& ifs, Message* message)
//{
//	return ifs;
//}
