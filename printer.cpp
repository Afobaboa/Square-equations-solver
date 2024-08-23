#include <assert.h>
#include <stdio.h>
#include "printer.h"



// Print helloMessage when program starts
void PrintStartMessage() {
    puts("Эта программа умеет решать квадратные уравнения в вещественных числах! Попоробуй сам!");
}


// Print endMessage when program ends
void PrintEndMessage() {
    puts("Пока!");
}





// Print roots of user's equation
SS_error_t PrintRoots(squareEquationRoots roots) {
    switch (roots.rootCount) {
    case INFINITE_ROOT_COUNT: 
        puts("Все действительные числа являются корнями.\n");
        return OK;
    case NO_ROOTS:
        puts("У данного уравнения нет действительных корней.\n");
        return OK;
    case ONE_ROOT:
        printf("Корень данного уравнения x = %lg\n", roots.x1);
        return OK;
    case TWO_ROOTS:
        printf("Корни данного уравнения x1 = %lg, x2 = %lg\n", roots.x1, roots.x2);
        return OK;
    default:
        fprintf(stderr, "printer.c: ERROR, wrong rootCount type.");
        return WRONG_ROOT_COUNT;
    }
}