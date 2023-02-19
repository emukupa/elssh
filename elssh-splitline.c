#include "elssh.h"

/**
 * @brief split the command line string into tokens
 * @param line_str command line string pointer
 * @return the array of tokens
*/
extern char **elssh_splitline(char *line_str){
    // to enable to increase the size of the buffer, we need to use a variable to store the buffer
    int bufsize = ELSSH_TOK_BUFSIZE;

    // allocate memory for the tokens
    char **tokens = malloc(bufsize * sizeof(char*));
    if(tokens == NULL){
        fprintf(stderr, "elssh error: unable to allocate memory for tokens");
        exit(EXIT_FAILURE);
    }

    int token_index = 0;
    size_t str_len = strlen(line_str);
    char *tracker = line_str;

    // loop through the string splitting it into tokens
    for(int i = 0; i < str_len; i++){
        // if the current character is a space, then we have reached the end of a token
        if(line_str[i] == ' '){
            // replace the space with a null terminator
            line_str[i] = '\0';

            // assign the index of command_args to the command_arg and increase the index
            tokens[token_index++] = tracker;

            // set the tracker to the next character
            // tracker = &line_str[i + 1];
            tracker = line_str + i + 1;
        } else if(i == str_len - 1){
            // if we are at the end of the string, then we have reached the end of a token
            tokens[token_index++] = tracker;
        }

        // if we have reached the end of the buffer, then we need to increase the size of the buffer
        if(token_index >= bufsize){
            bufsize += ELSSH_TOK_BUFSIZE;
            // reallocate memory for the tokens
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if(tokens == NULL){
                fprintf(stderr, "elssh error: unable to allocate more memory for tokens");
                exit(EXIT_FAILURE);
            }
        }
    }

    // add a null terminator to the end of the tokens
    tokens[token_index] = NULL;

    return tokens;
}