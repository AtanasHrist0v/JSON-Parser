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
	virtual void print(unsigned tabsCount) const override;
	virtual void search(const char* key) const override;
	virtual void set(const char* path, const char* value) override;
	virtual void create(const char* path, const char* value) override;
	virtual void deleteElement(const char* path) override;
	virtual void move(const char* from, const char* to) override;
	virtual Value* clone() override;
};