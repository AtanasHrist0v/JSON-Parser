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
	if (ch == ',' || ch == ':') {
		is >> ch;
	}

	switch (ch) {
		case VALUE_CHAR:
		{
			if (valueIsArray) {
				static char valueBuff[INPUT_MAX_SIZE]{};

				is.getline(valueBuff, INPUT_MAX_SIZE, VALUE_CHAR);
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