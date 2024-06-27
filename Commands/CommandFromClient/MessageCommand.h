#pragma once
#include "../CommandFromClient.h"

class MessageCommand : public CommandFromClient {
private:
public:
	void execute()override;
	virtual Command* clone() const;
};