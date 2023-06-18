#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "Value.h"

class Command {
protected:
	MyString name = "";
	unsigned argumentsCount = 0;
public:
	const MyString& getName() const;
	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const = 0;
	virtual ~Command() = default;
};