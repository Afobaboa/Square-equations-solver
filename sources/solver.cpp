#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include "../headers/solver.h"


/**
 * @file
 * This program used to solve
 * ready equation.
 */


/** 
 * This function solve linear
 * equation. FIRST COEFFICIEN 
 * (a) MUST BE ZERO, else there
 * will be wrong roots.
 * 
 * @return roots of this equation.
 */
static squareEquationRoots SolveLinearEquation(squareEquation* equation);


/** 
 * This function solve square
 * equations, wheer first
 * coefficient HAVE TO BE NOT
 * ZERO.
 * 
 * @return Roots of this equation.
 */
static squareEquationRoots SolveSquareEquation(squareEquation* equation);


/**
 * If there are roots like 0.0000001,
 * this function set they to 0.
 */
static void SetZeroRoots(squareEquationRoots* roots); 


/** 
 * @return Discriminant of square
 * equation. First coefficient (a)
 * have to be not zero.
 */
static double GetDiscriminant(squareEquation equation);


/**
 * Check if value is double zero.
 * EPSILON is used for compare.
 */
static bool IsZero(double value);



/** 
 * This const double is used to copmare double values with zero
 */
static const double EPSILON = 1E-5;


squareEquationRoots SolveEquation(squareEquation* equation) {
    assert(equation);
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


static squareEquationRoots SolveSquareEquation(squareEquation* equation) {
    assert(equation);
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


static squareEquationRoots SolveLinearEquation(squareEquation* equation) {
    assert(equation);
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


static bool IsZero(double value) {
    if (fabs(value) <= EPSILON)
        return true;
    return false;
}


static double GetDiscriminant(squareEquation equation) {
    return equation.b * equation.b  -  4 * equation.a * equation.c;
}


static void SetZeroRoots(squareEquationRoots* roots) {
    assert(roots);
    if (IsZero(roots->x1)) 
        roots->x1 = 0;
    if (IsZero(roots->x2)) 
        roots->x2 = 0;
}


bool AreRootsEqual(squareEquationRoots* firstRoots, squareEquationRoots* secondRoots) {
    assert(firstRoots || secondRoots);
    if (firstRoots->rootCount == secondRoots->rootCount &&
               IsZero(firstRoots->x1 - secondRoots->x1) &&
               IsZero(firstRoots->x2 - secondRoots->x2)   )
            return true;
    return false;
}