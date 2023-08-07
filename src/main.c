#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/definitions.h"

int print_help(int status) {
    printf("usage: ./daemonize <bash command>\n\n");

    return status;
}

/**
 * @brief Executes a bash command as a background task (daemon)
 * @param argc Argument count
 * @param argv Argument vector
 * @return 0 on success, non-zero on failure
 */
int main(int argc, char** argv) {
    int status= 0;

    if (argc != 2) {
        printf("error: invalid syntax\n");
        return print_help(1);
    }

    status = daemon(1, 0);

    if (system(argv[1]) != 0) {
        return 1;
    }

    return status;
}