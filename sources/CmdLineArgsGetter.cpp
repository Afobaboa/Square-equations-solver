#include <string.h>
#include "../headers/CmdLineArgsHandlers.h"


/**
 * @file 
 * There are functions to get
 * option.
 */


option_t GetOption(const char* option) {
    if (!strcmp(option, "help"))
        return HELP;
    if (!strcmp(option, "r"))
        return RUN;
    if (!strcmp(option, "t"))
        return TEST;
    if (!strcmp(option, "ded"))
        return DED;
    else 
        return WRONG_OPTION;
}


bool AreOptionsCorrect(int argc, char* argv[]) {
    if (argc == 2 && argv[1][0] == '-') 
        return true;
    return false;
}