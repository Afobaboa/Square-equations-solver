#include <assert.h>
#include <stdio.h>
#include "printer.h"
#include "solver.h"



// Print helloMessage when program starts
void PrintHelloMessage() {
    puts("Эта программа умеет решать квадратные уравнения в вещественных числах! Попоробуй сам!");
}


// Print endMessage when program ends
void PrintEndMessage() {
    puts("Пока!");
}


// Print seletionMessage
void PrintAnswersMessage() {
    puts("Хотите продолжить решать уравнения? Введите нужную цифру.\n"
         "1 - да, хочу продолжить.\n"
         "2 - нет, хочу выйти.\n");
}


// Print roots of user's equation
void PrintRoots(squareEquationRoots roots) {
    switch (roots.rootCount) {
    case INFINITE_ROOT_COUNT: 
        puts("Все действительные числа являются корнями.\n");
        break;
    case NO_ROOTS:
        puts("У данного уравнения нет действительных корней.\n");
        break;
    case ONE_ROOT:
        printf("Корень данного уравнения x = %lg\n", roots.x1);
        break;
    case TWO_ROOTS:
        printf("Корни данного уравнения x1 = %lg, x2 = %lg\n", roots.x1, roots.x2);
        break;
    default:
        fprintf(stderr, "printer.c: ERROR, wrong rootCount type.");
        exit(1);
    }
}