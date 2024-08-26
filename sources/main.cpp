#include <string.h>
#include <stdio.h>
#include "../headers/solverTest.h"
#include "../headers/CmdLineArgsHandlers.h"


static bool     AreOptionsCorrect(int argc, char* argv[]);
static option_t GetOption(const char* option);
static bool     ProcessOption(option_t option);


int main(int argc, char* argv[]) {
    if (!AreOptionsCorrect(argc, argv)) {
        PrintHelp();
    }

    int counter = 1;
    while (argc > counter && argv[counter][0] == '-') {
        option_t option = GetOption(argv[counter] + 1);
        if (!ProcessOption(option)) {
            PrintHelp();
            break;
        }
        counter++;
    }

    return 0;
}


// Convert option from char* to option_t
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


// Process option
// If option have to be only one,
// false will be returned
bool ProcessOption(option_t option) {
    switch (option) {
    case HELP:
        PrintHelp();
        return true;
    case RUN:
        RunSolving();
        return true;
    case TEST:
        RunSolverTesting();
        return true;
    case DED:
        PrintDED();
        return true;
    case WRONG_OPTION:
        return false;
    default:    
        fprintf(stderr, "ProcessOneOption(): ERROR, option doesn't exist.\n");
        return false;
    }
}


// Check if options correct
static bool AreOptionsCorrect(int argc, char* argv[]) {
    if (argc == 2 && argv[1][0] == '-') 
        return true;
    return false;
}
