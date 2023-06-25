#include "SaveCommand.h"
#include "Constants.h"

SaveCommand::SaveCommand() : Command(SAVE_COMMAND_NAME, SAVE_COMMAND_INFO, SAVE_COMMAND_DESCRIPTION, SAVE_COMMAND_ARGUMENTS_COUNT) {}

void SaveCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	std::ofstream ofs(filePath.c_str(), std::ios::out);
	if (!ofs.is_open()) {
		throw std::logic_error("Couldn't open file.");
	}

	root->print(ofs);
	ofs.close();
}
