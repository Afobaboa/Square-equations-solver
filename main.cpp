#include <stdio.h>
#include "SS_io.h"
#include "SS_solver.h"


static void RunSolvingLoop();


int main() {
    puts("# Эта программа умеет решать квадратные уравнения "
         "в вещественных числах! Попоробуй сам!\n"
         "# Для выхода нажмите ctrl+D. ");

    RunSolvingLoop();

    puts("# Пока!");
    return 0;
}


// Run solving loop
void RunSolvingLoop() {
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
}