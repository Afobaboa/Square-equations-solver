#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../headers/io.h"


/** 
 * @file 
 * This program used 
 * to get users input 
 * and write something
 * to terminal.
 */


/** defines used to set colors 
 * for ColoredPrint() and 
 * PrintColor().
 */
#define COLOR_RED    "\x1b[31m"
#define COLOR_GREEN  "\x1b[32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_WHITE  "\033[1;37m"
#define COLOR_RESET  "\x1b[0m"


/**
 * Check is stdin clear until
 * EOF or '\n' (until nearest 
 * symbol).
 * 
 * @return true if there are only 
 * spaces between begin of stdin 
 * and nearest '\n' or EOF,
 * @return false in other situations.
 */
static bool IsInputClear();


/**
 * Check if value is finit 
 * (not +-inf or nan).
 * 
 * @return true if value is finite,
 * @return false in other situations.
 */
static bool IsFinite(double value);


/**
 * This function chek if coefficients
 * of equation are finite (not +-inf or nan)
 * 
 * @return true if they are finite,
 * @return false in other situatiions.
 */
static bool IsEquationFinite(squareEquation* equation);


/**
 * This functions chek if
 * next char in stdin is EOF.
 * 
 * @return true if there is EOF,
 * @return false in other situations.
 */
static bool IsEOF();


/**
 * Clear all chars from stdin 
 * until '\n' or EOF isn't here
 */
static void ClearInput();


/**
 * Print special message if user 
 * write input in wrong format.
 */
static void PrintWrongInputMessage();


/** 
 * Print needed color (used defines).
 * 
 * This function used to make 
 * ColoredPrintf() more universal.
 */
static void PrintColor(color_t color);


static void ClearInput() {
    int c = getchar();
    while (c != '\n' && c != EOF) 
        c = getchar();
}


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
        fprintf(stderr, "%s: %s(): ERROR at line %d, wrong rootCount type.\n",
                                              __FILE__, __FUNCTION__, __LINE__);
        break;
    }
}


static void PrintWrongInputMessage() {
    puts("# Неверный ввод. Попробуйте ввести все сначала.");
}


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


static bool IsFinite(double value) {
    if (!isfinite(value) || isinf(value)) {
        return false;
    }
    return true;
}


static bool IsEOF() {
    int c = getchar();
    if (c == EOF)
        return true;
    return false;
}


int ColoredPrintf(color_t color, const char* format, ...) {
    va_list args;
    va_start(args, format);

    PrintColor(color);
    int result = vprintf(format, args);
    printf(COLOR_RESET);
    
    va_end(args);
    return result;
}


void PrintColor(color_t color) {
    switch(color) {
    case GREEN:
        printf(COLOR_GREEN);
        break;
    case RED:
        printf(COLOR_RED);
        break;
    case YELLOW:
        printf(COLOR_YELLOW);
        break;
    case WHITE:
        printf(COLOR_WHITE);
        break;
    default: 
        fprintf(stderr, "%s: %s(): ERROR at line %d, wrong color.",
                                 __FILE__, __FUNCTION__, __LINE__);
        break;
    }
}