#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "solverTest.h"
#include "io.h"
#include "solver.h"


enum OPTIONS {
    HELP,
    TEST,
    WRONG_OPTION
};
typedef enum OPTIONS option_t;


static void     RunSolving();
static void     PrintHelp();
static option_t GetOption(const char* option);
static bool     ProcessOption(option_t option);


int main(int argc, char* argv[]) {
    int counter = 1;

    if (argc == 1)
        RunSolving();
    else {
        while ((argc - counter) > 0  && *(argv + counter)[0] == '-') {
            option_t option = GetOption(++*(argv + counter));
            if (!ProcessOption(option))
                break;
            counter++;
        }
    }
    if (argc - counter != 0)
        printf("Неправильная опция! Попробуйте \"%s -help\".\n", argv[0]);

    return 0;
}


// Prints special message if there is -help
void PrintHelp() {
    puts("Доступные опции:\n"
         "-help выводит окошко.\n"
         "-t запускает тестирование.");
    puts("\nДля решения квадратных уравнений запустите программу без опций.");
}


// Run solving 
void RunSolving() {
    puts("# Эта программа умеет решать квадратные уравнения "
         "в вещественных числах! Попоробуй сам!\n"
         "# Для выхода нажмите ctrl+D. ");

    squareEquation equation = { .a = 0,
                                .b = 0,
                                .c = 0};

    for(;;) {
        if (!SetEquation(&equation))
            break;
        squareEquationRoots roots = SolveEquation(&equation);
        PrintRoots(&roots);
        puts("# Для выхода нажмите ctrl+D.");
    }

    puts("# Пока!");
}


// Convert option from char* to option_t
option_t GetOption(const char* option) {
    if (!strcmp(option, "help"))
        return HELP;
    if (!strcmp(option, "t"))
        return TEST;
    else 
        return WRONG_OPTION;
}


// Process option
bool ProcessOption(option_t option) {
    switch (option) {
    case HELP:
        PrintHelp();
        return true;
    case TEST:
        RunSolverTesting();
        return true;
    case WRONG_OPTION:
        return false;
    default:    
        fprintf(stderr, "main.cpp: ProcessOption(): ERROR, option doesn't exist.\n");
        return false;
    }
}