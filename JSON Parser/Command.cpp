#include "Command.h"
#include "Constants.h"

Command::Command(const MyString& name, const MyString& info, const MyString& description, unsigned argumentsCount) : name(name), info(info), description(description), argumentsCount(argumentsCount) {}

Command::Command(MyString&& name, MyString&& info, MyString&& description, unsigned argumentsCount) : name(std::move(name)), info(std::move(info)), description(std::move(description)), argumentsCount(argumentsCount) {}

const MyString& Command::getName() const {
	return this->name;
}

unsigned Command::getArgumentsCount() const {
	return this->argumentsCount;
}

void Command::printInfo() const {
	std::cout << this->info;
}

void Command::printDescription() const {
	std::cout << this->name;
	size_t padding = DESCRIPTION_ALIGNMENT - getName().length();
	for (size_t i = 0; i < padding; i++) {
		std::cout << ' ';
	}
	std::cout << this->description;
}
