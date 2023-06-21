#include <fstream>
#include "OpenCommand.h"
#include "Constants.h"
#include "ValueFactory.h"

OpenCommand::OpenCommand() : Command(OPEN_COMMAND_NAME, "gay", "gay2", OPEN_COMMAND_ARGUMENTS_COUNT) {}

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
