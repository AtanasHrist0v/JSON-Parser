#include "ValueFactory.h"
#include "Constants.h"
#include "SimpleValue.h"
#include "KeyValuePair.h"
#include "CompositeValue.h"

static char getClosingBracket(char openingBracket) {
	switch (openingBracket) {
		case ARRAY_OPENING_BRACKET:
			return ARRAY_CLOSING_BRACKET;
		case OBJECT_OPENING_BRACKET:
			return OBJECT_CLOSING_BRACKET;
		default:
			break;
	}

	return openingBracket;
}

SharedPtr<Value> valueFactory(std::istream& is, bool valueIsArray) {
	static bool charIsWhiteSpace = false;

	SharedPtr<Value> value;
	char ch;

	is >> ch;
	if (ch == ',' || ch == ':') {//TODO
		is >> ch;
	}

	switch (ch) {
		case DOUBLE_QUOTES_CHAR:
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 't':
		case 'f':
		case 'n':
		{
			if (valueIsArray) {
				static int pos;
				pos = 0;

				char valueBuff[INPUT_MAX_SIZE]{};

				if (ch == DOUBLE_QUOTES_CHAR) {
					valueBuff[pos++] = DOUBLE_QUOTES_CHAR;
					valueBuff[pos++] = is.peek();
					while (is.peek() != DOUBLE_QUOTES_CHAR) {
						is.get();
						valueBuff[pos++] = is.peek();
					}
					is >> ch;
					is >> ch;
				} else {
					while (ch != ',' && ch != ARRAY_CLOSING_BRACKET && ch != OBJECT_CLOSING_BRACKET) {
						valueBuff[pos++] = ch;
						is >> ch;
					}
				}

				is.seekg(-1, std::ios::cur);

				value = new SimpleValue(valueBuff);

				break;
			}

			static char keyBuff[INPUT_MAX_SIZE]{};	
			is.getline(keyBuff, INPUT_MAX_SIZE, DOUBLE_QUOTES_CHAR);

			value = new KeyValuePair(keyBuff, valueFactory(is));
		}
		break;
		case ARRAY_OPENING_BRACKET:
		case OBJECT_OPENING_BRACKET:
		{
			Vector<SharedPtr<Value>> data;
			char openingBracket = ch;
			char closingBracket = getClosingBracket(ch);

			do {
				data.push_back(std::move(valueFactory(is, ch == ARRAY_OPENING_BRACKET)));
				is >> ch;
			} while (ch != closingBracket);

			value = new CompositeValue(std::move(data), openingBracket, closingBracket);	
		}
		break;
		default:
			throw std::logic_error("JSON file is not in the correct format!");
			break;
	}

	return value;
}