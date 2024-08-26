#ifndef SCANNER_H
#define SCANNER_H


#include "squareEquation.h"



/** 
 * @file 
 * This file used to init int or
 * double values and to set user's equation.
 * 
 * There are depended scanning from stdin.
 */


enum COLORS {
    GREEN,
    RED
};
typedef enum COLORS color_t;


/** 
 * Set coefficients 
 * of square equation.
 * 
 * @param equation squareEquation to set. 
 * 
 * @return true if OK.
 * @return false if EOF is next in stdin
 * 
 * Elements of equation will be zeroes 
 * by default.
 * 
 */
bool SetEquation(squareEquation* equation);


/**
 * Print all roots if equation 
 * according to count of roots.
 * 
 * @param equation User's equation.
 */
void PrintRoots(squareEquationRoots* equation);


int ColoredPrintf(color_t color, const char* format, ...);


#endif // SCANNER_H