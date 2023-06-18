#include "ExitCommand.h"

ExitCommand::ExitCommand() {
	this->name = "exit";
	this->argumentsCount = 0;
}

void ExitCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() != this->argumentsCount) {
		throw std::logic_error("which one of y'all niggas stole my bike?!");
	}
}
