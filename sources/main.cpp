#include <stdio.h>
#include "../headers/io.h"
#include "../headers/solver.h"
#include "../headers/CmdLineArgsHandler.h"


void RunSolving();


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