#include "elssh.h"

/**
 * List of builtin commands
*/
char *elssh_builtin_str[] = {
    "cd",
    "exit",
    "help",
    "q",
    "quit",
};

/**
 * List of builtin functions corresponding to the builtin commands
*/
int (*elssh_builtin_func[]) (char **) = {
    &elssh_cd,
    &elssh_terminate,
    &elssh_help,
    &elssh_terminate,
    &elssh_terminate 
};

/**
 * @brief Function for changing the current working directory
 * @param args the array of arguments
 * @return int 1 as the status of the command
*/
extern int elssh_cd(char **args){
    // if the argument is empty, then print the current working directory
    if(args[1] == NULL){
        char cwd[ELSSH_BUFSIZE];
        getcwd(cwd, sizeof(cwd));
        printf("current working directory: \"%s\"\n", cwd);
        fprintf(stdout, "elssh error: expected argument to \"cd\" plus the folder name\n");
    }else{
        // change the current working directory
        if(chdir(args[1]) != 0){
            perror("elssh");
        }
    }
    return 1;
}

/**
 * @brief Function for printing help information
 * @param args the array of arguments
 * @return int 1 as the status of the command
*/
extern int elssh_help(char **args){
    if(args[0] == NULL){
        fprintf(stdout, "elssh error: expected argument to \"help\" plus the command name");
    }

    if(args[1] == NULL || !args[1]){
        puts("ELSSH help");
        puts("Type program names and arguments, and hit enter.");
        puts("The following are built in:");
        
        // print the list of builtin commands
        for(int i = 0; i < elssh_num_of_builtin_funcs(); i++){
            printf(" %d. %s\n", i, elssh_builtin_str[i]);
        }

        // You can use the system help 
        puts("Check the man page for information on other programs.");
    }else{
        // TODO: give more information for specific programs
        puts("Has specified command");
    }

    return 1;
}
/**
 * @brief number of builtin commands
 * @param void
 * @return the number of builtin commands
*/
extern int elssh_num_of_builtin_funcs(){
    return sizeof(elssh_builtin_str) / sizeof(char *);
}

/**
 * @brief terminates the shell
 * @param void 
 * @return int 0 as the status of the termination
*/
extern int elssh_terminate(){
   return 0;
}
