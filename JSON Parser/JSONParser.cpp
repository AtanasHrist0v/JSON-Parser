#include "JSONParser.h"
#include "Constants.h"
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
	if (command == OPEN_COMMAND) {
		//open(commandArguments);
	} else if (command == EXIT_COMMAND) {
		exit();
		commandIsExit = true;
	} /*else {
		std::cout << INVALID_INPUT << std::endl;
		pauseConsole();
	}*/

	if (&(*(this->root)) != nullptr) {
		if (command == CLOSE_COMMAND) {
			close();
		} else if (command == SAVE_COMMAND) {
			save();
		} else if (command == SAVE_AS_COMMAND) {
			saveAs();
		} else if (command == VALIDATE_COMMAND) {
			validate();
		} else if (command == PRINT_COMMAND) {
			this->root->print();
		} else if (command == SEARCH_COMMAND) {
			//this->root->search(commandArguments);
		} else if (command == SET_COMMAND) {
			//std::stringstream ss(commandArguments.c_str());
			//char path[INPUT_MAX_SIZE]{};
			//char value[INPUT_MAX_SIZE]{};

			//ss.getline(path, INPUT_MAX_SIZE, ' ');
			//ss.getline(value, INPUT_MAX_SIZE);
			//removeQuotes(path);
			//removeQuotes(value);

			//StringView pathView(path);

			//this->root->set(pathView, value);
		} else if (command == CREATE_COMMAND) {

		} else if (command == DELETE_COMMAND) {

		} else if (command == MOVE_COMMAND) {

		}
	}
	
	// TODO
	//else {
	//	std::cout << INVALID_INPUT << std::endl;
	//	pauseConsole();
	//}
}

void JSONParser::open(const MyString& filePath) {
	this->filePath = filePath;
}

void JSONParser::close() {}

void JSONParser::save() {}

void JSONParser::saveAs() {}

void JSONParser::exit() {}

void JSONParser::validate() const {
	std::ifstream ifs(this->filePath.c_str(), std::ios::in);

	ifs.close();
}


void JSONParser::run() {
	char userInput[INPUT_MAX_SIZE]{};
	bool commandIsExit = false;

	std::stringstream ss;
	char command[INPUT_MAX_SIZE]{};
	char commandArguments[INPUT_MAX_SIZE]{};

	while (!commandIsExit) {
		std::cout << '>';
		std::cin.getline(userInput, INPUT_MAX_SIZE);

		ss.str(userInput);
		ss.getline(command, INPUT_MAX_SIZE, ' ');
		ss.getline(commandArguments, INPUT_MAX_SIZE);

		//executeCommand(command, commandArguments, commandIsExit);
	}
}