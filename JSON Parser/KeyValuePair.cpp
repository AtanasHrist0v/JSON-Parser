#include "KeyValuePair.h"
#include "HelperFunctions.h"
#include "ValueFactory.h"
#include <sstream>

KeyValuePair::KeyValuePair(MyString&& key, SharedPtr<Value>&& value) : key(std::move(key)), value(std::move(value)) {}

void KeyValuePair::print(std::ostream& os, unsigned tabsCount) const {
	printTabs(os, tabsCount);
	os << '"' << this->key << "\": ";
	this->value->print(os, tabsCount + 1);
}

void KeyValuePair::search(const MyString& key) const {//TODO regular expression search
	if (key == this->key) {
		this->value->print(std::cout);
		std::cout << std::endl;
	} else {
		this->value->search(key);
	}
}

void KeyValuePair::set(const StringView& path, const MyString& value) {
	if (path == this->key) {
		std::stringstream ss(value.c_str());
		this->value = std::move(valueFactory(ss));
	} else {
		//TODO
	}
}

void KeyValuePair::create(const StringView& path, const MyString& value) {}

void KeyValuePair::deleteElement(const StringView& path) {}

void KeyValuePair::move(const StringView& from, const StringView& to) {}

Value* KeyValuePair::clone() {
	return new KeyValuePair(*this);
}