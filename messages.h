#ifndef MESSAGES_H
#define MESSAGES_H



void printHelloMessage();
void printEndMessage();
void printSelectionMessage();


// Print helloMessage when program starts
void printHelloMessage() {
    puts("Эта программа умеет решать квадратные уравнения в вещественных числах! Попоробуй сам!");
}


// Print endMessage when program ends
void printEndMessage() {
    puts("Пока!");
}


// Print seletionMessage
void printSelectionMessage() {
    puts("Хотите продолжить решать уравнения? Введите нужную цифру.\n"
         "1 - да, хочу продолжить.\n"
         "2 - нет, хочу выйти.\n");
}



#endif // MESSAGES_H