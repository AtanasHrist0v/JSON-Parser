#include "CloseCommand.h"

CloseCommand::CloseCommand() {
	this->name = "close";
	this->argumentsCount = 0;
}

void CloseCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() != this->argumentsCount) {
		throw std::logic_error("which one of y'all niggas stole my bike?!");
	}

	if (&(*root) == nullptr) {
		throw std::logic_error("No open file has been found.");
	}

	delete &(*root);
	filePath = "";
}