#include "../h/Check.h"

bool Check::isValid(const MyString& code)
{
	if (code.getSize() == 3) {
		for (int i = 0; i < 3; i++) {
			if (code[i] >= '0' && code[i] <= '9') {
				continue;
			}
			if (code[i] >= 'a' && code[i] <= 'z') {
				continue;
			}
			if (code[i] >= 'A' && code[i] <= 'Z') {
				continue;
			}
			return false;
		}
		return true;
	}
	return false;
}

Check::Check(const MyString& code, double money, unsigned Id) {
	if (money < 0) {
		throw std::exception("Money cannot be negative number");
	}
	if (isValid(code)) {
		this->code = code;
		this->money = money;
		this->Id = Id;
	}
	else {
		throw std::exception("The cod is not valid");
	}
}

Check::Check(const MyString& code, unsigned Id) {
	if (isValid(code)) {
		this->code = code;
		this->Id = Id;
	}
	else {
		throw std::exception("The cod is not valid");
	}
}

const MyString& Check::getCode()const {
	return code;
}

double Check::getMoney()const {
	return money;
}

unsigned Check::getId()const {
	return Id;
}


bool operator==(const Check& lhs, const Check& rhs) {
	return lhs.getCode() == rhs.getCode() && lhs.getId() == rhs.getId();
}

bool operator!=(const Check& lhs, const Check& rhs) {
	return !(lhs == rhs);
}