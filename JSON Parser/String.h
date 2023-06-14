#pragma once
#include "Value.h"
#include "MyString.h"

class String : public Value {
private:
	MyString value;
public:
	virtual void print(unsigned tabsCount) const override;
	virtual void search(const char* key) const override;
	virtual void set(const char* path, const char* value) override;
	virtual void create(const char* path, const char* value) override;
	virtual void deleteElement(const char* path) override;
	virtual void move(const char* from, const char* to) override;
	virtual Value* clone() override;
};