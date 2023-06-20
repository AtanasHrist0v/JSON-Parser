#include "CloseCommand.h"

CloseCommand::CloseCommand() : Command("close", 0) {}

void CloseCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() != getArgumentsCount()) {
		throw std::logic_error("'close' command takes 0 arguments.");
	}

	if (&(*root) == nullptr) {
		throw std::logic_error("No open file has been found.");
	}

	delete& (*root);
	//&(*root) = nullptr;
	//&(*root) = nullptr;
	filePath = "";
}

void CloseCommand::printDescription(unsigned descriptionAlignment) const {}

void CloseCommand::printInfo() const {}
