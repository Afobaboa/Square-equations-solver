#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "io.h"
#include "solverTest.h"


static void PrintWrongTest(int testNumber, squareEquationRoots recievedRoots);


// Interface of tests
struct SolverTest {
    squareEquation equation;
    squareEquationRoots expectedRoots;
};


static SolverTest solverTest[] = {
//  {{ a,          b,          c       },   {rootCount,             x1,         x2      }}
    {{ 1,          1,          1       },   {NO_ROOTS,              0,          0       }},  // 0
    {{ 0.000001,   0,          1       },   {NO_ROOTS,              0,          0       }},  // 1
    {{ 0,          0,          0       },   {INFINITE_ROOT_COUNT,   0,          0       }},  // 2
    {{ 0.000001,   5,          0.000001},   {ONE_ROOT,              0,          0       }},  // 3
    {{ 1,         -2,          1       },   {ONE_ROOT,              1,          0       }},  // 4
    {{ 5,          0,          0       },   {ONE_ROOT,              0,          0       }},  // 5
    {{-1.3,        3.434532,  -3       },   {NO_ROOTS,              0,          0       }},  // 6
    {{ 2,          6,          3       },   {TWO_ROOTS,            -2.366025,  -0.633975}},  // 7
    {{-1.234,      323,        323.23  },   {TWO_ROOTS,             262.74732, -0.996915}},  // 8
    {{ 23443,      2345,      -42873   },   {TWO_ROOTS,            -1.403278,   1.303248}},  // 9
    {{ 1,          1,          -12     },   {TWO_ROOTS,             -4,         3       }},  // 10
};


const int testCount = sizeof(solverTest) / sizeof(SolverTest);
    

// Run testing SS_solver
void RunSolverTesting() {
    puts("Testing started.");
    for (int i = 0; i < testCount; i++) {
        squareEquationRoots recievedRoots = SolveEquation(&solverTest[i].equation);
        if (AreRootsEqual(&recievedRoots, &solverTest[i].expectedRoots)) {
            ColoredPrintf(GREEN, "Test %d completed.\n", i);
        } else {
            PrintWrongTest(i, recievedRoots);
            break;
        }
    }
    puts("Testing ended.");
}


static void PrintWrongTest(int testNumber, squareEquationRoots recievedRoots) {
    ColoredPrintf(RED, "Test %d failed!!!\n"
              "Expected roots: x1 = %lg, x2 = %lg, count of roots = %d\n"
              "Resieved roots: x1 = %lg, x2 = %lg, count of roots = %d\n", 
              testNumber,
              solverTest[testNumber].expectedRoots.x1, solverTest[testNumber].expectedRoots.x2, 
                                                       solverTest[testNumber].expectedRoots.rootCount,
              recievedRoots.x1, recievedRoots.x2, recievedRoots.rootCount);
}