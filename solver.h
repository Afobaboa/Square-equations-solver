#ifndef SOLVER_H
#define SOLVER_H



const int MAX_ROOT_COUNT = 2;
const double EPSILON = 0.000001;


enum ROOT_COUNT {
    INFINITE_ROOT_COUNT,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};
typedef enum ROOT_COUNT rootCount_t;


struct squareEquationRoots {
    rootCount_t rootCount = NO_ROOTS;
    double x1 = 0; 
    double x2 = 0;
};


// Equation ax^2 + bx + c = 0
struct squareEquation { 
    int a = 0;
    int b = 0;
    int c = 0;
};


squareEquationRoots SolveEquation(squareEquation equation);
squareEquation InsertEquation();


#endif // SOLVER_H