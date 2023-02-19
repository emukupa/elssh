#include "elssh.h"

int main(){
    // Initialize the environment
    elssh_init();

    // continuously run the shell until stopped
    elssh_run();

    // clean up the environment
    elssh_cleanup();

    return 0;
}
