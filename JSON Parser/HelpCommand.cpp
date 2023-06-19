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
