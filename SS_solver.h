#ifndef SOLVER_H
#define SOLVER_H


/**
 * @file 
 * This file let
 * you solve square equations. 
 * 
 * Accuracy of calculations
 * is E-5.
 */


#include "SS_squareEquation.h"


/**
 * This function solve 
 * ax^2 + bx + c = 0 equation.
 * 
 * @param equation User's equation.
 * 
 * @return Struct squareEquationRoots from "squareEquation.h". 
 * Accuracy is equal to EPSILON.
 * @return If there are two roots, x1 will be less than x2.
 * @return If there are not two roots, they will be equal to zero. 
*/
squareEquationRoots SolveEquation(squareEquation* equation);


/** 
 * This function used to
 * compare two roots.
 * 
 * @return true if roots are equal.
 * @return false if roots are not equal.
 */
bool IsRootsEqual(squareEquationRoots* firstRoots, squareEquationRoots* secondRoots);


#endif // SOLVER_H