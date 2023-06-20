#include <fstream>
#include "OpenCommand.h"
#include "Constants.h"
#include "ValueFactory.h"

OpenCommand::OpenCommand() : Command("open", 1) {}//TODO -> move to Constants.h

void OpenCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() < getArgumentsCount()) {
		throw std::logic_error("No file to open.");
	}

	std::ifstream ifs(arguments[0]->c_str(), std::ios::in);
	if (!ifs.is_open()) {
		throw std::logic_error("Couldn't open file.");
	}

	root = std::move(valueFactory(ifs));
	filePath = *arguments[0];
	ifs.close();
}

void OpenCommand::printDescription(unsigned descriptionAlignment) const {
	std::cout << getName();
	size_t padding = descriptionAlignment - getName().length();
	for (size_t i = 0; i < padding; i++) {
		std::cout << ' ';
	}
	std::cout << "Opens a json file...";//TODO
}

void OpenCommand::printInfo() const {}
