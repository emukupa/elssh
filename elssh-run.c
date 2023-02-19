#include "elssh.h"

/**
 * @brief Run the shell
 * @return void
*/
extern void elssh_run(){
    int running = 1;
    // continuously run the shell until stopped
    while(running){
        // elssh prompt();
        printf("elssh> ");

        // read command line arguments
        char *line = elssh_readline();
        if(line == NULL){
            puts("Error reading line");
            continue;
        }

        // split the line into arguments or tokens
        char **args = elssh_splitline(line);
        if(args == NULL){
            puts("Error splitting line");
            continue;
        }

        // execute the commands
        int status = elssh_execute(args);
        if(status == 0){
            running = 0;
        }

        // free memory
        // free(line); // the trim messes up the memory address, let program exit to free memory
        free(args);
    }  
}
