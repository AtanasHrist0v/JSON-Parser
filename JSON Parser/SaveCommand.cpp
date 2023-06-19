#include "SaveCommand.h"

SaveCommand::SaveCommand() {
	this->name = "print";
	this->argumentsCount = 1;
}

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
