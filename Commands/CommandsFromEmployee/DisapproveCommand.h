#pragma once
#include "../CommandFromEmployee.h"

class DisapproveCommand : public CommandFromEmployee
{
private:
	unsigned ind;
public:
	DisapproveCommand(unsigned ind);
	void execute()override;
	virtual Command* clone() const;
};

