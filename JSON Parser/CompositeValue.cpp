#include "CompositeValue.h"

void CompositeValue::print(unsigned tabsCount) const {
	std::cout << this->openingBracket << std::endl;

	size_t vectorSize = this->data.getSize();
	for (size_t i = 0; i < vectorSize; i++) {
		this->data[i]->print(tabsCount + 1);
	}

	std::cout << std::endl << this->closingBracket;
}

void CompositeValue::search(const char* key) const {

}

void CompositeValue::set(const char* path, const char* value) {

}

void CompositeValue::create(const char* path, const char* value) {

}

void CompositeValue::deleteElement(const char* path) {

}

void CompositeValue::move(const char* from, const char* to) {

}

Value* CompositeValue::clone() {
	return new CompositeValue(*this);
}
