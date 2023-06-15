#include "SimpleValue.h"

void SimpleValue::print(unsigned tabsCount) const {
	std::cout << this->value;
}

void SimpleValue::search(const MyString& key) const {}

void SimpleValue::set(const StringView& path, const MyString& value) {}

void SimpleValue::create(const StringView& path, const MyString& value) {}

void SimpleValue::deleteElement(const StringView& path) {}

void SimpleValue::move(const StringView& from, const StringView& to) {}

Value* SimpleValue::clone() {
	return new SimpleValue(*this);
}