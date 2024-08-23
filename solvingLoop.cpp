#include <assert.h>
#include <stdio.h>
#include "scanner.h"
#include "solver.h"
#include "printer.h"


enum CONTINUE_STATUS {
    CONTINUE,
    EXIT,
    RESELECTION
};

typedef enum CONTINUE_STATUS continueStatus_t;



void RunSolvingLoop();
continueStatus_t GetContinueStatus();
void ProcessContinueStatus(continueStatus_t continueStatus);



// Run solving loop until solver exits
void RunSolvingLoop() {
    PrintStartMessage();

    continueStatus_t continueStatus  = CONTINUE;
    while (continueStatus == CONTINUE || continueStatus == RESELECTION) {
        const squareEquation equation = SetEquation();
        squareEquationRoots roots = SolveEquation(equation);

        if (PrintRoots(roots) == WRONG_ROOT_COUNT)
            break;

        do {
            continueStatus = GetContinueStatus(); // if user want to continue
            ClearInput();
            ProcesscontinueStatus(continueStatus);
        } while (continueStatus == RESELECTION);    
    }

    PrintEndMessage();
}


// Process user's selection 
void ProcesscontinueStatus(continueStatus_t continueStatus) {
    assert(continueStatus != CONTINUE || continueStatus != EXIT);
    if (continueStatus == RESELECTION)
        puts("Такого варианта нет. Попробуем еще раз.");
}


// Get user's continueStatus 
continueStatus_t GetContinueStatus() {
    puts("Хотите продолжить решать уравнения? Введите нужную цифру.\n"
         "1 - да, хочу продолжить.\n"
         "2 - нет, хочу выйти.\n");

    int continueStatus = GetIntValue();
    switch (continueStatus) {
    case 1: 
        return CONTINUE;
    case 2:
        return EXIT;
    default:
        puts("Такого варианта нет. Попробуйте еще раз.\n");
        return RESELECTION; 
    }
}
