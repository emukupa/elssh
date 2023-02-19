#include "elssh.h"

/**
 * @brief trims the leading whiteqspace from a string
 * @param str the string to left trim
 * @return the left trimmed string
*/
extern char *left_trim(char *str){
    while(isspace((unsigned char)*str)) str++;
    return str;
}

/**
 * @brief trims the trailing whitespace from a string
 * @param str the string to right trim
 * @return the right trimmed string
*/
extern char *right_trim(char *str){
    // TODO: verify that this works
    /**
    char *end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    // write new null terminator
    end[1] = '\0';
    */
    char *back = str + strlen(str);
    while(isspace(*--back));
    *(back+1) = '\0';
    return str;
}

/**
 * @brief trims the leading and trailing whitespace from a string
 * @param str the string to trim
 * @return the trimmed string
*/
extern char *trim(char *str){
    return right_trim(left_trim(str));
}
