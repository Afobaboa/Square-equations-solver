#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "solverTest.h"
#include "io.h"
#include "solver.h"


enum OPTIONS {
    HELP,
    RUN,
    TEST,
    DED,
    WRONG_OPTION
};
typedef enum OPTIONS option_t;


static void     PrintDED();
static void     RunSolving();
static void     PrintHelp();
static option_t GetOption(const char* option);
static bool     ProcessOption(option_t option);
static bool     AreOptionsCorrect(int argc, char* argv[]);


int main(int argc, char* argv[]) {
    if (AreOptionsCorrect(argc, argv)) {
        int counter = 1;
        while ((argc - counter) > 0  && argv[counter][0] == '-') {
            option_t option = GetOption(argv[counter] + 1);
            if (!ProcessOption(option)) {
                PrintHelp();
                break;
            }
            counter++;
        }
    } else
        PrintHelp();

    return 0;
}


// Prints special message if there is -help
static void PrintHelp() {
    puts("Вас приветствует программа Square Solver!\n"
         "Для пользования программой введиту './squareSolver [ОПЦИЯ]'\n\n"
         "Доступные опции:\n"
         "-help выводит все доступные флаги.\n"
         "-r запускает решение квадратных уравнений\n"
         "-t запускает тестирование.");
    puts("\nДля решения квадратных уравнений запустите программу без опций.");
}


// Run solving 
static void RunSolving() {
    puts("# Эта программа умеет решать квадратные уравнения "
         "в вещественных числах! Попоробуй сам!\n"
         "# Для выхода нажмите ctrl+D. ");

    squareEquation equation = { .a = 0,
                                .b = 0,
                                .c = 0};

    for(;;) {
        if (!SetEquation(&equation)) {
            puts("RunSolving(): ERROR, can't set equation.");
            break;
        }
        squareEquationRoots roots = SolveEquation(&equation);
        PrintRoots(&roots);
        puts("# Для выхода нажмите ctrl+D.");
    }

    puts("# Пока!");
}


// Convert option from char* to option_t
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


// Process option
// If option have to be only one,
// false will be returned
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
        fprintf(stderr, "main.cpp: ProcessOption(): ERROR, option doesn't exist.\n");
        return false;
    }
}


// Easter egg
static void PrintDED() {
    for (int i = 0; i < 32; i++)
        printf("бу");
    printf("\n");
}


static bool AreOptionsCorrect(int argc, char* argv[]) {
    if (argc == 2 && argv[1][0] == '-') 
        return true;
    return false;
}