#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "solver.h"
#include "scanner.h"



static squareEquationRoots SolveLinearEquation(squareEquation equation);
static squareEquationRoots SolveSquareEquation(squareEquation equation);
static bool IsNull(double num);
static double GetDiscriminant(squareEquation equation);



// Solve ax^2 + bx + c = 0, a CAN be 0
squareEquationRoots SolveEquation(squareEquation equation) {
    if (IsNull(equation.a))
        return SolveLinearEquation(equation);
    return SolveSquareEquation(equation);
}


// Solve ax^2 + bx + c = 0, a CAN'T be 0
static squareEquationRoots SolveSquareEquation(squareEquation equation) {
    squareEquationRoots roots;
    double D = GetDiscriminant(equation);
    if (IsNull(D)) {
        roots.x1 = -equation.b / (2*equation.a);
        roots.rootCount = ONE_ROOT;
    } else if (D < 0) 
        roots.rootCount = NO_ROOTS;
    else {
        roots.x1 = (-equation.b - sqrt(D)) / (2*equation.a);
        roots.x2 = (-equation.b + sqrt(D)) / (2*equation.a);
        roots.rootCount = TWO_ROOTS;
    }
}


// Solve bx + c = 0
static squareEquationRoots SolveLinearEquation(squareEquation equation) {
    squareEquationRoots roots;
    if (IsNull(equation.b)) 
        if (IsNull(equation.c))
            roots.rootCount = INFINITE_ROOT_COUNT;
        else
            roots.rootCount = NO_ROOTS;
    else {
        roots.x1 = -equation.c / equation.b;
        roots.rootCount = ONE_ROOT;
    }
}


// Is num a double 0?
static bool IsNull(double num) {
    if (fabs(num) < EPSILON)
        return true;
    return false;
}


// Get discriminant of equation
static double GetDiscriminant(squareEquation equation) {
    return equation.b * equation.b  -  4 * equation.a * equation.c;
}


// Insert equation
squareEquation InsertEquation() {
    puts("Для решения уравнения ax^2 + bx + c = 0, введите a, b, c по порядку:");
    squareEquation equation;
    equation.a = GetDoubleValue();
    equation.b = GetDoubleValue();
    equation.c = GetDoubleValue();
}