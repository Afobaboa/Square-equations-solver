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
 * Help user to solve
 * his square equations.
 */
void RunSolving();


/**
 * This functions breaks
 * my program and I don't
 * know how to delete if.
 */
void PrintDED();


/** 
 * Print all available 
 * options and instructions
 * for use.
 */
void PrintHelp();


#endif // CMD_LINE_ARGS_HANDLERS_H