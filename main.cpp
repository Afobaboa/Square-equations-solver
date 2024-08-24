#include <stdio.h>
#include <string.h>
#include "solverTest.h"
#include "io.h"
#include "solver.h"

static void StartSolving();
static void RunSolving();
static void PrintHelp();
static int  GetMaxOptionLength();


const char* OPTIONS[] = {
    "help", 
    "test"
};


const int OPTION_COUNT = sizeof(OPTIONS) / sizeof(OPTIONS[0]);
const int MAX_OPTION_LENGTH = GetMaxOptionLength();


int main(int argc, char* argv[]) {
    int counter = 1;

    while ((argc - counter) > 0 && *(argv + counter)[1] == '-') {
        if (strcmp(*(argv + counter) + 1, "test") == 0) 
            RunSolverTesting();
        if (strcmp(*(argv + counter) + 1, "help") == 0)
            PrintHelp();
        counter++;
    }
    if (argc - counter != 0)
        printf("Wrong! Try \"%s -help\".", argv[0]);

    return 0;
}


// Prints special message if there is -help
void PrintHelp() {
    puts("Доступные опции:\n"
        "-help выводит окошко");
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


// Get max length of options
int GetMaxOptionLength() {
    int maxLength = 0;
    for (int i = 0; i < OPTION_COUNT; i++) {
        int length = strlen(OPTIONS[i]);
        if (length > maxLength)
            maxLength = length;
    }
    return maxLength;
}
    