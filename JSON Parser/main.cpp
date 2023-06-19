#include "JSONParser.h"

int main() {
	{
		int* ptr = new int(1);
		JSONParser parser;
		parser.run();
		char* ch = new char('A');
	}
	_CrtDumpMemoryLeaks();
}