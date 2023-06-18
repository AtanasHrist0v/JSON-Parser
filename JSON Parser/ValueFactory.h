#pragma once
#include "SharedPtr.hpp"
#include "Value.h"

SharedPtr<Value> valueFactory(std::istream& is, bool valueIsArray = true);