#include <stdbool.h>
#include <stdio.h>
#include "SS_solver.h"
#include "solverTest.h"


static void PrintWrongTest(int testNumber, squareEquationRoots recievedRoots);


int main() {
    puts("Testing started.");
    for (int i = 0; i < testCount; i++) {
        squareEquationRoots recievedRoots = SolveEquation(&solverTest[i].equation);
        if (IsRootsEqual(&recievedRoots, &solverTest[i].expectedRoots)) {
            printf("Test %d completed.\n", i);
        } else {
            PrintWrongTest(i, recievedRoots);
            break;
        }
    }
    puts("Testing ended.");

    return 0;
}


void PrintWrongTest(int testNumber, squareEquationRoots recievedRoots) {
    printf("Test %d failed!!!\n"
           "Expected roots: x1 = %lg, x2 = %lg, count of roots = %d\n"
           "Resieved roots: x1 = %lg, x2 = %lg, count of roots = %d\n", 
           testNumber,
           solverTest[testNumber].expectedRoots.x1, solverTest[testNumber].expectedRoots.x2, 
                                                    solverTest[testNumber].expectedRoots.rootCount,
           recievedRoots.x1, recievedRoots.x2, recievedRoots.rootCount);
}