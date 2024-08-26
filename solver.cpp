#include <math.h>
#include <stdbool.h>
#include "solver.h"


static squareEquationRoots SolveLinearEquation(squareEquation* equation);
static squareEquationRoots SolveSquareEquation(squareEquation* equation);
static void                SetZeroRoots(squareEquationRoots* roots); 
static double              GetDiscriminant(squareEquation equation);
static bool                IsZero(double value);



// This const double is used to copmare double values with zero
static const double EPSILON = 1E-5;


// Solve ax^2 + bx + c = 0 equation, a can be zero
squareEquationRoots SolveEquation(squareEquation* equation) {
    squareEquationRoots roots = { .rootCount = NO_ROOTS,
                                  .x1 = 0,
                                  .x2 = 0};

    if (IsZero(equation->a))
        roots = SolveLinearEquation(equation);
    else
        roots = SolveSquareEquation(equation);

    SetZeroRoots(&roots);
    return roots;
}


// Solve ax^2 + bx + c = 0 equation, a CAN'T be zero
static squareEquationRoots SolveSquareEquation(squareEquation* equation) {
    squareEquationRoots roots = { .rootCount = NO_ROOTS,
                                  .x1 = 0,
                                  .x2 = 0};

    double D = GetDiscriminant(*equation);
    if (IsZero(D)) {
        roots.x1 = -equation->b / (2*equation->a);
        roots.rootCount = ONE_ROOT;
    } else if (D < 0) 
        roots.rootCount = NO_ROOTS;
    else {
        double sqrtD = sqrt(D);
        roots.x1 = (-equation->b - sqrtD) / (2*equation->a);
        roots.x2 = (-equation->b + sqrtD) / (2*equation->a);
        roots.rootCount = TWO_ROOTS;
    } 
    return roots;
}


// Solve bx + c = 0
static squareEquationRoots SolveLinearEquation(squareEquation* equation) {
    squareEquationRoots roots = { .rootCount = NO_ROOTS,
                                  .x1 = 0,
                                  .x2 = 0};

    if (IsZero(equation->b)) 
        if (IsZero(equation->c))
            roots.rootCount = INFINITE_ROOT_COUNT;
        else
            roots.rootCount = NO_ROOTS;
    else {
        roots.x1 = -equation->c / equation->b;
        roots.rootCount = ONE_ROOT;
    }
    return roots;
}


// Is value a double 0?
static bool IsZero(double value) {
    if (fabs(value) <= EPSILON)
        return true;
    return false;
}


// Get discriminant of square equation
static double GetDiscriminant(squareEquation equation) {
    return equation.b * equation.b  -  4 * equation.a * equation.c;
}


// If roots are less than EPSILON
// they will be change to 0.0
static void SetZeroRoots(squareEquationRoots* roots) {
    if (IsZero(roots->x1)) 
        roots->x1 = 0;
    if (IsZero(roots->x2)) 
        roots->x2 = 0;
}


// Reurn true if roots are equal, else rutern false
bool AreRootsEqual(squareEquationRoots* firstRoots, squareEquationRoots* secondRoots) {
    if (firstRoots->rootCount == secondRoots->rootCount &&
               IsZero(firstRoots->x1 - secondRoots->x1) &&
               IsZero(firstRoots->x2 - secondRoots->x2)   )
            return true;
    return false;
}