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



bool     AreOptionsCorrect(int argc, char* argv[]);
bool     ProcessOption(option_t option);
option_t GetOption(const char* option);
void     PrintHelp();


#endif // CMD_LINE_ARGS_HANDLER_H