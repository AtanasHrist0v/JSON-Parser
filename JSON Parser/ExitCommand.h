#pragma once
#include "Command.h"

class ExitCommand : public Command {
public:
	ExitCommand();
	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const override;
};