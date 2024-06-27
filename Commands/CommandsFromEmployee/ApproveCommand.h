#pragma once
#include "../CommandFromEmployee.h"

class ApproveCommand : public CommandFromEmployee
{
private:
	unsigned ind;
public:
	ApproveCommand(unsigned ind);
	void execute()override;
	virtual Command* clone() const;
};

