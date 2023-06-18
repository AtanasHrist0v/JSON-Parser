#pragma once
#include "Value.h"
#include "MyString.h"
#include "SharedPtr.hpp"

class KeyValuePair : public Value {
private:
	MyString key;
	SharedPtr<Value> value;
public:
	KeyValuePair(MyString&& key, SharedPtr<Value>&& value);

	virtual void print(unsigned tabsCount = 0) const override;
	virtual void search(const MyString& key) const override;
	virtual void set(const StringView& path, const MyString& value) override;
	virtual void create(const StringView& path, const MyString& value) override;
	virtual void deleteElement(const StringView& path) override;
	virtual void move(const StringView& from, const StringView& to) override;
	virtual Value* clone() override;
};