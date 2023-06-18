#pragma once
#include "Value.h"
#include "MyString.h"

class SimpleValue : public Value {
private:
	MyString value;
public:
	SimpleValue(MyString&& value);

	virtual void print(std::ostream& os, unsigned tabsCount = 0) const override;
	virtual void search(const MyString& key) const override;
	virtual void set(const StringView& path, const MyString& value) override;
	virtual void create(const StringView& path, const MyString& value) override;
	virtual void deleteElement(const StringView& path) override;
	virtual void move(const StringView& from, const StringView& to) override;
	virtual Value* clone() override;
};