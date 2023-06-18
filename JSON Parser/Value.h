#pragma once
#include "MyString.h"
#include "StringView.h"

class Value {
public:
	virtual void print(std::ostream& os, unsigned tabsCount = 0) const = 0;
	virtual void search(const MyString& key) const = 0;
	virtual void set(const StringView& path, const MyString& value) = 0;
	virtual void create(const StringView& path, const MyString& value) = 0;
	virtual void deleteElement(const StringView& path) = 0;
	virtual void move(const StringView& from, const StringView& to) = 0;
	virtual Value* clone() = 0;
	virtual ~Value() = default;
};