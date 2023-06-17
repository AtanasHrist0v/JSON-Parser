#pragma once
#include "SharedPtr.hpp"
#include "Value.h"
#include "Vector.hpp"

class JSONParser {
private:
	SharedPtr<Value> root;
	MyString filePath;

	void executeCommand(const MyString& command, const Vector<SharedPtr<MyString>>& commandArguments, bool& commandIsExit);

	void open(const MyString& filePath);
	void close();
	void save();
	void saveAs();
	void exit();
	void validate() const;

public:
	void run();
};