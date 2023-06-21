#include "SaveCommand.h"
#include "Constants.h"

SaveCommand::SaveCommand() : Command(SAVE_COMMAND_NAME, SAVE_COMMAND_INFO, SAVE_COMMAND_DESCRIPTION, SAVE_COMMAND_ARGUMENTS_COUNT) {}

void SaveCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	//if (arguments.getSize() != this->argumentsCount) {
	//	if (arguments.getSize() == 0)
	//	{

	//	} else if ()
	//}{}

	////std::ofstream ofs("data.txt", std::ios::out);
	//std::ifstream ofs(arguments[0]->c_str(), std::ios::in);
	//if (!ifs.is_open()) {
	//	throw std::logic_error("Couldn't open file.");
	//}

	//root = std::move(valueFactory(ifs));
	//filePath = *arguments[0];
	//ifs.close();
}
