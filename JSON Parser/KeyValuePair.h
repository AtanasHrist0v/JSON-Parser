#pragma once
#include "Value.h"
#include "MyString.h"
#include "SharedPtr.hpp"

class KeyValuePair : public Value {
private:
	MyString key;
	SharedPtr<Value> value;
public:
	virtual void print(unsigned tabsCount) const override;
	virtual void search(const char* key) const override;
	virtual void set(const char* path, const char* value) override;
	virtual void create(const char* path, const char* value) override;
	virtual void deleteElement(const char* path) override;
	virtual void move(const char* from, const char* to) override;
	virtual Value* clone() override;
};