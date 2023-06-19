#include "HelpCommand.h"

HelpCommand::HelpCommand() {
	this->name = "help";
	this->argumentsCount = 0;
}

void HelpCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	std::cout << "open" << std::endl;
	std::cout << "close" << std::endl;
	std::cout << "print" << std::endl;
	std::cout << "exit" << std::endl;
}

void HelpCommand::printDescription(unsigned descriptionAlignment) const {
	std::cout << this->name;
	size_t padding = descriptionAlignment - this->name.length();
	for (size_t i = 0; i < padding; i++) {
		std::cout << ' ';
	}
	std::cout << "Provides Help information for JSON Parser commands." << std::endl;
}

void HelpCommand::printInfo() const {}
