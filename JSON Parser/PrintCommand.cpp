#include "PrintCommand.h"

PrintCommand::PrintCommand() {
	this->name = "print";
	this->argumentsCount = 0;
}

void PrintCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	root->print(std::cout);
	std::cout << std::endl;
}
