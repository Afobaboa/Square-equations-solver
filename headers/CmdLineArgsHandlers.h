#ifndef CMD_LINE_ARGS_HANDLER_H
#define CMD_LINE_ARGS_HANDLER_H


enum OPTIONS {
    HELP,
    RUN,
    TEST,
    DED,
    WRONG_OPTION
};
typedef enum OPTIONS option_t;



void RunSolving();
void PrintDED();
void PrintHelp();


#endif // CMD_LINE_ARGS_HANDLER_H