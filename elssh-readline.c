#include "elssh.h"


/**
 * @brief Read a line from stdin
 * @return char* the pointer to the line read
*/
extern char *elssh_readline(){
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}