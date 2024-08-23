#ifndef PRINTER_H
#define PRINTER_H


#include "squareEquation.h"
#include "SS_errors.h"


void PrintStartMessage();
void PrintEndMessage();
SS_error_t PrintRoots(squareEquationRoots equation);


#endif // PRINTER_H