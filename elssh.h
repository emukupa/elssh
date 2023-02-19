#ifndef ELSSH_H
#define ELSSH_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ELSSH_BUFSIZE 1024
#define ELSSH_TOK_BUFSIZE 32

/**
 * Function declerations for the ELSSH builtin functions
 * These functions are defined in elssh-builtin.c
*/
extern int elssh_cd(char **args);
extern int elssh_help(char **args);
extern int elssh_terminate();

/**
 * List of builtin commands
*/
extern char *elssh_builtin_str[];

/**
 * List of builtin functions corresponding to the builtin commands
*/
extern int (*elssh_builtin_func[]) (char **);

/**
 * @brief number of builtin commands
 * @param void
 * @return the number of builtin commands
*/
extern int elssh_num_of_builtin_funcs();

/**
 * @brief Clean up the environment
 * @return void
*/
extern void elssh_cleanup(); 

/**
 * @brief execute the command line tokens
 * @param tokens command line array pointer of tokens 
 * @return the status of the commands
*/
extern int elssh_execute(char **tokens);

/**
 * @brief Initialize the environment
 * @return void
*/
extern void elssh_init();

/**
 * @brief Read a line from stdin
 * @return char* the pointer to the line read
*/
extern char *elssh_readline();

/**
 * @brief Run the shell
 * @return void
*/
extern void elssh_run();

/**
 * @brief trims the leading whiteqspace from a string
 * @param str the string to left trim
 * @return the left trimmed string
*/
extern char *left_trim(char *str);

/**
 * @brief trims the trailing whitespace from a string
 * @param str the string to right trim
 * @return the right trimmed string
*/
extern char *right_trim(char *str);

/**
 * @brief split the command line string into tokens
 * @param line_str command line string pointer
 * @return the array of tokens
*/
extern char **elssh_splitline(char *line_str);

/**
 * @brief split the command line string into tokens
 * @param line_str command line string pointer
 * @return the array of tokens
*/
extern char **elssh_splitline(char *line_str);

/**
 * @brief trims the leading and trailing whitespace from a string
 * @param str the string to trim
 * @return the trimmed string
*/
extern char *trim(char *str);

#endif // ELSSH_H
