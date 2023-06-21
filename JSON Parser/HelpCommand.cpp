#include "HelpCommand.h"
#include "Constants.h"
#include "CommandsManager.h"

HelpCommand::HelpCommand() : Command(HELP_COMMAND_NAME, HELP_COMMAND_INFO, HELP_COMMAND_DESCRIPTION, HELP_COMMAND_ARGUMENTS_COUNT) {}

void HelpCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	const Vector<SharedPtr<Command>>& allCommands = CommandsManager::getInstance().getCommands();
	size_t allCommandsCount = allCommands.getSize();
	size_t argumentsCount = arguments.getSize();

	if (argumentsCount == 0) {
		for (size_t i = 0; i < allCommandsCount; i++) {
			allCommands[i]->printInfo();
			std::cout << std::endl;
		}
		return;
	}

	for (size_t i = 0; i < allCommandsCount; i++) {
		if (allCommands[i]->getName() == *arguments[i]) {
			allCommands[i]->printDescription();
			return;
		}
	}

	throw std::logic_error("This command is not supported by the help utility.");// -> constants
}
