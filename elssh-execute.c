#include "elssh.h"

/**
 * @brief execute the command line tokens
 * @param tokens command line array pointer of tokens 
 * @return the status of the commands
*/
extern int elssh_execute(char **tokens){
    // if the command is empty, then return
    if(tokens[0] == NULL){
        return 1;
    }

    // check if the command is a built-in command
    if(strcmp(tokens[0], "exit") == 0 || strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "q") == 0){
        return 0;
    }

    // if the command is not a built-in command, then execute the command
    // TODO: fork a child process and execute the command
    return 1;
}
