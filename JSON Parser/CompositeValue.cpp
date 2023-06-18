#include "CompositeValue.h"

static void printTabs(unsigned tabsCount) {
	for (size_t i = 0; i < tabsCount; i++) {
		std::cout << "   ";
	}
}
static void printWhiteSpace(char openingBracket) {
	switch (openingBracket) {
		case CompositeValue::ARRAY_OPENING_BRACKET:

			break;
		case CompositeValue::OBJECT_OPENING_BRACKET:

			break;
		default:
			break;
	}
}

CompositeValue::CompositeValue(Vector<SharedPtr<Value>>&& data, const char openingBracket, const char closingBracket) : data(std::move(data)), openingBracket(openingBracket), closingBracket(closingBracket) {}

void CompositeValue::print(unsigned tabsCount) const {//TODO
	if (this->openingBracket == CompositeValue::OBJECT_OPENING_BRACKET) {
		printTabs(tabsCount);
		std::cout << this->openingBracket << std::endl;

		size_t vectorSize = this->data.getSize();
		for (size_t i = 0; i < vectorSize; i++) {
			this->data[i]->print(tabsCount + 1);
			if (i != vectorSize - 1) {
				std::cout << ',' << std::endl;
			}
		}

		std::cout << std::endl;
		printTabs(tabsCount);
		std::cout << this->closingBracket;
	} else {
		std::cout << this->openingBracket << std::endl;

		size_t vectorSize = this->data.getSize();
		for (size_t i = 0; i < vectorSize; i++) {
			this->data[i]->print(tabsCount + 1);
			if (i != vectorSize - 1) {
				std::cout << ',' << std::endl;
			}
		}

		std::cout << std::endl;
		printTabs(tabsCount);
		std::cout << this->closingBracket;
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