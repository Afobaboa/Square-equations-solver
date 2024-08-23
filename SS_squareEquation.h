#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H


/** 
 * @file 
 * There is interface to
 * work with square equations.
 */


/** 
 * There are root count codes.
 */
enum ROOT_COUNT {
    NO_ROOTS = 0,               /**< Equation has't any roots. */
    ONE_ROOT = 1,               /**< Equation has one root. */
    TWO_ROOTS = 2,              /**< Equation has two roots. */
    INFINITE_ROOT_COUNT     /**< Equation has infinity of roots. */
};

typedef enum ROOT_COUNT rootCount_t;


/** 
 * This struct contain roots.
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


/** 
 * There is square equation ax^2 + bx + c = 0.
 * 
 * @param a Coef before x^2.
 * @param b Coef before x.
 * @param c Free coef.
 */
struct squareEquation { 
    double a;
    double b;
    double c;
};


#endif // SQUARE_EQUATION_H