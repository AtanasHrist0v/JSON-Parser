#pragma once
#include "SharedPtr.hpp"
#include "Value.h"
#include "Vector.hpp"
#include "Command.h"

class JSONParser {
private:
	SharedPtr<Value> root;
	MyString filePath;
	Vector<SharedPtr<Command>> allCommands;

	void executeCommand(const MyString& command, const Vector<SharedPtr<MyString>>& commandArguments, bool& commandIsExit);
public:
	JSONParser();
	void run();
};