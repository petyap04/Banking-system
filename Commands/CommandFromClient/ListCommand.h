#pragma once
#include "../CommandFromClient.h"

class ListCommand : public CommandFromClient
{
private:
public:
	void execute()override;
	virtual Command* clone() const;
};

