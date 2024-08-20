#include <stdbool.h>
#include <stdio.h>
#include "scanner.h"

/* ERROR HANDLING WILL BE ADDED */


// Get double value from stdin
double GetDoubleValue() {
    double value = 0;
    scanf("%lf", &value);
    return value;
}


// Get int value from stdin
int GetIntValue() {
    int value = 0;
    scanf("%d", &value);
    return value;
}