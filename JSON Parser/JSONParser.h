#pragma once
#include "SharedPtr.hpp"
#include "Value.h"
#include "Vector.hpp"

class JSONParser {
private:
	SharedPtr<Value> root;
	MyString filePath;

	void executeCommand(const MyString& command, const Vector<SharedPtr<MyString>>& commandArguments, bool& commandIsExit);
public:
	void run();
};