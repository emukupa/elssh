#include "elssh.h"

/**
 * @brief Read a line from stdin
 * @return char* the pointer to the line read
*/
extern char *elssh_readline(){
    char *line = NULL;
    size_t bufsize = 0;
    if(getline(&line, &bufsize, stdin) == -1){
        if(feof(stdin)){
            exit(EXIT_SUCCESS);
        }else{
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }
    
    return trim(line);
}
