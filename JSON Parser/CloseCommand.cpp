#include "CloseCommand.h"
#include "Constants.h"

CloseCommand::CloseCommand() : Command(CLOSE_COMMAND_NAME, CLOSE_COMMAND_INFO, CLOSE_COMMAND_DESCRIPTION, CLOSE_COMMAND_ARGUMENTS_COUNT) {}

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
