#include "ExitCommand.h"
#include "Constants.h"

ExitCommand::ExitCommand() : Command(EXIT_COMMAND_NAME, EXIT_COMMAND_INFO, EXIT_COMMAND_DESCRIPTION, EXIT_COMMAND_ARGUMENTS_COUNT) {}

void ExitCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	exit(0);
}
