#include "String.h"

void String::print(unsigned tabsCount) const {
	std::cout << '"' << this->value << '"';
}

void String::search(const char* key) const {

}

void String::set(const char* path, const char* value) {

}

void String::create(const char* path, const char* value) {

}

void String::deleteElement(const char* path) {

}

void String::move(const char* from, const char* to) {

}

Value* String::clone() {
	return new String(*this);
}
