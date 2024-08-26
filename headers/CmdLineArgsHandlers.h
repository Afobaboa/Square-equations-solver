#ifndef CMD_LINE_ARGS_HANDLERS_H
#define CMD_LINE_ARGS_HANDLERS_H


/**
 * @file
 * This header used to process 
 * cmd line arguments of this 
 * program.
 */


/** 
 * This enum contain 
 * cmd line options.
 */
enum OPTIONS {
    HELP,           /**< If user don't know options. */
    RUN,            /**< If user want to solve equations. */
    TEST,           /**< If user want to test program. */
    DED,            /**< WTF I don't add this option. */
    WRONG_OPTION    /**< This option is for error handling. */
};
typedef enum OPTIONS option_t;


/**
 * Return next option from stdin.
 * Yout shoult process this option 
 * before getting next option.
 * 
 * @return Real option if it exists,
 * @return WRONG_OPTION if it doesn't 
 * exist.
 */
option_t GetOption(const char* option);


/**
 * Check if options format is OK.
 * Now the rules say you can't 
 * use more than 1 option.
 * 
 * You can change format rules 
 * in future.
 * 
 * @return true if rules 
 */
bool AreOptionsCorrect(int argc, char* argv[]);


#endif // CMD_LINE_ARGS_HANDLERS_H