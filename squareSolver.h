#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H



#define MAX_ROOT_COUNT 2


enum ROOT_COUNT {
    INFINITE_ROOT_COUNT,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};


typedef double answer_t;
typedef enum ROOT_COUNT rootCount_t;


rootCount_t solveEquation(double a, double b, double c, answer_t* answer);
double getDoubleValue();
int getIntValue();



#endif // SQUARE_SOLVER_H