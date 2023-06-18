#include "SimpleValue.h"

SimpleValue::SimpleValue(MyString&& value) : value(std::move(value)) {}

void SimpleValue::print(unsigned tabsCount) const {
	std::cout << this->value;
}

void SimpleValue::search(const MyString& key) const {}

void SimpleValue::set(const StringView& path, const MyString& value) {
	if (path.length() == 0) {
		this->value = value;
	}
}

void SimpleValue::create(const StringView& path, const MyString& value) {}

void SimpleValue::deleteElement(const StringView& path) {}

void SimpleValue::move(const StringView& from, const StringView& to) {}

Value* SimpleValue::clone() {
	return new SimpleValue(*this);
}