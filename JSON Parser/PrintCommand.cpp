#include "PrintCommand.h"

PrintCommand::PrintCommand() : Command("print", 0) {}

void PrintCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	root->print(std::cout);
	std::cout << std::endl;
}

void PrintCommand::printDescription(unsigned descriptionAlignment) const {}

void PrintCommand::printInfo() const {}
