#include "CompositeValue.h"
#include "Constants.h"
#include "HelperFunctions.h"

CompositeValue::CompositeValue(Vector<SharedPtr<Value>>&& data, char openingBracket, char closingBracket) : data(std::move(data)), openingBracket(openingBracket), closingBracket(closingBracket) {}

void CompositeValue::print(std::ostream& os, unsigned tabsCount) const {//TODO
	if (this->openingBracket == OBJECT_OPENING_BRACKET) {
		printTabs(os, tabsCount);
		os << this->openingBracket << std::endl;

		size_t vectorSize = this->data.getSize();
		for (size_t i = 0; i < vectorSize; i++) {
			this->data[i]->print(os, tabsCount + 1);
			if (i != vectorSize - 1) {
				os << ',' << std::endl;
			}
		}

		os << std::endl;
		printTabs(os, tabsCount);
		os << this->closingBracket;
	} else {
		os << this->openingBracket << std::endl;

		size_t vectorSize = this->data.getSize();
		for (size_t i = 0; i < vectorSize; i++) {
			this->data[i]->print(os, tabsCount + 1);
			if (i != vectorSize - 1) {
				os << ',' << std::endl;
			}
		}

		os << std::endl;
		printTabs(os, tabsCount);
		os << this->closingBracket;
	}
}

void CompositeValue::search(const MyString& key) const {
	size_t vectorSize = this->data.getSize();
	for (size_t i = 0; i < vectorSize; i++) {
		this->data[i]->search(key);
	}
}

void CompositeValue::set(const StringView& path, const MyString& value) {
	size_t vectorSize = this->data.getSize();
	for (size_t i = 0; i < vectorSize; i++) {
		this->data[i]->set(path, value);
	}
}

void CompositeValue::create(const StringView& path, const MyString& value) {}

void CompositeValue::deleteElement(const StringView& path) {}

void CompositeValue::move(const StringView& from, const StringView& to) {}

Value* CompositeValue::clone() {
	return new CompositeValue(*this);
}