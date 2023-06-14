#include "KeyValuePair.h"

void KeyValuePair::print(unsigned tabsCount) const {

}

void KeyValuePair::search(const char* key) const {

}

void KeyValuePair::set(const char* path, const char* value) {

}

void KeyValuePair::create(const char* path, const char* value) {}

void KeyValuePair::deleteElement(const char* path) {}

void KeyValuePair::move(const char* from, const char* to) {}

Value* KeyValuePair::clone() {
	return new KeyValuePair(*this);
}
