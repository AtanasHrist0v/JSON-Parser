#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "Value.h"

class Command {
private:
	const MyString name;
	const MyString info;
	const MyString description;
	unsigned argumentsCount;
public:
	Command(const MyString& name, const MyString& info, const MyString& description, unsigned argumentsCount);
	Command(MyString&& name, MyString&& info, MyString&& description, unsigned argumentsCount);
	virtual ~Command() = default;

	const MyString& getName() const;
	unsigned getArgumentsCount() const;

	virtual void execute(const Vector<SharedPtr<MyString>>& arguments, SharedPtr<Value>& root, MyString& filePath) const = 0;
	virtual void printInfo() const;
	virtual void printDescription() const;
};