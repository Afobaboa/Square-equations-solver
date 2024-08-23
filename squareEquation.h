#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H


enum ROOT_COUNT 
{
    INFINITE_ROOT_COUNT,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

typedef enum ROOT_COUNT rootCount_t;


/** 
 * @brief This struct contain roots.
 * 
 * @param rootCount Count of roots.
 * @param x1 First root.
 * @param x2 Second root.
 */
struct squareEquationRoots {
    rootCount_t rootCount;
    double x1; 
    double x2;
};


// Equation ax^2 + bx + c = 0
struct squareEquation { 
    double a;
    double b;
    double c;
};


#endif // SQUARE_EQUATION_H