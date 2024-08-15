#ifndef MESSAGES_H
#define MESSAGES_H



void helloMessage();
void endMessage();


// Print helloMessage when program starts
void helloMessage() {
    puts("Эта программа умеет решать квадратные уравнения в вещественных числах! Попоробуй сам!");
}


// Print endMessage when program ends
void endMessage() {
    puts("Пока!");
}



#endif // MESSAGES_H