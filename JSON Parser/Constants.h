#pragma once

const char VALUE_CHAR = '\"';

const size_t INPUT_MAX_SIZE = 1024;
const size_t DESCRIPTION_ALIGNMENT = 10;

const char OPEN_COMMAND_NAME[] = "open";
const char OPEN_COMMAND_INFO[] = "Opens a .json file and loads it into memory.";
const char OPEN_COMMAND_DESCRIPTION[] = "OPEN_COMMAND_DESCRIPTION";
const unsigned OPEN_COMMAND_ARGUMENTS_COUNT = 1;

const char CLOSE_COMMAND_NAME[] = "close";
const char CLOSE_COMMAND_INFO[] = "CLOSE_COMMAND_INFO";
const char CLOSE_COMMAND_DESCRIPTION[] = "CLOSE_COMMAND_DESCRIPTION";
const unsigned CLOSE_COMMAND_ARGUMENTS_COUNT = 0;

const char SAVE_COMMAND_NAME[] = "save";
const char SAVE_COMMAND_INFO[] = "SAVE_COMMAND_INFO";
const char SAVE_COMMAND_DESCRIPTION[] = "SAVE_COMMAND_DESCRIPTION";
const unsigned SAVE_COMMAND_ARGUMENTS_COUNT = 0;

const char SAVE_AS_COMMAND_NAME[] = "save as";
const char SAVE_AS_COMMAND_INFO[] = "SAVE_AS_COMMAND_INFO";
const char SAVE_AS_COMMAND_DESCRIPTION[] = "SAVE_AS_COMMAND_DESCRIPTION";
const unsigned SAVE_AS_COMMAND_ARGUMENTS_COUNT = 0;

const char HELP_COMMAND_NAME[] = "help";
const char HELP_COMMAND_INFO[] = "HELP_COMMAND_INFO";
const char HELP_COMMAND_DESCRIPTION[] = "HELP_COMMAND_DESCRIPTION";
const unsigned HELP_COMMAND_ARGUMENTS_COUNT = 1;

const char EXIT_COMMAND_NAME[] = "exit";
const char EXIT_COMMAND_INFO[] = "EXIT_COMMAND_INFO";
const char EXIT_COMMAND_DESCRIPTION[] = "EXIT_COMMAND_DESCRIPTION";
const unsigned EXIT_COMMAND_ARGUMENTS_COUNT = 0;

const char VALIDATE_COMMAND_NAME[] = "validate";

const char PRINT_COMMAND_NAME[] = "print";
const char PRINT_COMMAND_INFO[] = "PRINT_COMMAND_INFO";
const char PRINT_COMMAND_DESCRIPTION[] = "PRINT_COMMAND_DESCRIPTION";
const unsigned PRINT_COMMAND_ARGUMENTS_COUNT = 0;

const char SEARCH_COMMAND_NAME[] = "search";
const char SEARCH_COMMAND_INFO[] = "SEARCH_COMMAND_INFO";
const char SEARCH_COMMAND_DESCRIPTION[] = "SEARCH_COMMAND_DESCRIPTION";
const unsigned SEARCH_COMMAND_ARGUMENTS_COUNT = 1;

const char SET_COMMAND_NAME[] = "set";
const char CREATE_COMMAND_NAME[] = "create";
const char DELETE_COMMAND_NAME[] = "delete";
const char MOVE_COMMAND_NAME[] = "move";

const char INVALID_INPUT[] = "Invalid input!";