#include "Command.h"

Command::Command(const MyString& name, unsigned argumentsCount) : name(name), argumentsCount(argumentsCount) {}

Command::Command(MyString&& name, unsigned argumentsCount) : name(std::move(name)), argumentsCount(argumentsCount) {}

const MyString& Command::getName() const {
    return this->name;
}

unsigned Command::getArgumentsCount() const {
    return this->argumentsCount;
}
