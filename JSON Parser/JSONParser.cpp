#include "JSONParser.h"
#include "Constants.h"
#include "CommandsManager.h"
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
	static const Vector<SharedPtr<Command>>& allCommands = CommandsManager::getInstance().getCommands();
	static const size_t allCommandsCount = allCommands.getSize();

	for (size_t i = 0; i < allCommandsCount; i++) {
		if (allCommands[i]->getName() == command) {
			try {
				allCommands[i]->execute(commandArguments, this->root, this->filePath);
			} catch (const std::exception& ex) {
				std::cout << "Error! " << ex.what() << std::endl;
			}
			return;
		}
	}

	std::cout << "No such command." << std::endl;
}

void JSONParser::run() {
	char userInput[INPUT_MAX_SIZE]{};
	bool commandIsExit = false;

	std::stringstream ss;
	char commandStr[INPUT_MAX_SIZE]{};
	char commandArgumentsStr[INPUT_MAX_SIZE]{};

	Vector<SharedPtr<MyString>> commandArguments;

	while (!commandIsExit) {
		std::cout << "> ";
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