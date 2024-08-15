#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "messages.h"
#include "squareSolver.h"


bool showMenu(answer_t* answer);


int main() {
    answer_t* const answer = calloc(MAX_ROOT_COUNT, sizeof(double));
    helloMessage();
    while(showMenu(answer)); // showMenu() return false if it's end
    endMessage();
    free(answer);
    return 0;
}


// Show menu
bool showMenu(answer_t* answer) {
    puts("Для решения уравнения ax^2 + bx + c = 0, введите a, b, c по порядку:");
    double a = getDoubleValue();
    double b = getDoubleValue();
    double c = getDoubleValue();
    rootCount_t rootCount = solveEquation(a, b, c, answer);

    switch (rootCount) { /* Will be added separate function */
    case INFINITE_ROOT_COUNT: 
        puts("Все действительные числа являются корнями.\n");
        break;
    case NO_ROOTS:
        puts("У данного уравнения нет действительных корней.\n");
        break;
    case ONE_ROOT:
        printf("Корни данного уравнения x = %f\n", answer[0]);
        break;
    case TWO_ROOTS:
        printf("Корни данного уравнения x1 = %f, x2 = %f\n", answer[0], answer[1]);
        break;
    }

    puts("Хотите продолжить решать уравнения? Введите нужную цифру.\n" /* Will be used messages.h */
         "1 - да, хочу продолжить.\n"
         "2 - нет, хочу выйти.\n");
    int userSelection = getIntValue();
    switch (userSelection) {
    case 1: 
        return true;
    case 2:
        return false;
    default: /* Reselection will be added in separate function */
        puts("Такого варианта нет. Предположим, вы хотите продолжить...\n");
        return true; 
    }
}