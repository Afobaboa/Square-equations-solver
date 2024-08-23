#include <assert.h>
#include <stdio.h>
#include "scanner.h"

/* ERROR HANDLING WILL BE ADDED */


// Get double value from stdin
double GetDoubleValue() {
    double value = 0;
    assert(scanf("%lf", &value) == 1);
    return value;
}


// Get int value from stdin
int GetIntValue() {
    int value = 0;
    assert(scanf("%d", &value) == 1);
    return value;
}


// Clear all input
void ClearInput() {
    int c = getchar();
    while (c != '\n' && c != EOF) 
        c = getchar();
}


// Set equation
squareEquation SetEquation() {
    puts("Для решения уравнения ax^2 + bx + c = 0, введите a, b, c по порядку:");
    squareEquation equation = { .a = 0,
                                .b = 0,
                                .c = 0};

    equation.a = GetDoubleValue();
    equation.b = GetDoubleValue();
    equation.c = GetDoubleValue();
    ClearInput();
    return equation;
}