#pragma once

#include "../Users/h/ThirdPartyEmployee.h"
#include "../Users/h/Client.h"
#include "../Users/h/Employee.h"
#include "../Commands/Command.h"
Command* commandFactory(const MyString& command);
Command* userFactory(User* user);
Command* commandClientFactory();
Command* commandEmployeeFactory();
Command* commandThirdPartyEmployeeFactory();

