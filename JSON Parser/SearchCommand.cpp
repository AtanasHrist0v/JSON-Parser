#include "SearchCommand.h"

SearchCommand::SearchCommand() : Command("search", 1) {}

void SearchCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() != getArgumentsCount()) {
		throw std::logic_error("Search command takes 1 argument.");
	}

	if (&(*root) == nullptr) {
		throw std::logic_error("No json file has been loaded.");
	}

	root->search(*arguments[0]);
}

void SearchCommand::printDescription(unsigned descriptionAlignment) const {}

void SearchCommand::printInfo() const {}
