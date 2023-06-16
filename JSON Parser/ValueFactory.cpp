#include "ValueFactory.h"
#include "Constants.h"
#include "SimpleValue.h"
#include "KeyValuePair.h"
#include "CompositeValue.h"

SharedPtr<Value> valueFactory(std::istream& is) {
	char firstChar = is.peek();
	
	switch (firstChar) {
		case VALUE_CHAR:
			break;
		case CompositeValue::ARRAY_OPENING_BRACKET:
			break;
		case CompositeValue::OBJECT_OPENING_BRACKET:
			break;
		default:
			break;
	}

	return SharedPtr<Value>();
}
