#ifndef ELSSH_H
#define ELSSH_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Clean up the environment
 * @return void
*/
extern void elssh_cleanup(); 

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
 * @brief trims the leading and trailing whitespace from a string
 * @param str the string to trim
 * @return the trimmed string
*/
extern char *trim(char *str);

#endif // ELSSH_H
