#include <fstream>
#include "OpenCommand.h"
#include "ValueFactory.h"

OpenCommand::OpenCommand() {
	this->name = "open";
	this->argumentsCount = 1;
}

void OpenCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	if (arguments.getSize() != this->argumentsCount) {
		throw std::logic_error("which one of y'all niggas stole my bike?!");
	}

	//std::ofstream ofs("data.txt", std::ios::out);
	std::ifstream ifs(arguments[0]->c_str(), std::ios::in);
	if (!ifs.is_open()) {
		throw std::logic_error("Couldn't open file.");
	}

	root = std::move(valueFactory(ifs));
	filePath = *arguments[0];
	ifs.close();
}

void OpenCommand::printDescription(unsigned descriptionAlignment) const {
	std::cout << this->name;
	size_t padding = descriptionAlignment - this->name.length();
	for (size_t i = 0; i < padding; i++) {
		std::cout << ' ';
	}
	std::cout << "Opens a json file...";//TODO
}

void OpenCommand::printInfo() const {}
