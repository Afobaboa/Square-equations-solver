#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "io.h"


#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"


static bool IsInputClear();
static bool IsFinite(double value);
static bool IsEquationFinite(squareEquation* equation);
static bool IsEOF();
static void ClearInput();
static void PrintWrongInputMessage();


// Clear all stdin
static void ClearInput() {
    int c = getchar();
    while (c != '\n' && c != EOF) 
        c = getchar();
}


// Set user's equation
bool SetEquation(squareEquation* equation) {
    puts("# Для решения уравнения ax^2 + bx + c = 0, введите a, b, c по порядку:");

    while (scanf("%lg %lg %lg", &equation->a, &equation->b, &equation->c) != 3 || 
                                                !IsEquationFinite(equation) ||
                                                            !IsInputClear()   ) {
        if (IsEOF())
            return false;
        PrintWrongInputMessage();
        ClearInput();
    }
    return true;
}


// Is there any input?
static bool IsInputClear() {
    int c = 0;
    do {
        c = getchar();
        if (c == EOF || c == '\n') {
            return true;
        }
    } while (isspace(c));
    return false;
}


// Print roots of user's equation
void PrintRoots(squareEquationRoots* roots) {
    switch (roots->rootCount) {
    case INFINITE_ROOT_COUNT: 
        puts("# Все действительные числа являются корнями.\n\n");
        break;
    case NO_ROOTS:
        puts("# У данного уравнения нет действительных корней.\n\n");
        break;
    case ONE_ROOT:
        printf("# Корень данного уравнения x = %lg\n\n", roots->x1);
        break;
    case TWO_ROOTS:
        printf("# Корни данного уравнения x1 = %lg, x2 = %lg\n\n", roots->x1, roots->x2);
        break;
    default:
        fprintf(stderr, "SS_io.cpp: printRoots(): ERROR, wrong rootCount type.\n");
        break;
    }
}


// Print this message if input is wrong
static void PrintWrongInputMessage() {
    puts("# Неверный ввод. Попробуйте ввести все сначала.");
}


// If coefficients of equation are finite?
bool IsEquationFinite(squareEquation* equation) {
    bool result = true;
    if (!IsFinite(equation->a))
        result = false;
    if (!IsFinite(equation->b))
        result = false;
    if (!IsFinite(equation->c))
        result = false;
    return result;
}


// Is double value finite?
static bool IsFinite(double value) {
    if (!isfinite(value) || isinf(value)) {
        return false;
    }
    return true;
}


// If EOF is next in stdin?
static bool IsEOF() {
    int c = getchar();
    if (c == EOF)
        return true;
    return false;
}


// printf() but text is GREEN
int GreenPrintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf(COLOR_GREEN);
    int result = vprintf(format, args);
    printf(COLOR_RESET);
    va_end(args);
    return result;
}


// printf() but text is RED
int RedPrintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf(COLOR_RED);
    int result = vprintf(format, args);
    printf(COLOR_RESET);
    va_end(args);
    return result;
}