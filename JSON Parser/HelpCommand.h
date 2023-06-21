#pragma once
#include "Command.h"

class HelpCommand : public Command {
public:
	HelpCommand();
	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const override;
};