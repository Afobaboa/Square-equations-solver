#include <stdio.h>
#include "../headers/io.h"
#include "../headers/solver.h"
#include "../headers/solverTest.h"
#include "../headers/CmdLineArgsHandlers.h"


/**
 * @file 
 * There are start of my program.
 */


/**
 * Process all options from
 * enum OPTIONS.
 * 
 * @return false if processing isn't OK
 * or there are wrong option code.
 * @return true in other situations.
 */
static bool ProcessOption(option_t option);


/** 
 * Print all available 
 * options and instructions
 * for use.
 */
void PrintHelp();


/**
 * This functions breaks
 * my program and I don't
 * know how to delete if.
 */
void PrintDED();


/**
 * Help user to solve
 * his square equations.
 * 
 * Shows interface in terminal.
 */
static void RunSolving();


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

static void RunSolving() {
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


void PrintHelp() {
    puts("Вас приветствует программа Square Solver!\n"
         "Для пользования программой введитe './squareSolver [ОПЦИЯ]'\n\n"
         "Доступные опции:\n"
         "-help выводит все доступные флаги.\n"
         "-r запускает решение квадратных уравнений\n"
         "-t запускает тестирование.");
}


void PrintDED() {
    for (int i = 0; i < 32; i++)
        printf("бу");
    printf("\n");
}
