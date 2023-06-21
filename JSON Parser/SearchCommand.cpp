#include "SearchCommand.h"
#include "Constants.h"

SearchCommand::SearchCommand() : Command(SEARCH_COMMAND_NAME, SEARCH_COMMAND_INFO, SEARCH_COMMAND_DESCRIPTION, SEARCH_COMMAND_ARGUMENTS_COUNT) {}

void SearchCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() != getArgumentsCount()) {
		throw std::logic_error("Search command takes 1 argument.");
	}

	if (&(*root) == nullptr) {
		throw std::logic_error("No json file has been loaded.");
	}

	root->search(*arguments[0]);
}
