#pragma once

class Value {
	virtual void print(unsigned tabsCount = 0) const = 0;
	virtual void search(const char* key) const = 0;
	virtual void set(const char* path, const char* value) = 0;
	virtual void create(const char* path, const char* value) = 0;
	virtual void deleteElement(const char* path) = 0;
	virtual void move(const char* from, const char* to) = 0;
	virtual Value* clone() = 0;
	virtual ~Value() = default;
};