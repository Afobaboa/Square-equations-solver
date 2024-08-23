#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include "solver.h"


squareEquationRoots SolveLinearEquation(squareEquation equation);
squareEquationRoots SolveSquareEquation(squareEquation equation);
bool IsZero(double num);
double GetDiscriminant(squareEquation equation);


const double EPSILON = 1E-5;


squareEquationRoots SolveEquation(squareEquation equation) {
    if (IsZero(equation.a))
        return SolveLinearEquation(equation);
    return SolveSquareEquation(equation);
}


// Solve ax^2 + bx + c = 0, a CAN'T be 0
squareEquationRoots SolveSquareEquation(squareEquation equation) {
    squareEquationRoots roots = { .rootCount = NO_ROOTS,
                                  .x1 = 0,
                                  .x2 = 0};

    double D = GetDiscriminant(equation);
    if (IsZero(D)) {
        roots.x1 = -equation.b / (2*equation.a);
        roots.rootCount = ONE_ROOT;
    } else if (D < 0) 
        roots.rootCount = NO_ROOTS;
    else {
        double sqrtD = sqrt(D);
        roots.x1 = (-equation.b - sqrtD) / (2*equation.a);
        roots.x2 = (-equation.b + sqrtD) / (2*equation.a);
        roots.rootCount = TWO_ROOTS;
    } 
    return roots;
}


// Solve bx + c = 0
squareEquationRoots SolveLinearEquation(squareEquation equation) {
    squareEquationRoots roots = { .rootCount = NO_ROOTS,
                                  .x1 = 0,
                                  .x2 = 0};

    if (IsZero(equation.b)) 
        if (IsZero(equation.c))
            roots.rootCount = INFINITE_ROOT_COUNT;
        else
            roots.rootCount = NO_ROOTS;
    else {
        roots.x1 = -equation.c / equation.b;
        roots.rootCount = ONE_ROOT;
    }
    return roots;
}


// Is num a double 0?
bool IsZero(double num) {
    if (fabs(num) < EPSILON)
        return true;
    return false;
}


// Get discriminant of equation
double GetDiscriminant(squareEquation equation) {
    return equation.b * equation.b  -  4 * equation.a * equation.c;
}