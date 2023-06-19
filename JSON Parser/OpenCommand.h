#pragma once
#include "Command.h"

class OpenCommand : public Command {
public:
	OpenCommand();
	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const override;
	virtual void printDescription(unsigned descriptionAlignment) const override;
	virtual void printInfo() const override;
};