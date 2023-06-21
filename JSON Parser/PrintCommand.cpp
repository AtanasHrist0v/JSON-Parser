#include "PrintCommand.h"
#include "Constants.h"

PrintCommand::PrintCommand() : Command(PRINT_COMMAND_NAME, PRINT_COMMAND_INFO, PRINT_COMMAND_DESCRIPTION, PRINT_COMMAND_ARGUMENTS_COUNT) {}

void PrintCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	root->print(std::cout);
	std::cout << std::endl;
}
