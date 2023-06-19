#include "ValueFactory.h"
#include "Constants.h"
#include "SimpleValue.h"
#include "KeyValuePair.h"
#include "CompositeValue.h"

static char getClosingBracket(char openingBracket) {
	switch (openingBracket) {
		case CompositeValue::ARRAY_OPENING_BRACKET:
			return CompositeValue::ARRAY_CLOSING_BRACKET;
		case CompositeValue::OBJECT_OPENING_BRACKET:
			return CompositeValue::OBJECT_CLOSING_BRACKET;
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
		case VALUE_CHAR:
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

				if (ch == VALUE_CHAR) {
					valueBuff[pos++] = VALUE_CHAR;
					valueBuff[pos++] = is.peek();
					while (is.peek() != VALUE_CHAR) {
						is.get();
						valueBuff[pos++] = is.peek();
					}
					is >> ch;
					is >> ch;
				} else {
					while (ch != ',' && ch != CompositeValue::ARRAY_CLOSING_BRACKET && ch != CompositeValue::OBJECT_CLOSING_BRACKET) {
						valueBuff[pos++] = ch;
						is >> ch;
					}
				}

				is.seekg(-1, std::ios::cur);

				value = new SimpleValue(valueBuff);

				break;
			}

			static char keyBuff[INPUT_MAX_SIZE]{};
			is.getline(keyBuff, INPUT_MAX_SIZE, VALUE_CHAR);

			value = new KeyValuePair(keyBuff, valueFactory(is));
		}
		break;
		case CompositeValue::ARRAY_OPENING_BRACKET:
		case CompositeValue::OBJECT_OPENING_BRACKET:
		{
			Vector<SharedPtr<Value>> data;
			char openingBracket = ch;
			char closingBracket = getClosingBracket(ch);

			do {
				data.push_back(std::move(valueFactory(is, ch == CompositeValue::ARRAY_OPENING_BRACKET)));
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