#include "SimpleValue.h"

void SimpleValue::print(unsigned tabsCount) const {
	std::cout << this->value;
}

void SimpleValue::search(const char* key) const {}

void SimpleValue::set(const char* path, const char* value) {}

void SimpleValue::create(const char* path, const char* value) {}

void SimpleValue::deleteElement(const char* path) {}

void SimpleValue::move(const char* from, const char* to) {}

Value* SimpleValue::clone() {
	return new SimpleValue(*this);
}