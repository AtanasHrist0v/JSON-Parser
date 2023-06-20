#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "Value.h"

class Command {
private:
	MyString name;
	unsigned argumentsCount;
public:
	Command(const MyString& name, unsigned argumentsCount);
	Command(MyString&& name, unsigned argumentsCount);

	const MyString& getName() const;
	unsigned getArgumentsCount() const;

	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const = 0;
	virtual void printDescription(unsigned descriptionAlignment) const = 0;
	virtual void printInfo() const = 0;
	virtual ~Command() = default;
};