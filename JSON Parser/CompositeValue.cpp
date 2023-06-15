#include "CompositeValue.h"

void CompositeValue::print(unsigned tabsCount) const {}

void CompositeValue::search(const char* key) const {}

void CompositeValue::set(const char* path, const char* value) {}

void CompositeValue::create(const char* path, const char* value) {}

void CompositeValue::deleteElement(const char* path) {}

void CompositeValue::move(const char* from, const char* to) {}

Value* CompositeValue::clone() {
	return nullptr;
}
