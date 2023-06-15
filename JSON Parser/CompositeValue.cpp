#include "CompositeValue.h"

void CompositeValue::print(unsigned tabsCount) const {
	std::cout << this->openingBracket << std::endl;

	size_t vectorSize = this->data.getSize();
	for (size_t i = 0; i < vectorSize; i++) {
		this->data[i]->print(tabsCount + 1);
	}

	std::cout << std::endl << this->closingBracket;
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