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


/**
 * This colores used for
 * ColoredPrintf() to set
 * needed color.
 */
enum COLORS {
    GREEN,   /**< Green color. */
    RED,     /**< Red color. */
    YELLOW,  /**< Yellow color */
    WHITE    /**< White color */
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


/**
 * This function is similary
 * to printf(), but this function
 * can print colored text.
 * 
 * @param color Color of text. You have
 * to use something from enum COLORS.
 * @param format Format of your text.
 * You have to use printf() format
 * 
 * Other arguments used for subtitution
 * to format. You have to use as many
 * arguments as you us in format, like 
 * in printf().
 * 
 * @return Count of used other arguments.
 */
int ColoredPrintf(color_t color, const char* format, ...);


#endif // SCANNER_H