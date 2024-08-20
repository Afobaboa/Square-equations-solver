#include <assert.h>
#include <stdio.h>
#include "scanner.h"
#include "printer.h"



enum ANSWER {
    CONTINUE,
    EXIT,
    RESELECTION
};
typedef enum ANSWER answer_t;



void RunSolvingLoop();
answer_t GetAnswer();
void ProcessAnswer(answer_t answer);



int main() {
    PrintHelloMessage();
    RunSolvingLoop();
    PrintEndMessage();
    return 0;
}


// Run solving loop until solver exits
void RunSolvingLoop() {
    answer_t answer  = CONTINUE;
    while (answer == CONTINUE || answer == RESELECTION) {
        squareEquation equation = InsertEquation();
        squareEquationRoots roots = SolveEquation(equation);
        PrintRoots(roots);

        do {
            answer = GetAnswer(); // if user want to continue
            ProcessAnswer(answer);
        } while (answer == RESELECTION);    
    }
}


// Process user's selection 
void ProcessAnswer(answer_t answer) {
    assert(answer != CONTINUE || answer != EXIT);
    if (answer == RESELECTION) 
        puts("Такого варианта нет. Попробуем еще раз.");
}


// Get user's answer 
answer_t GetAnswer() {
    PrintAnswersMessage();
    int answer = GetIntValue();
    switch (answer) {
    case 1: 
        return CONTINUE;
    case 2:
        return EXIT;
    default:
        puts("Такого варианта нет. Попробуйте еще раз.\n");
        return RESELECTION; 
    }
}