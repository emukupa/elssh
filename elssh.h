#ifndef ELSSH_H
#define ELSSH_H

#include <stdio.h>

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



#endif // ELSSH_H
