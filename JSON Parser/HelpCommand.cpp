#include "HelpCommand.h"
#include "CommandsManager.h"

HelpCommand::HelpCommand() : Command("help", 1) {}

void HelpCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	const Vector<SharedPtr<Command>>& allCommands = CommandsManager::getInstance().getCommands();
	size_t allCommandsCount = allCommands.getSize();
	size_t argumentsCount = arguments.getSize();

	if (argumentsCount == 0) {
		for (size_t i = 0; i < allCommandsCount; i++) {
			allCommands[i]->printDescription(10);//TODO -> remove magic number
			std::cout << std::endl;
		}
		return;
	}

	for (size_t i = 0; i < allCommandsCount; i++) {
		if (allCommands[i]->getName() == *arguments[i]) {
			allCommands[i]->printInfo();
			return;
		}
	}

	throw std::logic_error("This command is not supported by the help utility.");
}

void HelpCommand::printDescription(unsigned descriptionAlignment) const {
	std::cout << getName();
	size_t padding = descriptionAlignment - getName().length();
	for (size_t i = 0; i < padding; i++) {
		std::cout << ' ';
	}
	std::cout << "Provides Help information for JSON Parser commands." << std::endl;
}

void HelpCommand::printInfo() const {}
