#include <string.h>
#include <stdio.h>
#include "../headers/solverTest.h"
#include "../headers/CmdLineArgsHandlers.h"


/**
 * @file 
 * There are start of my program.
 */


/**
 * Check if options format is OK.
 * Now the rules say you can't 
 * use more than 1 option.
 * 
 * You can change format rules 
 * in future.
 * 
 * @return true if rules 
 */
static bool AreOptionsCorrect(int argc, char* argv[]);


/**
 * Return next option from stdin.
 * Yout shoult process this option 
 * before getting next option.
 * 
 * @return Real option if it exists,
 * @return WRONG_OPTION if it doesn't 
 * exist.
 */
static option_t GetOption(const char* option);


/**
 * Process all options from
 * enum OPTIONS.
 * 
 * @return false if processing isn't OK
 * or there are wrong option code.
 * @return true in other situations.
 */
static bool ProcessOption(option_t option);


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


static option_t GetOption(const char* option) {
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


static bool ProcessOption(option_t option) {
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


static bool AreOptionsCorrect(int argc, char* argv[]) {
    if (argc == 2 && argv[1][0] == '-') 
        return true;
    return false;
}
