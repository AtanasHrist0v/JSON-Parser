#include "ExitCommand.h"

ExitCommand::ExitCommand() : Command("exit", 0) {}

void ExitCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	exit(0);
}

void ExitCommand::printDescription(unsigned descriptionAlignment) const {}

void ExitCommand::printInfo() const {}
