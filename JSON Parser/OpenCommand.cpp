#include <fstream>
#include "OpenCommand.h"
#include "Constants.h"
#include "ValueFactory.h"

OpenCommand::OpenCommand() : Command(OPEN_COMMAND_NAME, OPEN_COMMAND_INFO, OPEN_COMMAND_DESCRIPTION, OPEN_COMMAND_ARGUMENTS_COUNT) {}

void OpenCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() < getArgumentsCount()) {
		throw std::logic_error("No file to open.");
	}

	if (filePath.length() != 0) {
		std::cout << "A .json object is already loaded into memory. Please use 'close' command first." << std::endl;
		return;
	}

	std::ifstream ifs(arguments[0]->c_str(), std::ios::in);
	if (!ifs.is_open()) {
		throw std::logic_error("Couldn't open file.");
	}

	root = std::move(valueFactory(ifs));
	filePath = *arguments[0];
	ifs.close();

	std::cout << "File successfully read and loaded into memory." << std::endl;
}
