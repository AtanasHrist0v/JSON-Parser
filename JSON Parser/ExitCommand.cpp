#include "ExitCommand.h"

ExitCommand::ExitCommand() {
	this->name = "exit";
	this->argumentsCount = 0;
}

void ExitCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	//exit(0);
}

void ExitCommand::printDescription(unsigned descriptionAlignment) const {}

void ExitCommand::printInfo() const {}
