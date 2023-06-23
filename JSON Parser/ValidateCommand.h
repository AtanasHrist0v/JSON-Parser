#pragma once
#include "Command.h"

class ValidateCommand : public Command {
public:
	ValidateCommand();
	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const;
};