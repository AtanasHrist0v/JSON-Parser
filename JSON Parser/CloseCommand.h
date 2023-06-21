#pragma once
#include "Command.h"

class CloseCommand : public Command {
public:
	CloseCommand();
	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const override;
};