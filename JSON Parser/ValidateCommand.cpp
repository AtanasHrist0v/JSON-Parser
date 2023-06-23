#include "ValidateCommand.h"
#include "Constants.h"



static void validateSimpleValue(std::ifstream& ifs, char& currentChar) {
	char ch;
	ifs >> ch;

	switch (ch) {
		case DOUBLE_QUOTES_CHAR:
			break;

		default:
			break;
	}
}

static void validateKeyValuePair(std::ifstream& ifs, char& currentChar) {

}

static void validateCompositeValue(std::ifstream& ifs, char& currentChar, char closingBracket) {
	if (currentChar == ARRAY_OPENING_BRACKET) {
		while (currentChar != closingBracket) {
			validateSimpleValue(ifs, currentChar);
		}
	} else {
		while (currentChar != closingBracket) {
			validateKeyValuePair(ifs, currentChar);
		}
	}
}

static void validateJSON(std::ifstream& ifs) {
	char ch;
	ifs >> ch;

	if (!ifs.eof()) {
		switch (ch) {
			case ARRAY_OPENING_BRACKET:
				validateCompositeValue(ifs, ch, ARRAY_CLOSING_BRACKET);
				break;
			case OBJECT_OPENING_BRACKET:
				validateCompositeValue(ifs, ch, OBJECT_CLOSING_BRACKET);
				break;
			default:
				validateSimpleValue(ifs);
				break;
		}
	}
}

ValidateCommand::ValidateCommand() : Command(VALIDATE_COMMAND_NAME, VALIDATE_COMMAND_INFO, VALIDATE_COMMAND_DESCRIPTION, VALIDATE_COMMAND_ARGUMENTS_COUNT) {}

void ValidateCommand::execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const {
	std::ifstream ifs;

	if (arguments.getSize() == 0) {
		ifs.open(filePath.c_str(), std::ios::in);
	} else {
		ifs.open(arguments[0]->c_str(), std::ios::in);
	}

	if (!ifs.is_open()) {
		throw std::logic_error("temp");//TODO
	}

	validateJSON(ifs);

	std::cout << "File is valid." << std::endl;//TODO
}
