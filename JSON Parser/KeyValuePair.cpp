#include "KeyValuePair.h"

void KeyValuePair::print(unsigned tabsCount) const {
	std::cout << '"' << this->key << "\" : ";
	this->value->print(tabsCount + 1);
}

void KeyValuePair::search(const MyString& key) const {
	if (strcmp(key, this->key.c_str()) == 0) {
		print();
		return;
	}

}

void KeyValuePair::set(const StringView& path, const MyString& value) {}

void KeyValuePair::create(const StringView& path, const MyString& value) {}

void KeyValuePair::deleteElement(const StringView& path) {}

void KeyValuePair::move(const StringView& from, const StringView& to) {}

Value* KeyValuePair::clone() {
	return new KeyValuePair(*this);
}