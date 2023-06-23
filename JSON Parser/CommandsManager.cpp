#include "CommandsManager.h"
#include "OpenCommand.h"
#include "CloseCommand.h"
#include "SaveCommand.h"
#include "HelpCommand.h"
#include "ExitCommand.h"
#include "ValidateCommand.h"
#include "PrintCommand.h"
#include "SearchCommand.h"

CommandsManager::CommandsManager() {
	this->commands.push_back(std::move(SharedPtr<Command>(new OpenCommand)));
	this->commands.push_back(std::move(SharedPtr<Command>(new CloseCommand)));
	this->commands.push_back(std::move(SharedPtr<Command>(new SaveCommand)));
	this->commands.push_back(std::move(SharedPtr<Command>(new HelpCommand)));
	this->commands.push_back(std::move(SharedPtr<Command>(new ExitCommand)));
	this->commands.push_back(std::move(SharedPtr<Command>(new ValidateCommand)));
	this->commands.push_back(std::move(SharedPtr<Command>(new PrintCommand)));
	this->commands.push_back(std::move(SharedPtr<Command>(new SearchCommand)));
}

const Vector<SharedPtr<Command>>& CommandsManager::getCommands() const {
	return this->commands;
}

CommandsManager& CommandsManager::getInstance() {
	static CommandsManager manager;
	return manager;
}
