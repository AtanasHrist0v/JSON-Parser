#include "Number.h"

void Number::print(unsigned tabsCount) const {}

void Number::search(const char* key) const {}

void Number::set(const char* path, const char* value) {}

void Number::create(const char* path, const char* value) {}

void Number::deleteElement(const char* path) {}

void Number::move(const char* from, const char* to) {}

Value* Number::clone() {
	return new Number(*this);
}
