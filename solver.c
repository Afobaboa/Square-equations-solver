#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "squareSolver.h"

#define EPSILON 0.000001



static rootCount_t solveLinearEquation(double a, double b, answer_t* answer);
static rootCount_t solveSquareEquation(double a, double b, double c, answer_t* const answer);
static bool isNull(double num);



// Solve ax^2 + bx + c = 0, a CAN be 0
rootCount_t solveEquation(double a, double b, double c, answer_t* answer) {
    if (isNull(a))
        return solveLinearEquation(b, c, answer);
    return solveSquareEquation(a, b, c, answer);
}


// Solve ax^2 + bx + c = 0, a CAN'T be 0
static rootCount_t solveSquareEquation(double a, double b, double c, answer_t* answer) {
    double discr = b*b - 4*a*c;
    if (isNull(discr)) {
        answer[0] = -b / (2*a);
        return ONE_ROOT;
    } else if (discr < 0) 
        return NO_ROOTS;
    else {
        answer[0] = (-b - sqrt(discr)) / (2*a);
        answer[1] = (-b + sqrt(discr)) / (2*a);
        return TWO_ROOTS;
    }
}


// Solve ax + b = 0
static rootCount_t solveLinearEquation(double a, double b, answer_t* answer) {
    if (isNull(a)) 
        if (isNull(b))
            return INFINITE_ROOT_COUNT;
        else
            return NO_ROOTS;
    answer[0] = -b/a;
    return ONE_ROOT;
}


// Is num a double 0?
static bool isNull(double num) {
    if (abs(num) < EPSILON)
        return true;
    return false;
}