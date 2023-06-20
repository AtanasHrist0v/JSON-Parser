#pragma once
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "Command.h"

class CommandsManager {
private:
	Vector<SharedPtr<Command>> commands;

	CommandsManager();
	CommandsManager(const CommandsManager& other) = delete;
	CommandsManager& operator=(const CommandsManager& other) = delete;
public:
	const Vector<SharedPtr<Command>>& getCommands() const;
	static CommandsManager& getInstance();
};