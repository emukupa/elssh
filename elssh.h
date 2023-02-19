#ifndef ELSSH_H
#define ELSSH_H

#include <stdio.h>

/**
 * @brief Initialize the environment
 * @return void
*/
extern void elssh_init();

/**
 * @brief Run the shell
 * @return void
*/
extern void elssh_run();

/**
 * @brief Clean up the environment
 * @return void
*/
extern void elssh_cleanup();

#endif // ELSSH_H
