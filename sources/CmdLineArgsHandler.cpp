#include <stdio.h>
#include <string.h>
#include "../headers/CmdLineArgsHandler.h"
#include "../headers/solverTest.h"


static void PrintDED();


// Prints special message if there is -help
void PrintHelp() {
    puts("Вас приветствует программа Square Solver!\n"
         "Для пользования программой введитe './squareSolver [ОПЦИЯ]'\n\n"
         "Доступные опции:\n"
         "-help выводит все доступные флаги.\n"
         "-r запускает решение квадратных уравнений\n"
         "-t запускает тестирование.");
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


// Easter egg
static void PrintDED() {
    for (int i = 0; i < 32; i++)
        printf("бу");
    printf("\n");
}


// Check if options correct
bool AreOptionsCorrect(int argc, char* argv[]) {
    if (argc == 2 && argv[1][0] == '-') 
        return true;
    return false;
}
