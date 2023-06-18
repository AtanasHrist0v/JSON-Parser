#include "JSONParser.h"
#include "Constants.h"
#include "OpenCommand.h"
#include "CloseCommand.h"
#include "ExitCommand.h"
#include "PrintCommand.h"
#include <sstream>

//static void clearConsole() {
//	system("cls");
//}
static void pauseConsole() {
	system("pause");
}

static void removeQuotes(char* string) {
	for (size_t i = 0; string[i] != '\0'; i++) {
		if (string[i] == '\"') {
			for (size_t j = i; string[j] != '\0'; j++) {
				string[j] = string[j + 1];
			}
		}
	}
}

void JSONParser::executeCommand(const MyString& command, const Vector<SharedPtr<MyString>>& commandArguments, bool& commandIsExit) {
	static const ExitCommand exitCommand;
	if (command == exitCommand.getName()) {
		try {
			exitCommand.execute(commandArguments, this->root, this->filePath);
			commandIsExit = true;
		} catch (const std::exception& ex) {
			std::cout << "Error! " << ex.what() << std::endl;
		}

		return;
	}

	static const size_t allCommandsCount = this->allCommands.getSize();
	for (size_t i = 0; i < allCommandsCount; i++) {
		if (allCommands[i]->getName() == command) {
			try {
				allCommands[i]->execute(commandArguments, this->root, this->filePath);
			} catch (const std::exception& ex) {
				std::cout << "Error! " << ex.what() << std::endl;
			}
		}
	}
}

JSONParser::JSONParser() {
	this->allCommands.push_back(std::move(SharedPtr<Command>(new OpenCommand)));
	this->allCommands.push_back(std::move(SharedPtr<Command>(new CloseCommand)));
	this->allCommands.push_back(std::move(SharedPtr<Command>(new ExitCommand)));
	this->allCommands.push_back(std::move(SharedPtr<Command>(new PrintCommand)));
}

void JSONParser::run() {
	char userInput[INPUT_MAX_SIZE]{};
	bool commandIsExit = false;

	std::stringstream ss;
	char commandStr[INPUT_MAX_SIZE]{};
	char commandArgumentsStr[INPUT_MAX_SIZE]{};

	Vector<SharedPtr<MyString>> commandArguments;

	while (!commandIsExit) {
		std::cout << '>';
		std::cin.getline(userInput, INPUT_MAX_SIZE);

		ss.str(userInput);
		ss.getline(commandStr, INPUT_MAX_SIZE, ' ');
		commandArguments.clear();
		while (!ss.eof()) {
			ss.getline(commandArgumentsStr, INPUT_MAX_SIZE);
			commandArguments.push_back(std::move(SharedPtr<MyString>(new MyString(commandArgumentsStr))));
		}
		ss.clear();

		executeCommand(commandStr, commandArguments, commandIsExit);
	}
}