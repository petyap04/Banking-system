#pragma once
#include "../../Helpers/MyString.h"
class Message
{
private:
	MyString text;
public:
	void setMessage(const MyString& text);
	const MyString& getMessage()const;

	/*friend std::ostream& operator<<(std::ostream&, const Message*);
	friend std::istream& operator>>(std::istream&, Message*);*/
};

