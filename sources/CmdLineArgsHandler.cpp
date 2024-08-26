#include <stdio.h>
#include "../headers/io.h"
#include "../headers/solver.h"
#include "../headers/CmdLineArgsHandlers.h"


// Prints special message if there is -help
void PrintHelp() {
    puts("Вас приветствует программа Square Solver!\n"
         "Для пользования программой введитe './squareSolver [ОПЦИЯ]'\n\n"
         "Доступные опции:\n"
         "-help выводит все доступные флаги.\n"
         "-r запускает решение квадратных уравнений\n"
         "-t запускает тестирование.");
}


// Easter egg
void PrintDED() {
    for (int i = 0; i < 32; i++)
        printf("бу");
    printf("\n");
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