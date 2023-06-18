#pragma once
#include "Value.h"
#include "Vector.hpp"
#include "SharedPtr.hpp"

class CompositeValue : public Value {
private:
	Vector<SharedPtr<Value>> data;
	char openingBracket;
	char closingBracket;
public:
	CompositeValue(Vector<SharedPtr<Value>>&& data, char openingBracket, char closingBracket);

	static const char ARRAY_OPENING_BRACKET = '[';
	static const char ARRAY_CLOSING_BRACKET = ']';
	static const char OBJECT_OPENING_BRACKET = '{';
	static const char OBJECT_CLOSING_BRACKET = '}';

	virtual void print(unsigned tabsCount = 0) const override;
	virtual void search(const MyString& key) const override;
	virtual void set(const StringView& path, const MyString& value) override;
	virtual void create(const StringView& path, const MyString& value) override;
	virtual void deleteElement(const StringView& path) override;
	virtual void move(const StringView& from, const StringView& to) override;
	virtual Value* clone() override;
};