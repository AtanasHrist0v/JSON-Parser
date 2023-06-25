#include "HelperFunctions.h"

void printTabs(std::ostream& os, unsigned tabsCount) {
	for (size_t i = 0; i < tabsCount; i++) {
		os << "   ";
	}
}
