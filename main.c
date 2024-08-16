#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "messages.h"
#include "squareSolver.h"


enum USER_SELECTION {
    CONTINUE,
    EXIT,
    RESELECTION
};
typedef enum USER_SELECTION userSelection_t;


static bool showMenu(answer_t* answer);
static userSelection_t getUserSelection();
static bool processUserSelection(userSelection_t userSelection);
static void printRoots(rootCount_t rootCount, answer_t* answer);


int main() {
    answer_t* const answer = calloc(MAX_ROOT_COUNT, sizeof(double));
    printHelloMessage();
    while(showMenu(answer)); // showMenu() return false if it's end
    printEndMessage();
    free(answer);
    return 0;
}


// Show menu
static bool showMenu(answer_t* answer) {
    bool continueSolving = true; // The resut of this function
    puts("Для решения уравнения ax^2 + bx + c = 0, введите a, b, c по порядку:");
    double a = getDoubleValue();
    double b = getDoubleValue();
    double c = getDoubleValue();
    rootCount_t rootCount = solveEquation(a, b, c, answer);
    printRoots(rootCount, answer);

    userSelection_t userSelection;
    while ((userSelection = getUserSelection()) == RESELECTION) 
        continueSolving = processUserSelection(userSelection);
    return continueSolving;
}


// Process user's selection 
static bool processUserSelection(userSelection_t userSelection) {
    switch (userSelection) {
    case CONTINUE:
        return true;
    case EXIT:
        return false;
    case RESELECTION:
        return false;
    }
}


// Get user selection 
static userSelection_t getUserSelection() {
    printSelectionMessage();
    int userSelection = getIntValue();
    switch (userSelection) {
    case 1: 
        return CONTINUE;
    case 2:
        return EXIT;
    default:
        puts("Такого варианта нет. Попробуйте еще раз.\n");
        return RESELECTION; 
    }
}


// Print roots of user's equation
static void printRoots(rootCount_t rootCount, answer_t* answer) {
    switch (rootCount) {
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
}